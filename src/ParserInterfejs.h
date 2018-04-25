#pragma once
#include <memory>
#include <string>
#include <functional>
#include "ParserSymbol.h"

namespace SPar{

	/**
	* \brief Klasa bazowa atrybutu parsera.
	*
	* Klasa ujednolicaj¹ca interfejs parsera. Dostarcza ogólne metody dostêpu do obiektu.
	* \author Daniel Wojdak
	* \version 1
	* \date 24-06-2014
	*/
	class PARSER_API ParserAtrybut
	{
	public:

		/**
		* \brief Konstruktor bezparametrowy.
		*
		* Domyœlny konstruktor bezparametrowy.
		*/
		ParserAtrybut() = default;

		/**
		* \brief Destruktor.
		*
		* Domyœlny destruktor.
		*/
		virtual ~ParserAtrybut() = default;

		/**
		* \brief Konstruktor kopiuj¹cy.
		*
		* Domyœlny konstruktor kopiuj¹cy.
		* \param[in] obiekt - Obiekt Ÿród³owy.
		*/
		ParserAtrybut(const ParserAtrybut& obiekt) = default;

		/**
		* \brief Operator kopiowania.
		*
		* Domyœlny operator kopiowania.
		* \param[in] obiekt - Obiekt Ÿród³owy.
		*/
		ParserAtrybut& operator=(const ParserAtrybut& obiekt) = default;
		
		/**
		* \brief Metoda pobieraj¹ca nastêpny atrybut.
		*
		* Metoda pobiera natêpny element na liœcie atrybutów wêz³a.
		* \return WskaŸnika na atrybut.
		*/
		virtual std::shared_ptr<ParserAtrybut> pobierzNastepnyAtrybut() const  = 0;

