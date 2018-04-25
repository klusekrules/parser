#pragma once
#include "ParserInterfejs.h"
#include "tinyxml2/tinyxml2.h"

namespace SPar{

	/**
	* \brief Klasa dokumentu parsera.
	*
	* Klasa implementuj�ca interfejs parsera dla formatu XML.
	* \author Daniel Wojdak
	* \version 1
	* \date 25-06-2014
	*/
	class PARSER_API ParserDokumentXml :
		public ParserDokument
	{
	public:

		/**
		* \brief Konstruktor bezparametrowy.
		*
		* Domy�lny konstruktor bezparametrowy.
		*/
		ParserDokumentXml() = default;

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		virtual ~ParserDokumentXml() = default;

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
		* Metoda usuwaj�ca w�ze� przekazany w parametrze.
		* \param[in] wezel - Wska�nik na w�ze� do usuni�cia.
		* \return Zwracana jest true je�eli uda�o si� usun�� lub warto�� false, w przypadku gdy nie ususni�to w�z�a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool usunElement(std::shared_ptr<ParserElement> wezel) override;

		/**
		* \brief Metoda odczytuj�ca dane.
		*
		* Metoda wczytuje dane z pliku do obiektu.
		* \param[in] nazwaPliku - Nazwa pliku z kt�rego s� wczytane dane.
		* \return Zwracana jest true je�eli uda�o si� wczyta� dane. Zwracana jest warto�� false, w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool odczytaj(const char* nazwaPliku) override;

		/**
		* \brief Metoda zapisuj�ca dane.
		*
		* Metoda zapisuje dane do pliku podanego w nazwie.
		* \param[in] nazwaPliku - Nazwa pliku do kt�rego s� zapisywane dane.
		* \return Zwracana jest true je�eli uda�o si� zapisa� dane. Zwracana jest warto�� false, w przypadku b��du.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool zapisz(const char* nazwaPliku) override;

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
		tinyxml2::XMLDocument dokument_; /// Obiekt dokumentu.
		std::string nazwa_; /// Adres pliku xml.
	};
};
