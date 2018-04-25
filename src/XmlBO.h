#pragma once
#include "ParserInterfejs.h"
#include "Types\TypyProste.h"
#include "WyjatekParser.h"
#include <exception>
#include <string>
#include <algorithm>

#define ZMIANA_NAPIS_BLAD_WEZLA "B³ad odczytu elementu-dziecka o nazwie "
#define ZMIANA_NAPIS_BLAD_ATRYBUTU "B³ad odczytu atrybutu o nazwie "
#define ZMIANA_NAPIS_Z_WEZLA " z wezla: "

/**
* \brief Klasa zawieraj¹ce operacje biznesowe.
*
* Klasa zawiera metody pomagaj¹ce wykonuj¹ce operacje biznesowe, u³atwiaj¹ce koszystanie z parsera Xml.
* \author Daniel Wojdak
* \version 1
* \date 18-06-2014
*/
class XmlBO{

public:
	typedef std::shared_ptr<SPar::ParserElement> ElementWezla; /// Typ wskaŸnika na wêze³.
	typedef std::shared_ptr<SPar::ParserAtrybut> AtrybutElementu; /// Typ wskaŸnika na atrybut wêz³a.
	typedef std::function< bool(ElementWezla) > OperacjaWezla; /// Typ funkcyjny przyjmuj¹cy jako parametr wskaŸnik na wêze³.
	typedef std::function< bool(AtrybutElementu) > OperacjaAtrybutu; /// Typ funkcyjny przyjmuj¹cy jako parametr wskaŸnik na atrybut.

private:
	/**
	* \brief Metoda trymuj¹ca ci¹g znaków.
	*
	* Metoda usuwa spacje z podanego ci¹gu znaków.
	* \param[inout] s - Napis, w którym maj¹ zostaæ usuniête spacje. 
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template < typename T > 
	static void trim( std::string &s ){
		s.erase(std::remove_if(s.begin(), s.end(), isSpace), s.end());
	}

	/**
	* \brief Metoda trymuj¹ca ci¹g znaków.
	*
	* Metoda pomija usuwanie spacji w ci¹gach znaków typu STyp::SPG::Tekst.
	* \param[inout] s - nieu¿ywany parametr.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template < > 
	static void trim<STyp::SPG::Tekst>( std::string &s ){
	}

	/**
	* \brief Metoda zamieniaj¹ca znak dziesiêtny.
	*
	* Metoda zamienia znaki "," i "." na aktualny znak punktu oddzielaj¹cego liczbê u³amkow¹ zdefiniowany w lokalnych ustawieniach systemu.
	* \param[inout] s - Napis, w którym maj¹ zostaæ zamienione znaki dziesiêtne.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static void decimal_point(std::string &s){
		std::replace_if(s.begin(),s.end(),[](char c){ return c==',' || c=='.'; },std::use_facet<std::numpunct<char>>(std::locale()).decimal_point());
	}

	/**
	* \brief Metoda sprawdzaj¹ca czy podany znak jest znakiem bia³ym.
	*
	* Metoda sprawdza czy podany w parametrze znak jest znakiem bia³ym.
	* \param[in] c - znak do sprawdzenia.
	* \return Metoda zwraca wartoœæ true, je¿eli podany snak jest bia³ym znakiem. W przeciwnym wypadku zwrócona zostaje wartoœæ false.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static bool isSpace( unsigned char c ){
		return isspace(c)!=0;
	}
	
	/**
	* \brief Metoda ogólna do konwersji napisu na typ podstawowy.
	*
	* Metoda konwertuje napis na typ podstawowy.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do którego zapisywane s¹ skonwertowane dane.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template < typename T > 
	static void Zaladuj(const std::string& atrybut, STyp::PodstawowyInterfejs<T>& obiekt){
		obiekt(atrybut);
	}

	/**
	* \brief Metoda szczegó³owa do konwersji napisu na typ double.
	*
	* Metoda konwertuje napis na typ double.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do którego zapisywane s¹ skonwertowane dane.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template <  > 
	static void Zaladuj<double>(const std::string& atrybut, STyp::PodstawowyInterfejs<double>& obiekt){
		double tmp;
		std::string kopia = atrybut;
		decimal_point(kopia);
		tmp = stod(kopia);
		obiekt(tmp);
	}

	/**
	* \brief Metoda szczegó³owa do konwersji napisu na typ long double.
	*
	* Metoda konwertuje napis na typ long double.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do którego zapisywane s¹ skonwertowane dane.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template <  > 
	static void Zaladuj<long double>(const std::string& atrybut, STyp::PodstawowyInterfejs<long double>& obiekt){
		long double tmp;
		std::string kopia = atrybut;
		decimal_point(kopia);
		tmp = stold(kopia);
		obiekt(tmp);
	}

	/**
	* \brief Metoda szczegó³owa do konwersji napisu na typ int.
	*
	* Metoda konwertuje napis na typ int.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do którego zapisywane s¹ skonwertowane dane.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template <  > 
	static void Zaladuj<int>(const std::string& atrybut, STyp::PodstawowyInterfejs<int>& obiekt){
		int tmp;
		tmp = stoul(atrybut,nullptr,0);
		obiekt(tmp);
	}
	
	/**
	* \brief Metoda szczegó³owa do konwersji napisu na typ unsigned int.
	*
	* Metoda konwertuje napis na typ unsigned int.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do którego zapisywane s¹ skonwertowane dane.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template <  > 
	static void Zaladuj<unsigned int>(const std::string& atrybut, STyp::PodstawowyInterfejs<unsigned int>& obiekt){
		unsigned int tmp;
		tmp = stoul(atrybut);
		obiekt(tmp);
	}

	/**
	* \brief Metoda szczegó³owa do konwersji napisu na typ float.
	*
	* Metoda konwertuje napis na typ float.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do którego zapisywane s¹ skonwertowane dane.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template <  > 
	static void Zaladuj<float>(const std::string& atrybut, STyp::PodstawowyInterfejs<float>& obiekt){
		float tmp;
		std::string kopia = atrybut;
		decimal_point(kopia);
		tmp = stof(kopia);
		obiekt(tmp);
	}
	
public:

	/**
	* \brief Metoda ogólna wykonuj¹ca operacje dla ka¿dego wlementu.
	*
	* Metoda wywo³uje dla ka¿dego elementu wêz³a, o nazwie podanej przez parametr nazwa, funkcjê przekazan¹ w parametrze.
	* \par Sposoby opuszczenia pêtli
	* Standardowa pêtla udostêpnia takie s³owa kluczowe jak break lub continue. Z racji sposobu implementacji u¿ywanie ich nie jest mo¿liwe.
	* Zosta³y one zast¹pione przez wartoœæ zwracan¹ przez funkcjê. Je¿eli funkcja zwróci wartoœæ false wykonywanie pêtli bêdzie przerwane 
	* i metoda zwróci wartoœæ false. Je¿eli funkcja zwróci wartoœæ true, wykonywanie pêtli bêdzie kontynuowane.
	* \param[in] wezel - Wêze³-Rodzic elementów, które maj¹ zostaæ przetworzone.
	* \param[in] nazwa - Nazwa elemetów, które maj¹ zostaæ przetworzone. Je¿eli napis jest pusty, przetwarzane s¹ wszytkie wêz³y.
	* \param[in] funkcja - Funkcja wykonuj¹ce operacje na wêŸle.
	* \return Metoda zwraca wartoœæ true, je¿eli pêtla przejdzie po wszystkich elementach bez przerwy. Zwraca wartoœæ false w przypadku przerwania pêtli przez funkcjê lub je¿eli u¿yto klasy zwracaj¹cej false, w przypadku wykrycia b³êdnego wêz³a rodzica.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<class T>
	static bool ForEach(ElementWezla wezel, const std::string& nazwa, OperacjaWezla& funkcja){
		if (wezel == nullptr)
			return T::bladWezla(wezel, nazwa) != nullptr;
		const char * cNazwa = nazwa.empty() ? nullptr : nazwa.c_str();
		for (ElementWezla element = wezel->pobierzElement(cNazwa); element != nullptr; element = element->pobierzNastepnyElement(cNazwa)){
			if(!funkcja(element))
				return false;
		}
		return true;
	}

	/**
	* \brief Metoda ogólna wykonuj¹ca operacje dla ka¿dego wlementu.
	*
	* Metoda wywo³uje dla ka¿dego atrybutu wêz³a, funkcjê przekazan¹ w parametrze.
	* \par Sposoby opuszczenia pêtli
	* Standardowa pêtla udostêpnia takie s³owa kluczowe jak break lub continue. Z racji sposobu implementacji u¿ywanie ich nie jest mo¿liwe.
	* Zosta³y one zast¹pione przez wartoœæ zwracan¹ przez funkcjê. Je¿eli funkcja zwróci wartoœæ false wykonywanie pêtli bêdzie przerwane
	* i metoda zwróci wartoœæ false. Je¿eli funkcja zwróci wartoœæ true, wykonywanie pêtli bêdzie kontynuowane.
	* \param[in] wezel - Wêze³, którego atrybuty maj¹ zostaæ przetworzone.
	* \param[in] funkcja - Funkcja wykonuj¹ce operacje na atrybutach.
	* \return Metoda zwraca wartoœæ true, je¿eli pêtla przejdzie po wszystkich elementach bez przerwy. Zwraca wartoœæ false w przypadku przerwania pêtli przez funkcjê lub je¿eli u¿yto klasy zwracaj¹cej false, w przypadku wykrycia b³êdnego wêz³a rodzica.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<class T>
	static bool ForEach(ElementWezla wezel, OperacjaAtrybutu& funkcja){
		if (wezel == nullptr)
			return T::bladWezla(wezel, "") != nullptr;
		for (AtrybutElementu element = wezel->pobierzAtrybut(nullptr); element != nullptr; element = element->pobierzNastepnyAtrybut()){
			if (!funkcja(element))
				return false;
		}
		return true;
	}

	/**
	* \brief Metoda ogólna wykonuj¹ca operacje dla ka¿dego wlementu.
	*
	* Metoda wywo³uje dla ka¿dego elementu wêz³a, funkcjê przekazan¹ w parametrze.
	* \par Sposoby opuszczenia pêtli
	* Standardowa pêtla udostêpnia takie s³owa kluczowe jak break lub continue. Z racji sposobu implementacji u¿ywanie ich nie jest mo¿liwe.
	* Zosta³y one zast¹pione przez wartoœæ zwracan¹ przez funkcjê. Je¿eli funkcja zwróci wartoœæ false wykonywanie pêtli bêdzie przerwane
	* i metoda zwróci wartoœæ false. Je¿eli funkcja zwróci wartoœæ true, wykonywanie pêtli bêdzie kontynuowane.
	* \param[in] wezel - Wêze³-Rodzic elementów, które maj¹ zostaæ przetworzone.
	* \param[in] funkcja - Funkcja wykonuj¹ce operacje na wêŸle.
	* \return Metoda zwraca wartoœæ true, je¿eli pêtla przejdzie po wszystkich elementach bez przerwy. Zwraca wartoœæ false w przypadku przerwania pêtli przez funkcjê lub je¿eli u¿yto klasy zwracaj¹cej false, w przypadku wykrycia b³êdnego wêz³a rodzica.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<class T>
	static bool ForEach(ElementWezla wezel, OperacjaWezla& funkcja){
		return ForEach<T>(wezel,std::string(),funkcja);
	}

	/**
	* \brief Metoda wyszukuj¹ca w wêŸle element o podanej nazwie. 
	*
	* Metoda przeszukuje wêze³ i zwraca pierwszy napotkany o podanej nazwie. Do poprawnego wyszukiwania jeden z wêz³ów musi byæ poprawny.
	* \param[in] wezel - Wêze³-Rodzic, w którym maj¹ byæ szukane elementy.
	* \param[in] nazwa - Nazwa szukanego wêz³a.
	* \param[in] poprzedniWezel - Wêze³, za którym maj¹ byæ szukane elementy.
	* \return
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<class T>
	static ElementWezla ZnajdzWezel(ElementWezla wezel, const std::string& nazwa, ElementWezla poprzedniWezel = nullptr){
		if ((wezel == nullptr && poprzedniWezel == nullptr) || nazwa.empty())
			return T::bladWezla(poprzedniWezel ? poprzedniWezel : wezel, nazwa);
		ElementWezla element;
		if(poprzedniWezel)
			element = poprzedniWezel->pobierzNastepnyElement(nazwa.c_str());
		else
			element = wezel->pobierzElement(nazwa.c_str());
		if (element == nullptr)
			return T::bladWezla(poprzedniWezel ? poprzedniWezel : wezel, nazwa);
		return element;
	}
	
	/**
	* \brief Metoda wyszukuj¹ca w wêŸle element o podanej nazwie.
	*
	* Metoda przeszukuje wêze³ i zwraca pierwszy napotkany o podanej nazwie oraz spe³niaj¹cy warunek atrybutu o podanej nazwie i wartoœci. Do poprawnego wyszukiwania jeden z wêz³ów musi byæ poprawny.
	* \param[in] wezel - Wêze³-Rodzic, w którym maj¹ byæ szukane elementy.
	* \param[in] nazwaWezla - Nazwa szukanego wêz³a.
	* \param[in] nazwaAtrybutu - Nazwa atrybutu.
	* \param[in] wartoscAtrybutu - Wartoœæ artybutu.
	* \param[in] poprzedniWezel - Wêze³, za którym maj¹ byæ szukane elementy.
	* \return
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<class T>
	static ElementWezla ZnajdzWezelJezeli(ElementWezla wezel,
		const std::string& nazwaWezla,
		const std::string& nazwaAtrybutu,
		const std::string& wartoscAtrybutu,
		ElementWezla poprzedniWezel = nullptr)
	{
		if ((wezel == nullptr && poprzedniWezel == nullptr) || nazwaWezla.empty() || nazwaAtrybutu.empty())
			return T::bladWezla(poprzedniWezel ? poprzedniWezel : wezel, nazwaWezla);
		ElementWezla element;
		for (
			auto wezelDziecko = poprzedniWezel ? poprzedniWezel->pobierzNastepnyElement(nazwaWezla.c_str()) : wezel->pobierzElement(nazwaWezla.c_str());
			wezelDziecko != nullptr;
		wezelDziecko = wezelDziecko->pobierzNastepnyElement(nazwaWezla.c_str())
			){
			auto tmp = wezelDziecko->pobierzAtrybut(nazwaAtrybutu.c_str());
			if (tmp && !strcmp(wartoscAtrybutu.c_str(), tmp->pobierzWartosc())){
				element = wezelDziecko;
				break;
			}
		}
		if (element == nullptr)
			return T::bladWezla(poprzedniWezel ? poprzedniWezel : wezel, nazwaWezla);
		return element;
	}
	
	/**
	* \brief Metoda wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a. Dane przekazywane s¹ do obiektu przekazanego przez parametr.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[out] obiekt - Obiekt, do którego maja zostaæ wczytane dane.
	* \return Metoda zwraca wartoœæ true, je¿eli uda siê wczytaæ dane do obiektu. Zwraca wartoœæ false w przeciwnym wypadku, pod warunkiem u¿ucia klasy zwracaj¹cej wartoœæ false przy wywo³aniu metody b³¹d atrybutu.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<class K, typename T>
	static bool WczytajAtrybut(ElementWezla wezel, const std::string& nazwa, STyp::PodstawowyInterfejs<T>& obiekt){
		if(!wezel)
			return K::bladAtrybutu(wezel, nazwa);
		auto napis = wezel->pobierzAtrybut(nazwa.c_str());
		if(!napis)
			return K::bladAtrybutu(wezel, nazwa);
		std::string atrybut(napis->pobierzWartosc());
		trim<T>(atrybut);
		if(!atrybut.empty()){
			Zaladuj<T>(atrybut,obiekt);
			return true;
		}
		return K::bladAtrybutu(wezel, nazwa);
	}
	
	/**
	* \brief Metoda ogólna wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domyœlna wartoœæ zwrócowa w przypadku b³êdu.
	* \return Wczytana wartoœæ lub domyœlna w przypadku wyst¹pienia b³êdu.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<typename T>
	static T WczytajAtrybut(ElementWezla wezel, const std::string& nazwa, T domyslnaWartosc){
		if(!wezel)
			return domyslnaWartosc;
		auto ptr = wezel->pobierzAtrybut(nazwa.c_str());
		if(!ptr)
			return domyslnaWartosc;
		return std::move(std::string(ptr->pobierzWartosc()));
	}

	/**
	* \brief Metoda wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domyœlna wartoœæ zwrócowa w przypadku b³êdu.
	* \return Wczytana wartoœæ lub domyœlna w przypadku wyst¹pienia b³êdu.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template< >
	static int WczytajAtrybut<int>(ElementWezla wezel, const std::string& nazwa, int domyslnaWartosc){
		if(!wezel)
			return domyslnaWartosc;
		auto ptr = wezel->pobierzAtrybut(nazwa.c_str());
		if(!ptr)
			return domyslnaWartosc;
		const std::string napis(ptr->pobierzWartosc());
		if(!napis.empty()){
			return stoul(napis,nullptr,0);
		}
		return domyslnaWartosc;
	}

	/**
	* \brief Metoda wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domyœlna wartoœæ zwrócowa w przypadku b³êdu.
	* \return Wczytana wartoœæ lub domyœlna w przypadku wyst¹pienia b³êdu.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template< >
	static unsigned int WczytajAtrybut<unsigned int>(ElementWezla wezel, const std::string& nazwa, unsigned int domyslnaWartosc){
		if(!wezel)
			return domyslnaWartosc;
		auto ptr = wezel->pobierzAtrybut(nazwa.c_str());
		if(!ptr)
			return domyslnaWartosc;
		const std::string napis(ptr->pobierzWartosc());
		if (!napis.empty()){
			return stoul(napis,nullptr,0);
		}
		return domyslnaWartosc;
	}

	/**
	* \brief Metoda wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domyœlna wartoœæ zwrócowa w przypadku b³êdu.
	* \return Wczytana wartoœæ lub domyœlna w przypadku wyst¹pienia b³êdu.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template< >
	static char WczytajAtrybut<char>(ElementWezla wezel, const std::string& nazwa, char domyslnaWartosc){
		if (!wezel)
			return domyslnaWartosc;
		auto ptr = wezel->pobierzAtrybut(nazwa.c_str());
		if (!ptr)
			return domyslnaWartosc;
		const std::string napis(ptr->pobierzWartosc());
		if (!napis.empty()){
			return static_cast<char>(stoul(napis, nullptr, 0));
		}
		return domyslnaWartosc;
	}

	/**
	* \brief Metoda wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domyœlna wartoœæ zwrócowa w przypadku b³êdu.
	* \return Wczytana wartoœæ lub domyœlna w przypadku wyst¹pienia b³êdu.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template< >
	static unsigned char WczytajAtrybut<unsigned char>(ElementWezla wezel, const std::string& nazwa, unsigned char domyslnaWartosc){
		if (!wezel)
			return domyslnaWartosc;
		auto ptr = wezel->pobierzAtrybut(nazwa.c_str());
		if (!ptr)
			return domyslnaWartosc;
		const std::string napis(ptr->pobierzWartosc());
		if (!napis.empty()){
			return static_cast<unsigned char>(stoul(napis, nullptr, 0));
		}
		return domyslnaWartosc;
	}

	/**
	* \brief Metoda wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domyœlna wartoœæ zwrócowa w przypadku b³êdu.
	* \return Wczytana wartoœæ lub domyœlna w przypadku wyst¹pienia b³êdu.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template< >
	static long double WczytajAtrybut<long double>(ElementWezla wezel, const std::string& nazwa, long double domyslnaWartosc){
		if(!wezel)
			return domyslnaWartosc;
		auto ptr = wezel->pobierzAtrybut(nazwa.c_str());
		if(!ptr)
			return domyslnaWartosc;
		const std::string napis(ptr->pobierzWartosc());
		if (!napis.empty()){
			std::string kopia = napis;
			decimal_point(kopia);
			return stold(kopia);
		}
		return domyslnaWartosc;
	}

	/**
	* \brief Metoda wczytuj¹ca dane z atrybutu wez³a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego wêz³a.
	* \param[in] wezel - Wêze³, w którego bêdize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domyœlna wartoœæ zwrócowa w przypadku b³êdu.
	* \return Wczytana wartoœæ lub domyœlna w przypadku wyst¹pienia b³êdu.
	* \author Daniel Wojdak
	* \version 1
	* \date 25-03-2016
	*/
	template< >
	static bool WczytajAtrybut<bool>(ElementWezla wezel, const std::string& nazwa, bool domyslnaWartosc) {
		if (!wezel)
			return domyslnaWartosc;
		auto ptr = wezel->pobierzAtrybut(nazwa.c_str());
		if (!ptr)
			return domyslnaWartosc;
		bool ret = domyslnaWartosc;
		if (ptr->pobierzWartoscBool(ret)) {
			return ret;
		}
		return domyslnaWartosc;
	}
};

