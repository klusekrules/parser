#pragma once
#include "ParserInterfejs.h"
#include "tinyxml2/tinyxml2.h"

namespace SPar{

	/**
	* \brief Klasa dokumentu parsera.
	*
	* Klasa implementuj¹ca interfejs parsera dla formatu XML.
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
		* Domyœlny konstruktor bezparametrowy.
		*/
		ParserDokumentXml() = default;

		/**
		* \brief Destruktor.
		*
		* Domyœlny destruktor.
		*/
		virtual ~ParserDokumentXml() = default;

		/**
		* \brief Metoda pobieraj¹ca wêze³-dziecko.
		*
		* Metoda pobieraj¹ca wêze³-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserElement> pobierzElement(const char* nazwa) override;

		/**
		* \brief Metoda tworz¹ca wêze³-dziecko.
		*
		* Metoda tworz¹ca wêze³-dziecko o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserElement> tworzElement(const char* nazwa) override;

		/**
		* \brief Metoda usuwaj¹ca wêze³.
		*
		* Metoda usuwaj¹ca wêze³ przekazany w parametrze.
		* \param[in] wezel - WskaŸnik na wêze³ do usuniêcia.
		* \return Zwracana jest true je¿eli uda³o siê usun¹æ lub wartoœæ false, w przypadku gdy nie ususniêto wêz³a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool usunElement(std::shared_ptr<ParserElement> wezel) override;

		/**
		* \brief Metoda odczytuj¹ca dane.
		*
		* Metoda wczytuje dane z pliku do obiektu.
		* \param[in] nazwaPliku - Nazwa pliku z którego s¹ wczytane dane.
		* \return Zwracana jest true je¿eli uda³o siê wczytaæ dane. Zwracana jest wartoœæ false, w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool odczytaj(const char* nazwaPliku) override;

		/**
		* \brief Metoda zapisuj¹ca dane.
		*
		* Metoda zapisuje dane do pliku podanego w nazwie.
		* \param[in] nazwaPliku - Nazwa pliku do którego s¹ zapisywane dane.
		* \return Zwracana jest true je¿eli uda³o siê zapisaæ dane. Zwracana jest wartoœæ false, w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool zapisz(const char* nazwaPliku) override;

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
		tinyxml2::XMLDocument dokument_; /// Obiekt dokumentu.
		std::string nazwa_; /// Adres pliku xml.
	};
};
