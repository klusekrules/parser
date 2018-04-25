#include "ParserDokumentXml.h"
#include "ParserElementXml.h"
#include <sstream>

namespace SPar{

	std::shared_ptr<ParserElement> ParserDokumentXml::pobierzElement(const char* nazwa){
		auto ptr = dokument_.FirstChildElement(nazwa);
		if (ptr) {
			return std::make_shared<ParserElementXml>(ptr);
		}
		return nullptr;
		
	}

	std::shared_ptr<ParserElement> ParserDokumentXml::tworzElement(const char* nazwa){
		auto element = dokument_.NewElement(nazwa);
		dokument_.LinkEndChild(element);
		return std::make_shared<ParserElementXml>(element);
	}

	bool ParserDokumentXml::usunElement(std::shared_ptr<ParserElement> element){
		return element->usunElement();
	}

	bool ParserDokumentXml::odczytaj(const char* nazwa){
		if (!nazwa)
			return false;
		nazwa_ = nazwa;
		return dokument_.LoadFile(nazwa) == tinyxml2::XML_SUCCESS;
	}

	bool ParserDokumentXml::zapisz(const char* nazwa){
		if (nazwa){
			nazwa_ = nazwa;
			return dokument_.SaveFile(nazwa) == tinyxml2::XML_SUCCESS;
		}
		else{
			if (nazwa_.empty())
				return false;
			return dokument_.SaveFile(nazwa_.c_str()) == tinyxml2::XML_SUCCESS;
		}
	}

	ParserDokumentXml::operator bool()const{
		return !dokument_.Error();
	}

	std::string ParserDokumentXml::error()const{
		std::stringstream str;
		str << dokument_.ErrorID() << " : " << (dokument_.GetErrorStr1() ? dokument_.GetErrorStr1() : " ") << "; " << (dokument_.GetErrorStr2() ? dokument_.GetErrorStr2() : " ");
		return str.str();
	}
}
