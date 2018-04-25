#pragma once
#include <memory>
#include <string>
#include <functional>
#include "ParserSymbol.h"

namespace SPar{

	/**
	* \brief Klasa bazowa atrybutu parsera.
	*
	* Klasa ujednolicaj�ca interfejs parsera. Dostarcza og�lne metody dost�pu do obiektu.
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
		* Domy�lny konstruktor bezparametrowy.
		*/
		ParserAtrybut() = default;

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		virtual ~ParserAtrybut() = default;

		/**
		* \brief Konstruktor kopiuj�cy.
		*
		* Domy�lny konstruktor kopiuj�cy.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		ParserAtrybut(const ParserAtrybut& obiekt) = default;

		/**
		* \brief Operator kopiowania.
		*
		* Domy�lny operator kopiowania.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		ParserAtrybut& operator=(const ParserAtrybut& obiekt) = default;
		
		/**
		* \brief Metoda pobieraj�ca nast�pny atrybut.
		*
		* Metoda pobiera nat�pny element na li�cie atrybut�w w�z�a.
		* \return Wska�nika na atrybut.
		*/
		virtual std::shared_ptr<ParserAtrybut> pobierzNastepnyAtrybut() const  = 0;

		/**
		* \brief Metoda ustawiaj�ca nazw� atrybutu.
		*
		* Metoda ustawia now� nazw� atrybutu na podan� w parametrze.
		* \param[in] nazwa - Nowa nazwa atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� nazw� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawNazwe(const char* nazwa) = 0;

		/**
		* \brief Metoda pobieraj�ca nazw� atrybutu.
		*
		* Metoda pobieraj�ca nazw� atrybutu.
		* \return Aktualna nazwa atrybutu.
		*/
		virtual const char* pobierzNazwe() const = 0;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartosc(const char* wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual const char* pobierzWartosc() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual bool ustawWartoscBool(bool wartosc) const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual bool pobierzWartoscBool() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscBool(bool &wartosc) const = 0;
		
		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscInt(int wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual int pobierzWartoscInt() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscInt(int &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscUnsignedInt(unsigned int wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual unsigned int pobierzWartoscUnsignedInt() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscUnsignedInt(unsigned int &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscLongLong(long long wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual long long pobierzWartoscLongLong() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscLongLong(long long &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscUnsignedLongLong(unsigned long long wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual unsigned long long pobierzWartoscUnsignedLongLong() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscUnsignedLongLong(unsigned long long &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscFloat(float wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual float pobierzWartoscFloat() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscFloat(float &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscDouble(double wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual double pobierzWartoscDouble() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscDouble(double &wartosc) const = 0;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawWartoscLongDouble(long double wartosc) = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		*/
		virtual long double pobierzWartoscLongDouble() const = 0;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		*/
		virtual bool pobierzWartoscLongDouble(long double &wartosc) const = 0;

		/**
		* \brief Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		*
		* Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		* \return Zwraca warto�� true, je�eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		*/
		virtual operator bool()const = 0;

		/**
		* \brief Metoda pobieraj�ca informacje o b��dzie.
		*
		* Metoda pobieraj�ca informacje o powodzie b��dnego stanu aktualnego obiektu.
		* \return Napis zawieraj�cy opis b��du.
		*/
		virtual std::string error()const = 0;

	};

	/**
	* \brief Klasa bazowa w�z�a parsera.
	*
	* Klasa ujednolicaj�ca interfejs parsera. Dostarcza og�lne metody dost�pu do obiektu.
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
		* Domy�lny konstruktor bezparametrowy.
		*/
		ParserElement() = default;

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		virtual ~ParserElement() = default;

		/**
		* \brief Konstruktor kopiuj�cy.
		*
		* Domy�lny konstruktor kopiuj�cy.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		ParserElement(const ParserElement& obiekt) = default;

		/**
		* \brief Operator kopiowania.
		*
		* Domy�lny operator kopiowania.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		ParserElement& operator=(const ParserElement& obiekt) = default;

		/**
		* \brief Metoda ustawiaj�ca nazw� w�z�a.
		*
		* Metoda ustawia now� nazw� w�z�a na podan� w parametrze.
		* \param[in] nazwa - Nowa nazwa w�z�a.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� nazw� w�z�a. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawNazwe(const char* nazwa) = 0;

		/**
		* \brief Metoda pobieraj�ca nazw� w�z�a.
		*
		* Metoda pobieraj�ca nazw� w�z�a.
		* \return Aktualna nazwa w�z�a.
		*/
		virtual const char* pobierzNazwe() const = 0;

		/**
		* \brief Metoda ustawiaj�ca tekst w�z�a.
		*
		* Metoda ustawia nowy tekst w�z�a na podany w parametrze.
		* \param[in] tekst - Nowy tekst w�z�a.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� tekst w�z�a. Zwracana jest warto�� false w przeciwnym wypadku.
		*/
		virtual bool ustawTekst(const char* tekst) = 0;

		/**
		* \brief Metoda pobieraj�ca tekst w�z�a.
		*
		* Metoda pobieraj�ca tekst w�z�a.
		* \return Aktualny tekst w�z�a.
		*/
		virtual const char* pobierzTekst() const = 0;
		
		/**
		* \brief Metoda pobieraj�ca atrybut.
		*
		* Metoda pobieraj�ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracany jest wska�nik na atrybut lub warto�� nullptr, w przypadku b��du.
		*/
		virtual std::shared_ptr<ParserAtrybut> pobierzAtrybut(const char* nazwa) = 0;

		/**
		* \brief Metoda tworz�ca atrybut.
		*
		* Metoda tworzy atrybut o podanej nazwie i warto�ci.
		* \param[in] nazwa - Nazwa atrybutu.
		* \param[in] wartosc - Warto�� atrybut.
		* \return Zwracany jest wska�nik na atrybut lub warto�� nullptr, w przypadku b��du.
		*/
		virtual std::shared_ptr<ParserAtrybut> tworzAtrybut(const char* nazwa, const char* wartosc) = 0;

		/**
		* \brief Metoda usuwaj�ca atrybut.
		*
		* Metoda usuwaj�ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracana jest true je�eli uda�o si� usun�� lub warto�� false, w przypadku gdy nie ususni�to atrybutu.
		*/
		virtual bool usunAtrybut(const char* nazwa) = 0;
		
		/**
		* \brief Metoda pobieraj�ca w�ze�-dziecko.
		*
		* Metoda pobieraj�ca w�ze�-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		*/
		virtual std::shared_ptr<ParserElement> pobierzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda pobieraj�ca w�ze�-brat.
		*
		* Metoda pobieraj�ca w�ze�-brat o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		*/
		virtual std::shared_ptr<ParserElement> pobierzNastepnyElement(const char* nazwa) const = 0;

		/**
		* \brief Metoda tworz�ca w�ze�-dziecko.
		*
		* Metoda tworz�ca w�ze�-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		*/
		virtual std::shared_ptr<ParserElement> tworzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda usuwaj�ca w�ze�.
		*
		* Metoda usuwaj�ca aktualny w�ze�.
		* \return Zwracana jest true je�eli uda�o si� usun�� lub warto�� false, w przypadku gdy nie ususni�to w�z�a.
		*/
		virtual bool usunElement() = 0;

		/**
		* \brief Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		*
		* Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		* \return Zwraca warto�� true, je�eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		*/
		virtual operator bool()const = 0;

		/**
		* \brief Metoda pobieraj�ca informacje o b��dzie.
		*
		* Metoda pobieraj�ca informacje o powodzie b��dnego stanu aktualnego obiektu.
		* \return Napis zawieraj�cy opis b��du.
		*/
		virtual std::string error()const = 0;

	};

	/**
	* \brief Klasa bazowa dokumentu parsera.
	*
	* Klasa ujednolicaj�ca interfejs parsera. Dostarcza og�lne metody dost�pu do obiektu.
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
		* Domy�lny konstruktor bezparametrowy.
		*/
		ParserDokument() = default;

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		virtual ~ParserDokument() = default;

		/**
		* \brief Konstruktor kopiuj�cy.
		*
		* Domy�lny konstruktor kopiuj�cy.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		ParserDokument(const ParserDokument& obiekt) = default;

		/**
		* \brief Operator kopiowania.
		*
		* Domy�lny operator kopiowania.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		ParserDokument& operator=(const ParserDokument& obiekt) = default;
		
		/**
		* \brief Metoda pobieraj�ca w�ze�-dziecko.
		*
		* Metoda pobieraj�ca w�ze�-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		*/
		virtual std::shared_ptr<ParserElement> pobierzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda tworz�ca w�ze�-dziecko.
		*
		* Metoda tworz�ca w�ze�-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		*/
		virtual std::shared_ptr<ParserElement> tworzElement(const char* nazwa) = 0;

		/**
		* \brief Metoda usuwaj�ca w�ze�.
		*
		* Metoda usuwaj�ca w�ze� przekazany w parametrze.
		* \param[in] wezel - Wska�nik na w�ze� do usuni�cia.
		* \return Zwracana jest true je�eli uda�o si� usun�� lub warto�� false, w przypadku gdy nie ususni�to w�z�a.
		*/
		virtual bool usunElement(std::shared_ptr<ParserElement> wezel) = 0;

		/**
		* \brief Metoda odczytuj�ca dane.
		*
		* Metoda wczytuje dane z pliku do obiektu.
		* \param[in] nazwaPliku - Nazwa pliku z kt�rego s� wczytane dane.
		* \return Zwracana jest true je�eli uda�o si� wczyta� dane. Zwracana jest warto�� false, w przypadku b��du.
		*/
		virtual bool odczytaj(const char* nazwaPliku) = 0;

		/**
		* \brief Metoda zapisuj�ca dane.
		*
		* Metoda zapisuje dane do pliku podanego w nazwie.
		* \param[in] nazwaPliku - Nazwa pliku do kt�rego s� zapisywane dane.
		* \return Zwracana jest true je�eli uda�o si� zapisa� dane. Zwracana jest warto�� false, w przypadku b��du.
		*/
		virtual bool zapisz(const char* nazwaPliku) = 0;

		/**
		* \brief Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		*
		* Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		* \return Zwraca warto�� true, je�eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		*/
		virtual operator bool()const = 0;

		/**
		* \brief Metoda pobieraj�ca informacje o b��dzie.
		*
		* Metoda pobieraj�ca informacje o powodzie b��dnego stanu aktualnego obiektu.
		* \return Napis zawieraj�cy opis b��du.
		*/
		virtual std::string error()const = 0;

	};
};
