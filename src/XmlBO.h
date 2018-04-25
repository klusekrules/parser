#pragma once
#include "ParserInterfejs.h"
#include "Types\TypyProste.h"
#include "WyjatekParser.h"
#include <exception>
#include <string>
#include <algorithm>

#define ZMIANA_NAPIS_BLAD_WEZLA "B�ad odczytu elementu-dziecka o nazwie "
#define ZMIANA_NAPIS_BLAD_ATRYBUTU "B�ad odczytu atrybutu o nazwie "
#define ZMIANA_NAPIS_Z_WEZLA " z wezla: "

/**
* \brief Klasa zawieraj�ce operacje biznesowe.
*
* Klasa zawiera metody pomagaj�ce wykonuj�ce operacje biznesowe, u�atwiaj�ce koszystanie z parsera Xml.
* \author Daniel Wojdak
* \version 1
* \date 18-06-2014
*/
class XmlBO{

public:
	typedef std::shared_ptr<SPar::ParserElement> ElementWezla; /// Typ wska�nika na w�ze�.
	typedef std::shared_ptr<SPar::ParserAtrybut> AtrybutElementu; /// Typ wska�nika na atrybut w�z�a.
	typedef std::function< bool(ElementWezla) > OperacjaWezla; /// Typ funkcyjny przyjmuj�cy jako parametr wska�nik na w�ze�.
	typedef std::function< bool(AtrybutElementu) > OperacjaAtrybutu; /// Typ funkcyjny przyjmuj�cy jako parametr wska�nik na atrybut.

private:
	/**
	* \brief Metoda trymuj�ca ci�g znak�w.
	*
	* Metoda usuwa spacje z podanego ci�gu znak�w.
	* \param[inout] s - Napis, w kt�rym maj� zosta� usuni�te spacje. 
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template < typename T > 
	static void trim( std::string &s ){
		s.erase(std::remove_if(s.begin(), s.end(), isSpace), s.end());
	}

	/**
	* \brief Metoda trymuj�ca ci�g znak�w.
	*
	* Metoda pomija usuwanie spacji w ci�gach znak�w typu STyp::SPG::Tekst.
	* \param[inout] s - nieu�ywany parametr.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template < > 
	static void trim<STyp::SPG::Tekst>( std::string &s ){
	}

	/**
	* \brief Metoda zamieniaj�ca znak dziesi�tny.
	*
	* Metoda zamienia znaki "," i "." na aktualny znak punktu oddzielaj�cego liczb� u�amkow� zdefiniowany w lokalnych ustawieniach systemu.
	* \param[inout] s - Napis, w kt�rym maj� zosta� zamienione znaki dziesi�tne.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static void decimal_point(std::string &s){
		std::replace_if(s.begin(),s.end(),[](char c){ return c==',' || c=='.'; },std::use_facet<std::numpunct<char>>(std::locale()).decimal_point());
	}

	/**
	* \brief Metoda sprawdzaj�ca czy podany znak jest znakiem bia�ym.
	*
	* Metoda sprawdza czy podany w parametrze znak jest znakiem bia�ym.
	* \param[in] c - znak do sprawdzenia.
	* \return Metoda zwraca warto�� true, je�eli podany snak jest bia�ym znakiem. W przeciwnym wypadku zwr�cona zostaje warto�� false.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static bool isSpace( unsigned char c ){
		return isspace(c)!=0;
	}
	
	/**
	* \brief Metoda og�lna do konwersji napisu na typ podstawowy.
	*
	* Metoda konwertuje napis na typ podstawowy.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do kt�rego zapisywane s� skonwertowane dane.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template < typename T > 
	static void Zaladuj(const std::string& atrybut, STyp::PodstawowyInterfejs<T>& obiekt){
		obiekt(atrybut);
	}

	/**
	* \brief Metoda szczeg�owa do konwersji napisu na typ double.
	*
	* Metoda konwertuje napis na typ double.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do kt�rego zapisywane s� skonwertowane dane.
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
	* \brief Metoda szczeg�owa do konwersji napisu na typ long double.
	*
	* Metoda konwertuje napis na typ long double.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do kt�rego zapisywane s� skonwertowane dane.
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
	* \brief Metoda szczeg�owa do konwersji napisu na typ int.
	*
	* Metoda konwertuje napis na typ int.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do kt�rego zapisywane s� skonwertowane dane.
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
	* \brief Metoda szczeg�owa do konwersji napisu na typ unsigned int.
	*
	* Metoda konwertuje napis na typ unsigned int.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do kt�rego zapisywane s� skonwertowane dane.
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
	* \brief Metoda szczeg�owa do konwersji napisu na typ float.
	*
	* Metoda konwertuje napis na typ float.
	* \param[in] atrybut - Napis przeznaczony do konwersji.
	* \param[out] obiekt - Obiekt, do kt�rego zapisywane s� skonwertowane dane.
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
	* \brief Metoda og�lna wykonuj�ca operacje dla ka�dego wlementu.
	*
	* Metoda wywo�uje dla ka�dego elementu w�z�a, o nazwie podanej przez parametr nazwa, funkcj� przekazan� w parametrze.
	* \par Sposoby opuszczenia p�tli
	* Standardowa p�tla udost�pnia takie s�owa kluczowe jak break lub continue. Z racji sposobu implementacji u�ywanie ich nie jest mo�liwe.
	* Zosta�y one zast�pione przez warto�� zwracan� przez funkcj�. Je�eli funkcja zwr�ci warto�� false wykonywanie p�tli b�dzie przerwane 
	* i metoda zwr�ci warto�� false. Je�eli funkcja zwr�ci warto�� true, wykonywanie p�tli b�dzie kontynuowane.
	* \param[in] wezel - W�ze�-Rodzic element�w, kt�re maj� zosta� przetworzone.
	* \param[in] nazwa - Nazwa elemet�w, kt�re maj� zosta� przetworzone. Je�eli napis jest pusty, przetwarzane s� wszytkie w�z�y.
	* \param[in] funkcja - Funkcja wykonuj�ce operacje na w�le.
	* \return Metoda zwraca warto�� true, je�eli p�tla przejdzie po wszystkich elementach bez przerwy. Zwraca warto�� false w przypadku przerwania p�tli przez funkcj� lub je�eli u�yto klasy zwracaj�cej false, w przypadku wykrycia b��dnego w�z�a rodzica.
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
	* \brief Metoda og�lna wykonuj�ca operacje dla ka�dego wlementu.
	*
	* Metoda wywo�uje dla ka�dego atrybutu w�z�a, funkcj� przekazan� w parametrze.
	* \par Sposoby opuszczenia p�tli
	* Standardowa p�tla udost�pnia takie s�owa kluczowe jak break lub continue. Z racji sposobu implementacji u�ywanie ich nie jest mo�liwe.
	* Zosta�y one zast�pione przez warto�� zwracan� przez funkcj�. Je�eli funkcja zwr�ci warto�� false wykonywanie p�tli b�dzie przerwane
	* i metoda zwr�ci warto�� false. Je�eli funkcja zwr�ci warto�� true, wykonywanie p�tli b�dzie kontynuowane.
	* \param[in] wezel - W�ze�, kt�rego atrybuty maj� zosta� przetworzone.
	* \param[in] funkcja - Funkcja wykonuj�ce operacje na atrybutach.
	* \return Metoda zwraca warto�� true, je�eli p�tla przejdzie po wszystkich elementach bez przerwy. Zwraca warto�� false w przypadku przerwania p�tli przez funkcj� lub je�eli u�yto klasy zwracaj�cej false, w przypadku wykrycia b��dnego w�z�a rodzica.
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
	* \brief Metoda og�lna wykonuj�ca operacje dla ka�dego wlementu.
	*
	* Metoda wywo�uje dla ka�dego elementu w�z�a, funkcj� przekazan� w parametrze.
	* \par Sposoby opuszczenia p�tli
	* Standardowa p�tla udost�pnia takie s�owa kluczowe jak break lub continue. Z racji sposobu implementacji u�ywanie ich nie jest mo�liwe.
	* Zosta�y one zast�pione przez warto�� zwracan� przez funkcj�. Je�eli funkcja zwr�ci warto�� false wykonywanie p�tli b�dzie przerwane
	* i metoda zwr�ci warto�� false. Je�eli funkcja zwr�ci warto�� true, wykonywanie p�tli b�dzie kontynuowane.
	* \param[in] wezel - W�ze�-Rodzic element�w, kt�re maj� zosta� przetworzone.
	* \param[in] funkcja - Funkcja wykonuj�ce operacje na w�le.
	* \return Metoda zwraca warto�� true, je�eli p�tla przejdzie po wszystkich elementach bez przerwy. Zwraca warto�� false w przypadku przerwania p�tli przez funkcj� lub je�eli u�yto klasy zwracaj�cej false, w przypadku wykrycia b��dnego w�z�a rodzica.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	template<class T>
	static bool ForEach(ElementWezla wezel, OperacjaWezla& funkcja){
		return ForEach<T>(wezel,std::string(),funkcja);
	}

	/**
	* \brief Metoda wyszukuj�ca w w�le element o podanej nazwie. 
	*
	* Metoda przeszukuje w�ze� i zwraca pierwszy napotkany o podanej nazwie. Do poprawnego wyszukiwania jeden z w�z��w musi by� poprawny.
	* \param[in] wezel - W�ze�-Rodzic, w kt�rym maj� by� szukane elementy.
	* \param[in] nazwa - Nazwa szukanego w�z�a.
	* \param[in] poprzedniWezel - W�ze�, za kt�rym maj� by� szukane elementy.
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
	* \brief Metoda wyszukuj�ca w w�le element o podanej nazwie.
	*
	* Metoda przeszukuje w�ze� i zwraca pierwszy napotkany o podanej nazwie oraz spe�niaj�cy warunek atrybutu o podanej nazwie i warto�ci. Do poprawnego wyszukiwania jeden z w�z��w musi by� poprawny.
	* \param[in] wezel - W�ze�-Rodzic, w kt�rym maj� by� szukane elementy.
	* \param[in] nazwaWezla - Nazwa szukanego w�z�a.
	* \param[in] nazwaAtrybutu - Nazwa atrybutu.
	* \param[in] wartoscAtrybutu - Warto�� artybutu.
	* \param[in] poprzedniWezel - W�ze�, za kt�rym maj� by� szukane elementy.
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
	* \brief Metoda wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a. Dane przekazywane s� do obiektu przekazanego przez parametr.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[out] obiekt - Obiekt, do kt�rego maja zosta� wczytane dane.
	* \return Metoda zwraca warto�� true, je�eli uda si� wczyta� dane do obiektu. Zwraca warto�� false w przeciwnym wypadku, pod warunkiem u�ucia klasy zwracaj�cej warto�� false przy wywo�aniu metody b��d atrybutu.
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
	* \brief Metoda og�lna wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domy�lna warto�� zwr�cowa w przypadku b��du.
	* \return Wczytana warto�� lub domy�lna w przypadku wyst�pienia b��du.
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
	* \brief Metoda wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domy�lna warto�� zwr�cowa w przypadku b��du.
	* \return Wczytana warto�� lub domy�lna w przypadku wyst�pienia b��du.
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
	* \brief Metoda wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domy�lna warto�� zwr�cowa w przypadku b��du.
	* \return Wczytana warto�� lub domy�lna w przypadku wyst�pienia b��du.
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
	* \brief Metoda wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domy�lna warto�� zwr�cowa w przypadku b��du.
	* \return Wczytana warto�� lub domy�lna w przypadku wyst�pienia b��du.
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
	* \brief Metoda wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domy�lna warto�� zwr�cowa w przypadku b��du.
	* \return Wczytana warto�� lub domy�lna w przypadku wyst�pienia b��du.
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
	* \brief Metoda wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domy�lna warto�� zwr�cowa w przypadku b��du.
	* \return Wczytana warto�� lub domy�lna w przypadku wyst�pienia b��du.
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
	* \brief Metoda wczytuj�ca dane z atrybutu wez�a.
	*
	* Metoda wczytuje dane z atrybutu o podanej nazwie z podanego w�z�a.
	* \param[in] wezel - W�ze�, w kt�rego b�dize pobrany atrybut.
	* \param[in] nazwa - Nazwa atrybutu.
	* \param[in] domyslnaWartosc - Domy�lna warto�� zwr�cowa w przypadku b��du.
	* \return Wczytana warto�� lub domy�lna w przypadku wyst�pienia b��du.
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
* \brief Klasa definiuj�ca cechy reakcji na b��dy.
*
* Klasa zawiera metody o specyficznym zachowaniu w przypadku wykrycia b��du podczas korzystania z metod klasy XmlBO.
* Metody generuj� wyj�tki, zawieraj�ce opis wez�a i/lub atrybutu.
* \author Daniel Wojdak
* \version 1
* \date 18-06-2014
*/
class THROW {
public:
	/**
	* \brief Metoda generuj�ca wyj�tek.
	*
	* Metoda generuje wyj�tek jako reakcje na b��d.
	* \param[in] element - W�ze�.
	* \param[in] nazwaWezla - Nazwa w�z�a.
	* \param[in] stos - �lad stosu.
	* \return �adna warto�� nie jest zwracana.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static XmlBO::ElementWezla bladWezla(XmlBO::ElementWezla element, const std::string& nazwaWezla, const STyp::Tekst& debug = STyp::Tekst()){
		throw SPar::WyjatekParser(EXCEPTION_PLACE, debug, element.get(), std::string(ZMIANA_NAPIS_BLAD_WEZLA + nazwaWezla + ZMIANA_NAPIS_Z_WEZLA));
	}

	/**
	* \brief Metoda generuj�ca wyj�tek.
	*
	* Metoda generuje wyj�tek jako reakcje na b��d.
	* \param[in] element - W�ze�.
	* \param[in] nazwaAtrybutu - Nazwa atrybutu.
	* \param[in] stos - �lad stosu.
	* \return �adna warto�� nie jest zwracana.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static bool bladAtrybutu(XmlBO::ElementWezla element, const std::string& nazwaAtrybutu, const STyp::Tekst& debug = STyp::Tekst()){
		throw SPar::WyjatekParser(EXCEPTION_PLACE, debug, element.get(), std::string(ZMIANA_NAPIS_BLAD_ATRYBUTU + nazwaAtrybutu + ZMIANA_NAPIS_Z_WEZLA));
	}

};

/**
* \brief Klasa definiuj�ca cechy reakcji na b��dy.
*
* Klasa zawiera metody o specyficznym zachowaniu w przypadku wykrycia b��du podczas korzystania z metod klasy XmlBO.
* Metody zwracaj� warto�ci informuj�ce o b��dzie podczas obs�ugi b��du.
* \author Daniel Wojdak
* \version 1
* \date 18-06-2014
*/
class NOTHROW {
public:

