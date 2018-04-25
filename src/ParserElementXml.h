#pragma once
#include "ParserInterfejs.h"
#include "tinyxml2/tinyxml2.h"

namespace SPar {

	/**
	* \brief Klasa w�z�a parsera.
	*
	* Klasa implementuj�ca interfejs parsera dla formatu typu XML.
	* \author Daniel Wojdak
	* \version 1
	* \date 25-06-2014
	*/
	class PARSER_API ParserElementXml :
		public ParserElement
	{
		friend class ParserDokumentXml;
	public:

		/**
		* \brief Konstruktor.
		*
		* Konstruktor obiektu.
		* \param[in] wezel - Wska�nik do w�z�a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		ParserElementXml(tinyxml2::XMLElement* wezel);

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		virtual ~ParserElementXml() = default;

		/**
		* \brief Metoda ustawiaj�ca nazw� w�z�a.
		*
		* Metoda ustawia now� nazw� w�z�a na podan� w parametrze.
		* \param[in] nazwa - Nowa nazwa w�z�a.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� nazw� w�z�a. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawNazwe(const char* nazwa) override;

		/**
		* \brief Metoda pobieraj�ca nazw� w�z�a.
		*
		* Metoda pobieraj�ca nazw� w�z�a.
		* \return Aktualna nazwa w�z�a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzNazwe() const override;

		/**
		* \brief Metoda ustawiaj�ca tekst w�z�a.
		*
		* Metoda ustawia nowy tekst w�z�a na podany w parametrze.
		* \param[in] tekst - Nowy tekst w�z�a.
		* \return Zwracana jest warto�� true, je�eli uda si� ustawi� tekst w�z�a. Zwracana jest warto�� false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawTekst(const char* tekst) override;

		/**
		* \brief Metoda pobieraj�ca tekst w�z�a.
		*
		* Metoda pobieraj�ca tekst w�z�a.
		* \return Aktualny tekst w�z�a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzTekst()const override;

		/**
		* \brief Metoda pobieraj�ca atrybut.
		*
		* Metoda pobieraj�ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracany jest wska�nik na atrybut lub warto�� nullptr, w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserAtrybut> pobierzAtrybut(const char* nazwa) override;

		/**
		* \brief Metoda tworz�ca atrybut.
		*
		* Metoda tworzy atrybut o podanej nazwie i warto�ci.
		* \param[in] nazwa - Nazwa atrybutu.
		* \param[in] wartosc - Warto�� atrybut.
		* \return Zwracany jest wska�nik na atrybut lub warto�� nullptr, w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserAtrybut> tworzAtrybut(const char* nazwa, const char* wartosc) override;

		/**
		* \brief Metoda usuwaj�ca atrybut.
		*
		* Metoda usuwaj�ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracana jest true je�eli uda�o si� usun�� lub warto�� false, w przypadku gdy nie ususni�to atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool usunAtrybut(const char* nazwa) override;

		/**
		* \brief Metoda pobieraj�ca w�ze�-dziecko.
		*
		* Metoda pobieraj�ca w�ze�-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserElement> pobierzElement(const char* nazwa) override;

		/**
		* \brief Metoda pobieraj�ca w�ze�-brat.
		*
		* Metoda pobieraj�ca w�ze�-brat o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserElement> pobierzNastepnyElement(const char* nazwa) const override;

		/**
		* \brief Metoda tworz�ca w�ze�-dziecko.
		*
		* Metoda tworz�ca w�ze�-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa w�z�a.
		* \return Zwracany jest wska�nik na w�ze� lub warto�� nullptr, w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserElement> tworzElement(const char* nazwa) override;

		/**
		* \brief Metoda usuwaj�ca w�ze�.
		*
		* Metoda usuwaj�ca aktualny w�ze�.
		* \return Zwracana jest true je�eli uda�o si� usun�� lub warto�� false, w przypadku gdy nie ususni�to w�z�a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool usunElement() override;

		/**
		* \brief Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		*
		* Metoda pobieraj�ca informacje o poprawno�ci obiektu.
		* \return Zwraca warto�� true, je�eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		operator bool()const;

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
		tinyxml2::XMLElement* element_ = nullptr; /// Wska�nik na element.
	};
};