/**
* \brief Klasa definiuj¹ca cechy reakcji na b³êdy.
*
* Klasa zawiera metody o specyficznym zachowaniu w przypadku wykrycia b³êdu podczas korzystania z metod klasy XmlBO.
* Metody generuj¹ wyj¹tki, zawieraj¹ce opis wez³a i/lub atrybutu.
* \author Daniel Wojdak
* \version 1
* \date 18-06-2014
*/
class THROW {
public:
	/**
	* \brief Metoda generuj¹ca wyj¹tek.
	*
	* Metoda generuje wyj¹tek jako reakcje na b³¹d.
	* \param[in] element - Wêze³.
	* \param[in] nazwaWezla - Nazwa wêz³a.
	* \param[in] stos - Œlad stosu.
	* \return ¯adna wartoœæ nie jest zwracana.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static XmlBO::ElementWezla bladWezla(XmlBO::ElementWezla element, const std::string& nazwaWezla, const STyp::Tekst& debug = STyp::Tekst()){
		throw SPar::WyjatekParser(EXCEPTION_PLACE, debug, element.get(), std::string(ZMIANA_NAPIS_BLAD_WEZLA + nazwaWezla + ZMIANA_NAPIS_Z_WEZLA));
	}

	/**
	* \brief Metoda generuj¹ca wyj¹tek.
	*
	* Metoda generuje wyj¹tek jako reakcje na b³¹d.
	* \param[in] element - Wêze³.
	* \param[in] nazwaAtrybutu - Nazwa atrybutu.
	* \param[in] stos - Œlad stosu.
	* \return ¯adna wartoœæ nie jest zwracana.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static bool bladAtrybutu(XmlBO::ElementWezla element, const std::string& nazwaAtrybutu, const STyp::Tekst& debug = STyp::Tekst()){
		throw SPar::WyjatekParser(EXCEPTION_PLACE, debug, element.get(), std::string(ZMIANA_NAPIS_BLAD_ATRYBUTU + nazwaAtrybutu + ZMIANA_NAPIS_Z_WEZLA));
	}

};

/**
* \brief Klasa definiuj¹ca cechy reakcji na b³êdy.
*
* Klasa zawiera metody o specyficznym zachowaniu w przypadku wykrycia b³êdu podczas korzystania z metod klasy XmlBO.
* Metody zwracaj¹ wartoœci informuj¹ce o b³êdzie podczas obs³ugi b³êdu.
* \author Daniel Wojdak
* \version 1
* \date 18-06-2014
*/
class NOTHROW {
public:

