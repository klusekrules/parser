#pragma once
#include "ParserInterfejs.h"
#include "Types\Wyjatek.h"

namespace SPar{

	/**
	* \brief Klasa wyj¹tku parsera.
	*
	* Klasa wyj¹tku generowanego w przypadku b³êdu struktury pliku XML.
	* \author Daniel Wojdak
	* \version 1
	* \date 24-06-2014
	*/
	class PARSER_API WyjatekParser: 
		public STyp::Wyjatek,
		virtual public SLog::LoggerInterface
	{
	public:

		/**
		* \brief Konstruktor wyj¹tku dla Atrybutu.
		*
		* Konstruktor wyj¹tku przystosowany do generowania informacji o b³êdnym atrybucie.
		* \param[in] plik - Plik w którym wyst¹pi³ wyj¹tek.
		* \param[in] funkcja - Funkcja w której wyst¹pi³ wyj¹tek.
		* \param[in] linia - Linia w pliku w której wyst¹pi³ wyj¹tek.
		* \param[in] sladStosu - Œlad stosu w momencie wyst¹pienia wyj¹tku.
		* \param[in] atrybut - WskaŸnik na obiekt b³êdnego atrybutu.
		* \param[in] tekst - Dodatkowy tekst wyœwietlany w komunikacie wyj¹tku.
		* \author Daniel Wojdak
		* \version 1
		* \date 24-06-2014
		*/
		WyjatekParser(
			const STyp::Tekst& plik,
			const STyp::Tekst& funkcja,
			const STyp::Ilosc& linia,
			const STyp::Tekst& debug,
			const ParserAtrybut* atrybut,
			const STyp::Tekst& tekst = STyp::Tekst()
			);

		/**
		* \brief Konstruktor wyj¹tku dla Wêz³a.
		*
		* Konstruktor wyj¹tku przystosowany do generowania informacji o b³êdnym wêŸle.
		* \param[in] plik - Plik w którym wyst¹pi³ wyj¹tek.
		* \param[in] funkcja - Funkcja w której wyst¹pi³ wyj¹tek.
		* \param[in] linia - Linia w pliku w której wyst¹pi³ wyj¹tek.
		* \param[in] sladStosu - Œlad stosu w momencie wyst¹pienia wyj¹tku.
		* \param[in] element - WskaŸnik na obiekt b³êdnego elementu.
		* \param[in] tekst - Dodatkowy tekst wyœwietlany w komunikacie wyj¹tku.
		* \author Daniel Wojdak
		* \version 1
		* \date 24-06-2014
		*/
		WyjatekParser(
			const STyp::Tekst& plik,
			const STyp::Tekst& funkcja,
			const STyp::Ilosc& linia,
			const STyp::Tekst& debug,
			const ParserElement* element,
			const STyp::Tekst& tekst = STyp::Tekst()
			);

		/**
		* \brief Konstruktor wyj¹tku dla Dokumentu.
		*
		* Konstruktor wyj¹tku przystosowany do generowania informacji o b³êdnym dokumencie.
		* \param[in] plik - Plik w którym wyst¹pi³ wyj¹tek.
		* \param[in] funkcja - Funkcja w której wyst¹pi³ wyj¹tek.
		* \param[in] linia - Linia w pliku w której wyst¹pi³ wyj¹tek.
		* \param[in] sladStosu - Œlad stosu w momencie wyst¹pienia wyj¹tku.
		* \param[in] dokument - WskaŸnik na obiekt b³êdnego dokumentu.
		* \param[in] tekst - Dodatkowy tekst wyœwietlany w komunikacie wyj¹tku.
		* \author Daniel Wojdak
		* \version 1
		* \date 24-06-2014
		*/
		WyjatekParser(
			const STyp::Tekst& plik,
			const STyp::Tekst& funkcja,
			const STyp::Ilosc& linia,
			const STyp::Tekst& debug,
			const ParserDokument* dokument,
			const STyp::Tekst& tekst = STyp::Tekst()
			);

		/**
		* \brief Konstruktor kopiuj¹cy.
		*
		* Domyœlny konstruktor kopiuj¹cy.
		* \param[in] obiekt - Obiekt Ÿród³owy.
		*/
		WyjatekParser(const WyjatekParser& obiekt) = default;

		/**
		* \brief Destruktor.
		*
		* Domyœlny destruktor.
		*/
		~WyjatekParser() = default;

		/**
		* \brief Metoda zwracaj¹ca opis b³êdnego elementu.
		*
		* Metoda zwraca opis b³êdnego elementu: Atrybutu, Wêz³a lub Dokumentu.
		* \return Tekst opisuj¹cy b³êdny element: Atrybutu, Wêz³a lub Dokumentu.
		* \author Daniel Wojdak
		* \version 1
		* \date 24-06-2014
		*/
		const STyp::Tekst& zawartoscWezla()const;

		/**
		* \brief Metoda zwracaj¹ca opis obiektu.
		*
		* Metoda zwraca opis obiektu.
		* \return Tekst opisuj¹cy ca³y obiekt.
		* \author Daniel Wojdak
		* \version 1
		* \date 24-06-2014
		*/
		std::string napis() const override;

	private:
		STyp::Tekst wezel_; /// Opis b³êdnego elementu: Atrybutu, Wêz³a lub Dokumentu.
	};
}
