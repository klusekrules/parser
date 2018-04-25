#pragma once
#include "ParserInterfejs.h"
#include "tinyxml2/tinyxml2.h"

namespace SPar{

	/**
	* \brief Klasa atrybutu parsera.
	*
	* Klasa implementuj¹ca interfejs klasy ParserAtrybut dla formatu typu XML.
	* \author Daniel Wojdak
	* \version 3
	* \date 25-03-2016
	*/
	class PARSER_API ParserAtrybutXml :
		public ParserAtrybut
	{
	public:
		/**
		* \brief Konstruktor.
		*
		* Konstruktor obiektu.
		* \param[in] atrybut - WskaŸnik na obiekt atrybutu.
		* \param[in] wezel - WskaŸnik na wêze³ zawieraj¹cy atrybut.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		ParserAtrybutXml( const tinyxml2::XMLAttribute* atrybut, tinyxml2::XMLElement* wezel );

		/**
		* \brief Destruktor.
		*
		* Domyœlny destruktor.
		*/
		virtual ~ParserAtrybutXml() = default;

		/**
		* \brief Metoda pobieraj¹ca nastêpny atrybut.
		*
		* Metoda pobiera natêpny element na liœcie atrybutów wêz³a.
		* \return WskaŸnika na atrybut.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserAtrybut> pobierzNastepnyAtrybut() const override;

		/**
		* \brief Metoda ustawiaj¹ca nazwê atrybutu.
		*
		* Metoda ustawia now¹ nazwê atrybutu na podan¹ w parametrze.
		* \param[in] nazwa - Nowa nazwa atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ nazwê atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawNazwe( const char* nazwa) override;

		/**
		* \brief Metoda pobieraj¹ca nazwê atrybutu.
		*
		* Metoda pobieraj¹ca nazwê atrybutu.
		* \return Aktualna nazwa atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzNazwe() const override;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartosc(const char* wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzWartosc( ) const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool ustawWartoscBool(bool wartosc) const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscBool() const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscBool(bool &wartosc) const override;
		
		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscInt(int wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.		
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		int pobierzWartoscInt( ) const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscInt(int &wartosc) const override;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscUnsignedInt(unsigned int wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		unsigned int pobierzWartoscUnsignedInt() const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscUnsignedInt(unsigned int &wartosc) const override;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool ustawWartoscLongLong(long long wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		long long pobierzWartoscLongLong() const override;
		
		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool pobierzWartoscLongLong(long long &wartosc) const override;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool ustawWartoscUnsignedLongLong(unsigned long long wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		unsigned long long pobierzWartoscUnsignedLongLong() const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 2
		* \date 25-03-2016
		*/
		bool pobierzWartoscUnsignedLongLong(unsigned long long &wartosc) const override;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscFloat(float wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		float pobierzWartoscFloat() const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscFloat(float &wartosc) const override;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscDouble(double wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		double pobierzWartoscDouble() const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscDouble(double &wartosc) const override;

		/**
		* \brief Metoda ustawiaj¹ca wartoœæ atrybutu.
		*
		* Metoda ustawia now¹ wartoœæ atrybutu na podan¹ w parametrze.
		* \param[in] wartosc - Nowa wartoœæ atrybutu.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ wartoœæ atrybutu. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawWartoscLongDouble(long double wartosc) override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \return Aktualna wartoœæ atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		long double pobierzWartoscLongDouble() const override;

		/**
		* \brief Metoda pobieraj¹ca wartoœæ atrybutu.
		*
		* Metoda pobieraj¹ca wartoœæ atrybutu.
		* \param[out] wartosc - Parametr do którego zostanie zapisana odczytana wartoœæ.
		* \return True jeœli wartoœæ zosta³a odczyta poprawnie, false w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-03-2016
		*/
		bool pobierzWartoscLongDouble(long double &wartosc) const override;

		/**
		* \brief Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		*
		* Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		* \return Zwraca wartoœæ true, je¿eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		operator bool()const override;

		/**
		* \brief Metoda pobieraj¹ca informacje o b³êdzie.
		*
		* Metoda pobieraj¹ca informacje o powodzie b³êdnego stanu aktualnego obiektu.
		* \return Napis zawieraj¹cy opis b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::string error()const override;

	private:
		const tinyxml2::XMLAttribute* atrybut_ = nullptr; /// WskaŸnik na obiekt atrybutu.
		tinyxml2::XMLElement* element_ = nullptr; /// WskaŸnik na element zawieraj¹cy atrybut.
	};
};