		/**
		* \brief Metoda ustawiaj¹ca nazwê atrybutu.
		*
		* Metoda ustawia now¹ nazwê atrybutu na podan¹ w parametrze.
		* \param[in] nazwa - Nowa nazwa atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ nazwê atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawNazwe(const char* nazwa) = 0;

		/**
		* \brief Metoda pobieraj¹ca nazwê atrybutu.
		*
		* Metoda pobieraj¹ca nazwê atrybutu.
		* \return Aktualna nazwa atrybutu.
		*/
		virtual const char* pobierzNazwe() const = 0;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartosc(const char* wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual const char* pobierzWartosc() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual bool ustawWartoscBool(bool wartosc) const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual bool pobierzWartoscBool() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscBool(bool &wartosc) const = 0;
		
		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscInt(int wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual int pobierzWartoscInt() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscInt(int &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscUnsignedInt(unsigned int wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual unsigned int pobierzWartoscUnsignedInt() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscUnsignedInt(unsigned int &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscLongLong(long long wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual long long pobierzWartoscLongLong() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscLongLong(long long &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscUnsignedLongLong(unsigned long long wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual unsigned long long pobierzWartoscUnsignedLongLong() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscUnsignedLongLong(unsigned long long &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscFloat(float wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual float pobierzWartoscFloat() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscFloat(float &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscDouble(double wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual double pobierzWartoscDouble() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscDouble(double &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscLongDouble(long double wartosc) = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		*/
		virtual long double pobierzWartoscLongDouble() const = 0;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		*/
		virtual bool pobierzWartoscLongDouble(long double &wartosc) const = 0;

		/**
		* \brief Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		*
		* Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		* \return Zwraca wartoœæ true, je¿eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		*/
		virtual operator bool()const = 0;

		/**
		* \brief Metoda pobieraj¹ca informacje o b³êdzie.
		*
		* Metoda pobieraj¹ca informacje o powodzie b³êdnego stanu aktualnego obiektu.
		* \return Napis zawieraj¹cy opis b³êdu.
		*/
		virtual std::string error()const = 0;

	};

	/**
	* \brief Klasa bazowa wêz³a parsera.
	*
	* Klasa ujednolicaj¹ca interfejs parsera. Dostarcza ogólne metody dostêpu do obiektu.
	* \author Daniel Wojdak
	* \version 1
	* \date 24-06-2014
	*/
	class PARSER_API ParserElement
	{
	public:

		/**
		* \brief Konstruktor bezparametrowy.
		*
		* Domyœlny konstruktor bezparametrowy.
		*/
		ParserElement() = default;

		/**
		* \brief Destruktor.
		*
		* Domyœlny destruktor.
		*/
		virtual ~ParserElement() = default;

		/**
		* \brief Konstruktor kopiuj¹cy.
		*
		* Domyœlny konstruktor kopiuj¹cy.
		* \param[in] obiekt - Obiekt Ÿród³owy.
		*/
		ParserElement(const ParserElement& obiekt) = default;

		/**
		* \brief Operator kopiowania.
		*
		* Domyœlny operator kopiowania.
		* \param[in] obiekt - Obiekt Ÿród³owy.
		*/
		ParserElement& operator=(const ParserElement& obiekt) = default;

		/**
		* \brief Metoda ustawiaj¹ca nazwê wêz³a.
		*
		* Metoda ustawia now¹ nazwê wêz³a na podan¹ w parametrze.
		* \param[in] nazwa - Nowa nazwa wêz³a.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ nazwê wêz³a. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawNazwe(const char* nazwa) = 0;

		/**
		* \brief Metoda pobieraj¹ca nazwê wêz³a.
		*
		* Metoda pobieraj¹ca nazwê wêz³a.
		* \return Aktualna nazwa wêz³a.
		*/
		virtual const char* pobierzNazwe() const = 0;

		/**
		* \brief Metoda ustawiaj¹ca tekst wêz³a.
		*
		* Metoda ustawia nowy tekst wêz³a na podany w parametrze.
		* \param[in] tekst - Nowy tekst wêz³a.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ tekst wêz³a. Zwracana jest wartoœæ false w przeciwnym wypadku.
		*/
		virtual bool ustawTekst(const char* tekst) = 0;

		/**
		* \brief Metoda pobieraj¹ca tekst wêz³a.
		*
		* Metoda pobieraj¹ca tekst wêz³a.
		* \return Aktualny tekst wêz³a.
		*/
		virtual const char* pobierzTekst() const = 0;
		
		/**
		* \brief Metoda pobieraj¹ca atrybut.
		*
		* Metoda pobieraj¹ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracany jest wskaŸnik na atrybut lub wartoœæ nullptr, w przypadku b³êdu.
		*/
		virtual std::shared_ptr<ParserAtrybut> pobierzAtrybut(const char* nazwa) = 0;

		/**
		* \brief Metoda tworz¹ca atrybut.
		*
		* Metoda tworzy atrybut o podanej nazwie i wartoœci.
		* \param[in] nazwa - Nazwa atrybutu.
		* \param[in] wartosc - Wartoœæ atrybut.
		* \return Zwracany jest wskaŸnik na atrybut lub wartoœæ nullptr, w przypadku b³êdu.
		*/
		virtual std::shared_ptr<ParserAtrybut> tworzAtrybut(const char* nazwa, const char* wartosc) = 0;

		/**
		* \brief Metoda usuwaj¹ca atrybut.
		*
		* Metoda usuwaj¹ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracana jest true je¿eli uda³o siê usun¹æ lub wartoœæ false, w przypadku gdy nie ususniêto atrybutu.
		*/
		virtual bool usunAtrybut(const char* nazwa) = 0;
		
		/**
		* \brief Metoda pobieraj¹ca wêze³-dziecko.
		*
		* Metoda pobieraj¹ca wêze³-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		*/
		virtual std::shared_ptr<ParserElement> pobierzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda pobieraj¹ca wêze³-brat.
		*
		* Metoda pobieraj¹ca wêze³-brat o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		*/
		virtual std::shared_ptr<ParserElement> pobierzNastepnyElement(const char* nazwa) const = 0;

		/**
		* \brief Metoda tworz¹ca wêze³-dziecko.
		*
		* Metoda tworz¹ca wêze³-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		*/
		virtual std::shared_ptr<ParserElement> tworzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda usuwaj¹ca wêze³.
		*
		* Metoda usuwaj¹ca aktualny wêze³.
		* \return Zwracana jest true je¿eli uda³o siê usun¹æ lub wartoœæ false, w przypadku gdy nie ususniêto wêz³a.
		*/
		virtual bool usunElement() = 0;

		/**
		* \brief Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		*
		* Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		* \return Zwraca wartoœæ true, je¿eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		*/
		virtual operator bool()const = 0;

		/**
		* \brief Metoda pobieraj¹ca informacje o b³êdzie.
		*
		* Metoda pobieraj¹ca informacje o powodzie b³êdnego stanu aktualnego obiektu.
		* \return Napis zawieraj¹cy opis b³êdu.
		*/
		virtual std::string error()const = 0;

	};

	/**
	* \brief Klasa bazowa dokumentu parsera.
	*
	* Klasa ujednolicaj¹ca interfejs parsera. Dostarcza ogólne metody dostêpu do obiektu.
	* \author Daniel Wojdak
	* \version 1
	* \date 24-06-2014
	*/
	class PARSER_API ParserDokument
	{
	public:

		/**
		* \brief Konstruktor bezparametrowy.
		*
		* Domyœlny konstruktor bezparametrowy.
		*/
		ParserDokument() = default;

		/**
		* \brief Destruktor.
		*
		* Domyœlny destruktor.
		*/
		virtual ~ParserDokument() = default;

		/**
		* \brief Konstruktor kopiuj¹cy.
		*
		* Domyœlny konstruktor kopiuj¹cy.
		* \param[in] obiekt - Obiekt Ÿród³owy.
		*/
		ParserDokument(const ParserDokument& obiekt) = default;

		/**
		* \brief Operator kopiowania.
		*
		* Domyœlny operator kopiowania.
		* \param[in] obiekt - Obiekt Ÿród³owy.
		*/
		ParserDokument& operator=(const ParserDokument& obiekt) = default;
		
		/**
		* \brief Metoda pobieraj¹ca wêze³-dziecko.
		*
		* Metoda pobieraj¹ca wêze³-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		*/
		virtual std::shared_ptr<ParserElement> pobierzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda tworz¹ca wêze³-dziecko.
		*
		* Metoda tworz¹ca wêze³-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		*/
		virtual std::shared_ptr<ParserElement> tworzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda usuwaj¹ca wêze³.
		*
		* Metoda usuwaj¹ca wêze³ przekazany w parametrze.
		* \param[in] wezel - WskaŸnik na wêze³ do usuniêcia.
		* \return Zwracana jest true je¿eli uda³o siê usun¹æ lub wartoœæ false, w przypadku gdy nie ususniêto wêz³a.
		*/
		virtual bool usunElement(std::shared_ptr<ParserElement> wezel) = 0;

		/**
		* \brief Metoda odczytuj¹ca dane.
		*
		* Metoda wczytuje dane z pliku do obiektu.
		* \param[in] nazwaPliku - Nazwa pliku z którego s¹ wczytane dane.
		* \return Zwracana jest true je¿eli uda³o siê wczytaæ dane. Zwracana jest wartoœæ false, w przypadku b³êdu.
		*/
		virtual bool odczytaj(const char* nazwaPliku) = 0;

		/**
		* \brief Metoda zapisuj¹ca dane.
		*
		* Metoda zapisuje dane do pliku podanego w nazwie.
		* \param[in] nazwaPliku - Nazwa pliku do którego s¹ zapisywane dane.
		* \return Zwracana jest true je¿eli uda³o siê zapisaæ dane. Zwracana jest wartoœæ false, w przypadku b³êdu.
		*/
		virtual bool zapisz(const char* nazwaPliku) = 0;

		/**
		* \brief Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		*
		* Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		* \return Zwraca wartoœæ true, je¿eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		*/
		virtual operator bool()const = 0;

		/**
		* \brief Metoda pobieraj¹ca informacje o b³êdzie.
		*
		* Metoda pobieraj¹ca informacje o powodzie b³êdnego stanu aktualnego obiektu.
		* \return Napis zawieraj¹cy opis b³êdu.
		*/
		virtual std::string error()const = 0;

	};
};