	/**
	* \brief Metoda zwracaj¹ca wartoœæ
	*
	* Metoda zwraca wartoœæ nullptr jako reakcje na b³¹d.
	* \param[in] element - nieu¿ywany parametr.
	* \param[in] nazwaWezla - nieu¿ywany parametr.
	* \return Metoda zwraca nullptr.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static XmlBO::ElementWezla bladWezla(XmlBO::ElementWezla element, const std::string& nazwaWezla){
		return nullptr;
	}

	/**
	* \brief Metoda zwracaj¹ca wartoœæ
	*
	* Metoda zwraca wartoœæ false jako reakcje na b³¹d.
	* \param[in] element - nieu¿ywany parametr.
	* \param[in] nazwaAtrybutu - nieu¿ywany parametr.
	* \return Metoda zwraca false.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static bool bladAtrybutu(XmlBO::ElementWezla element, const std::string& nazwaAtrybutu){
		return false;
	}
};

namespace SPar{
	/**
	* \brief Klasa zawieraj¹ca funkcje pomocnicze.
	*
	* Klasa zawiera metody pomocnicze.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	class PARSER_API ParserUtils
	{
	public:
		/**
		* \brief Metoda generuj¹ca wyj¹tek.
		*
		* Metoda generuje wyj¹tek typu WyjatekParser.
		* \param[in] wezel - Wêze³.
		* \param[in] stos - Œlad stosu.
		* \author Daniel Wojdak
		* \version 1
		* \date 18-06-2014
		*/
		static void generujWyjatekBleduStruktury(XmlBO::ElementWezla wezel, const STyp::Tekst& debug = STyp::Tekst());
	};
}