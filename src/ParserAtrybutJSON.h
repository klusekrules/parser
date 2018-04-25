#pragma once
#include "ParserInterfejs.h"
#include "json/json.h"

namespace SPar{
	/**
	* \brief Klasa atrybutu parsera.
	*
	* Klasa implementuj�ca interfejs klasy ParserAtrybut dla formatu typu JSON.
	* \author Daniel Wojdak
	* \version 3
	* \date 25-03-2016
	*/
	class PARSER_API ParserAtrybutJSON :
		public ParserAtrybut
	{
	public:
		/**
		* \brief Konstruktor.
		*
		* Konstruktor obiektu.
		* \param[in] atrybut - Wska�nik na obiekt atrybutu.
		* \param[in] wezel - Wska�nik na w�ze� zawieraj�cy atrybut.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		ParserAtrybutJSON(Json::ValueIterator iterator, Json::ValueIterator end);

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		virtual ~ParserAtrybutJSON() = default;

		/**
		* \brief Metoda pobieraj�ca nast�pny atrybut.
		*
		* Metoda pobiera nat�pny element na li�cie atrybut�w w�z�a.
		* \return Wska�nika na atrybut.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserAtrybut> pobierzNastepnyAtrybut() const override;

		/**
		* \brief Metoda ustawiaj�ca nazw� atrybutu.
		*
		* Metoda ustawia now� nazw� atrybutu na podan� w parametrze.
		* \param[in] nazwa - Nowa nazwa atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� nazw� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawNazwe(const char* nazwa) override;

		/**
		* \brief Metoda pobieraj�ca nazw� atrybutu.
		*
		* Metoda pobieraj�ca nazw� atrybutu.
		* \return Aktualna nazwa atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzNazwe() const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartosc(const char* wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzWartosc() const override;
		
		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool ustawWartoscBool(bool wartosc) const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscBool() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscBool(bool &wartosc) const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscInt(int wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		int pobierzWartoscInt() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscInt(int &wartosc) const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscUnsignedInt(unsigned int wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		unsigned int pobierzWartoscUnsignedInt() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscUnsignedInt(unsigned int &wartosc) const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool ustawWartoscLongLong(long long wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		long long pobierzWartoscLongLong() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool pobierzWartoscLongLong(long long &wartosc) const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool ustawWartoscUnsignedLongLong(unsigned long long wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		unsigned long long pobierzWartoscUnsignedLongLong() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool pobierzWartoscUnsignedLongLong(unsigned long long &wartosc) const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscFloat(float wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		float pobierzWartoscFloat() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscFloat(float &wartosc) const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscDouble(double wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		double pobierzWartoscDouble() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscDouble(double &wartosc) const override;

		/**
		* \brief Metoda ustawiaj�ca warto�� atrybutu.
		*
		* Metoda ustawia now� warto�� atrybutu na podan� w parametrze.
		* \param[in] wartosc - Nowa warto�� atrybutu.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� warto�� atrybutu. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscLongDouble(long double wartosc) override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \return Aktualna warto�� atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		long double pobierzWartoscLongDouble() const override;

		/**
		* \brief Metoda pobieraj�ca warto�� atrybutu.
		*
		* Metoda pobieraj�ca warto�� atrybutu.
		* \param[out] wartosc - Parametr do kt�rego zostanie zapisana odczytana warto��.
		* \return True je�li warto�� zosta�a odczyta poprawnie, false w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscLongDouble(long double &wartosc) const override;

		/**
		* \brief Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		*
		* Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		* \return Zwraca warto�� true, je�eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		operator bool()const override;

		/**
		* \brief Metoda pobieraj�ca informacje o b��dzie.
		*
		* Metoda pobieraj�ca informacje o powodzie b��dnego stanu aktualnego obiektu.
		* \return Napis zawieraj�cy opis b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::string error()const override;

	private:
		Json::ValueIterator iterator_;
		Json::ValueIterator end_;
		std::string error_;
	};
}
