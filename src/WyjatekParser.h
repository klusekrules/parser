#pragma once
#include "ParserInterfejs.h"
#include "Types\Wyjatek.h"

namespace SPar{

	/**
	* \brief Klasa wyj�tku parsera.
	*
	* Klasa wyj�tku generowanego w przypadku b��du struktury pliku XML.
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
		* \brief Konstruktor wyj�tku dla Atrybutu.
		*
		* Konstruktor wyj�tku przystosowany do generowania informacji o b��dnym atrybucie.
		* \param[in] plik - Plik w kt�rym wyst�pi� wyj�tek.
		* \param[in] funkcja - Funkcja w kt�rej wyst�pi� wyj�tek.
		* \param[in] linia - Linia w pliku w kt�rej wyst�pi� wyj�tek.
		* \param[in] sladStosu - �lad stosu w momencie wyst�pienia wyj�tku.
		* \param[in] atrybut - Wska�nik na obiekt b��dnego atrybutu.
		* \param[in] tekst - Dodatkowy tekst wy�wietlany w komunikacie wyj�tku.
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
		* \brief Konstruktor wyj�tku dla W�z�a.
		*
		* Konstruktor wyj�tku przystosowany do generowania informacji o b��dnym w�le.
		* \param[in] plik - Plik w kt�rym wyst�pi� wyj�tek.
		* \param[in] funkcja - Funkcja w kt�rej wyst�pi� wyj�tek.
		* \param[in] linia - Linia w pliku w kt�rej wyst�pi� wyj�tek.
		* \param[in] sladStosu - �lad stosu w momencie wyst�pienia wyj�tku.
		* \param[in] element - Wska�nik na obiekt b��dnego elementu.
		* \param[in] tekst - Dodatkowy tekst wy�wietlany w komunikacie wyj�tku.
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
		* \brief Konstruktor wyj�tku dla Dokumentu.
		*
		* Konstruktor wyj�tku przystosowany do generowania informacji o b��dnym dokumencie.
		* \param[in] plik - Plik w kt�rym wyst�pi� wyj�tek.
		* \param[in] funkcja - Funkcja w kt�rej wyst�pi� wyj�tek.
		* \param[in] linia - Linia w pliku w kt�rej wyst�pi� wyj�tek.
		* \param[in] sladStosu - �lad stosu w momencie wyst�pienia wyj�tku.
		* \param[in] dokument - Wska�nik na obiekt b��dnego dokumentu.
		* \param[in] tekst - Dodatkowy tekst wy�wietlany w komunikacie wyj�tku.
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
		* \brief Konstruktor kopiuj�cy.
		*
		* Domy�lny konstruktor kopiuj�cy.
		* \param[in] obiekt - Obiekt �r�d�owy.
		*/
		WyjatekParser(const WyjatekParser& obiekt) = default;

		/**
		* \brief Destruktor.
		*
		* Domy�lny destruktor.
		*/
		~WyjatekParser() = default;

		/**
		* \brief Metoda zwracaj�ca opis b��dnego elementu.
		*
		* Metoda zwraca opis b��dnego elementu: Atrybutu, W�z�a lub Dokumentu.
		* \return Tekst opisuj�cy b��dny element: Atrybutu, W�z�a lub Dokumentu.
		* \author Daniel Wojdak
		* \version 1
		* \date 24-06-2014
		*/
		const STyp::Tekst& zawartoscWezla()const;

		/**
		* \brief Metoda zwracaj�ca opis obiektu.
		*
		* Metoda zwraca opis obiektu.
		* \return Tekst opisuj�cy ca�y obiekt.
		* \author Daniel Wojdak
		* \version 1
		* \date 24-06-2014
		*/
		std::string napis() const override;

	private:
		STyp::Tekst wezel_; /// Opis b��dnego elementu: Atrybutu, W�z�a lub Dokumentu.
	};
}
