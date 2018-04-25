#include "WyjatekParser.h"
#include "Logger\Logger.h"
#include "ParserStale.h"

namespace SPar{
	WyjatekParser::WyjatekParser(
		const STyp::Tekst& plik,
		const STyp::Tekst& funkcja,
		const STyp::Ilosc& linia,
		const STyp::Tekst& debug,
		const ParserAtrybut* atrybut,
		const STyp::Tekst& tekst
		)
		: Wyjatek(
		plik,
		funkcja,
		linia,
		debug,
		STyp::Identyfikator(PARSER_WYJATEK_ATRYBUTU_ID),
		STyp::Tekst(PARSER_WYJATEK_ATRYBUTU_TYTUL),
		STyp::Tekst(tekst.isEmpty() ? (STyp::Tekst(PARSER_WYJATEK_ATRYBUTU_TRESC) + STyp::Tekst(atrybut ? atrybut->error() : PARSER_WYJATEK_NULLPTR)) : (tekst + STyp::Tekst(atrybut ? atrybut->error() : PARSER_WYJATEK_NULLPTR)))),
		wezel_(STyp::Tekst(atrybut ? atrybut->error() : PARSER_WYJATEK_NULLPTR))
	{
	}

	WyjatekParser::WyjatekParser(
		const STyp::Tekst& plik,
		const STyp::Tekst& funkcja,
		const STyp::Ilosc& linia,
		const STyp::Tekst& debug,
		const ParserElement* element,
		const STyp::Tekst& tekst
		)
		: Wyjatek(
		plik,
		funkcja,
		linia,
		debug,
		STyp::Identyfikator(PARSER_WYJATEK_ELEMENTU_ID),
		STyp::Tekst(PARSER_WYJATEK_ELEMENTU_TYTUL),
		STyp::Tekst(tekst.isEmpty() ? (STyp::Tekst(PARSER_WYJATEK_ELEMENTU_TRESC) + STyp::Tekst(element ? element->error() : PARSER_WYJATEK_NULLPTR)) : (tekst + STyp::Tekst(element ? element->error() : PARSER_WYJATEK_NULLPTR)))),
		wezel_(STyp::Tekst(element ? element->error() : PARSER_WYJATEK_NULLPTR))
	{
	}

	WyjatekParser::WyjatekParser(
		const STyp::Tekst& plik,
		const STyp::Tekst& funkcja,
		const STyp::Ilosc& linia,
		const STyp::Tekst& debug,
		const ParserDokument* dokument,
		const STyp::Tekst& tekst
		) : Wyjatek(
		plik,
		funkcja,
		linia,
		debug,
		STyp::Identyfikator(PARSER_WYJATEK_DOKUMENTU_ID),
		STyp::Tekst(PARSER_WYJATEK_DOKUMENTU_TYTUL),
		STyp::Tekst(tekst.isEmpty() ? STyp::Tekst(PARSER_WYJATEK_DOKUMENTU_TRESC) + STyp::Tekst(dokument ? dokument->error() : PARSER_WYJATEK_NULLPTR) : tekst + STyp::Tekst(dokument ? dokument->error() : PARSER_WYJATEK_NULLPTR))),
		wezel_(STyp::Tekst(dokument ? dokument->error() : PARSER_WYJATEK_NULLPTR))
	{
	}

	const STyp::Tekst& WyjatekParser::zawartoscWezla()const{
		return wezel_;
	}

	std::string WyjatekParser::napis() const {
		SLog::Logger str(NAZWAKLASY(WyjatekParser));
		str.dodajKlase(Wyjatek::napis());
		str.dodajPole(NAZWAPOLA(wezel_),wezel_);
		return std::move(str.napis());
	}

}
