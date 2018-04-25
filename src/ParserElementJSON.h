#pragma once
#include "ParserInterfejs.h"
#include "json/json.h"

namespace SPar {

	class PARSER_API ParserElementJSON :
		public ParserElement
	{
	public:
		ParserElementJSON(Json::ValueIterator iterator, Json::ValueIterator end);

		virtual ~ParserElementJSON() = default;

		/**
		* \brief Metoda ustawiaj¹ca nazwê wêz³a.
		*
		* Metoda ustawia now¹ nazwê wêz³a na podan¹ w parametrze.
		* \param[in] nazwa - Nowa nazwa wêz³a.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ nazwê wêz³a. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawNazwe(const char* nazwa) override;

		/**
		* \brief Metoda pobieraj¹ca nazwê wêz³a.
		*
		* Metoda pobieraj¹ca nazwê wêz³a.
		* \return Aktualna nazwa wêz³a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzNazwe() const override;

		/**
		* \brief Metoda ustawiaj¹ca tekst wêz³a.
		*
		* Metoda ustawia nowy tekst wêz³a na podany w parametrze.
		* \param[in] tekst - Nowy tekst wêz³a.
		* \return Zwracana jest wartoœæ true, je¿eli uda siê ustawiæ tekst wêz³a. Zwracana jest wartoœæ false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool ustawTekst(const char* tekst) override;

		/**
		* \brief Metoda pobieraj¹ca tekst wêz³a.
		*
		* Metoda pobieraj¹ca tekst wêz³a.
		* \return Aktualny tekst wêz³a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		const char* pobierzTekst()const override;

		/**
		* \brief Metoda pobieraj¹ca atrybut.
		*
		* Metoda pobieraj¹ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracany jest wskaŸnik na atrybut lub wartoœæ nullptr, w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserAtrybut> pobierzAtrybut(const char* nazwa) override;

		/**
		* \brief Metoda tworz¹ca atrybut.
		*
		* Metoda tworzy atrybut o podanej nazwie i wartoœci.
		* \param[in] nazwa - Nazwa atrybutu.
		* \param[in] wartosc - Wartoœæ atrybut.
		* \return Zwracany jest wskaŸnik na atrybut lub wartoœæ nullptr, w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserAtrybut> tworzAtrybut(const char* nazwa, const char* wartosc) override;

		/**
		* \brief Metoda usuwaj¹ca atrybut.
		*
		* Metoda usuwaj¹ca atrybut o podanej nazwie.
		* \param[in] nazwa - Nazwa atrybutu.
		* \return Zwracana jest true je¿eli uda³o siê usun¹æ lub wartoœæ false, w przypadku gdy nie ususniêto atrybutu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool usunAtrybut(const char* nazwa) override;

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
		* \brief Metoda pobieraj¹ca wêze³-brat.
		*
		* Metoda pobieraj¹ca wêze³-brat o podanej nazwie.
		* \param[in] nazwa - Nazwa wêz³a.
		* \return Zwracany jest wskaŸnik na wêze³ lub wartoœæ nullptr, w przypadku b³êdu.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		std::shared_ptr<ParserElement> pobierzNastepnyElement(const char* nazwa) const override;

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
		* Metoda usuwaj¹ca aktualny wêze³.
		* \return Zwracana jest true je¿eli uda³o siê usun¹æ lub wartoœæ false, w przypadku gdy nie ususniêto wêz³a.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		bool usunElement() override;

		/**
		* \brief Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		*
		* Metoda pobieraj¹ca informacje o poprawnoœci obiektu.
		* \return Zwraca wartoœæ true, je¿eli obiekt jest w poprawnym stanie. Zwracana jest metoda false w przeciwnym wypadku.
		* \author Daniel Wojdak
		* \version 1
		* \date 25-06-2014
		*/
		operator bool()const;

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
		Json::ValueIterator iterator_;
		Json::ValueIterator end_;
		std::string error_;
	};
}