	/**
	* \brief Metoda zwracaj�ca warto��
	*
	* Metoda zwraca warto�� nullptr jako reakcje na b��d.
	* \param[in] element - nieu�ywany parametr.
	* \param[in] nazwaWezla - nieu�ywany parametr.
	* \return Metoda zwraca nullptr.
	* \author Daniel Wojdak
	* \version 1
	* \date 18-06-2014
	*/
	static XmlBO::ElementWezla bladWezla(XmlBO::ElementWezla element, const std::string& nazwaWezla){
		return nullptr;
	}

	/**
	* \brief Metoda zwracaj�ca warto��
	*
	* Metoda zwraca warto�� false jako reakcje na b��d.
	* \param[in] element - nieu�ywany parametr.
	* \param[in] nazwaAtrybutu - nieu�ywany parametr.
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
	* \brief Klasa zawieraj�ca funkcje pomocnicze.
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
		* \brief Metoda generuj�ca wyj�tek.
		*
		* Metoda generuje wyj�tek typu WyjatekParser.
		* \param[in] wezel - W�ze�.
		* \param[in] stos - �lad stosu.
		* \author Daniel Wojdak
		* \version 1
		* \date 18-06-2014
		*/
		static void generujWyjatekBleduStruktury(XmlBO::ElementWezla wezel, const STyp::Tekst& debug = STyp::Tekst());
	};
}