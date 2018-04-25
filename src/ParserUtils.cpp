#include "XmlBO.h"

#define ZMIANA_NAPIS_KOMUNIKAT_METODY_GENERUJACEJ_BLAD_STRUKTURY "W ni¿ej wyœwietlonym wêŸle wyst¹pi³ b³¹d struktury danych. "

namespace SPar{
	void ParserUtils::generujWyjatekBleduStruktury(XmlBO::ElementWezla wezel, const STyp::Tekst& debug)
	{
		throw SPar::WyjatekParser(EXCEPTION_PLACE, debug, wezel.get(), std::string(ZMIANA_NAPIS_KOMUNIKAT_METODY_GENERUJACEJ_BLAD_STRUKTURY));
	}
}
