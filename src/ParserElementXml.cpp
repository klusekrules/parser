#include "ParserElementXml.h"
#include "ParserAtrybutXml.h"

namespace SPar{
	ParserElementXml::ParserElementXml(tinyxml2::XMLElement* element)
		: element_(element)
	{
	}

	bool ParserElementXml::ustawNazwe(const char* nazwa){
		if (!nazwa || !element_)
			return false;
		element_->SetName(nazwa);
		return true;
	}

	const char* ParserElementXml::pobierzNazwe() const{
		if (!element_)
			return nullptr;
		return element_->Name();
	}

	bool ParserElementXml::ustawTekst(const char* tekst){
		if (element_){
			if (element_->FirstChild() && element_->FirstChild()->ToText()) {
				element_->FirstChild()->ToText()->SetValue(tekst);
				return true;
			}
			else{
				auto wezel = element_->GetDocument()->NewText(tekst);
				if (wezel){
					element_->LinkEndChild(wezel);
					return true;
				}
			}
		}
		return false;
	}

	const char* ParserElementXml::pobierzTekst()const{
		if (!element_)
			return nullptr;
		return element_->GetText();
	}

	std::shared_ptr<ParserAtrybut> ParserElementXml::pobierzAtrybut(const char* atrybut){
		if (element_){
			const tinyxml2::XMLAttribute* atr = const_cast<const tinyxml2::XMLElement*>(element_)->FindAttribute(atrybut);
			if (!atr)
				return nullptr;
			else
				return std::make_shared<ParserAtrybutXml>(atr, element_);
		}
		return nullptr;
	}

	std::shared_ptr<ParserAtrybut> ParserElementXml::tworzAtrybut(const char* atrybut, const char* wartosc){
		if (!element_)
			return nullptr;
		element_->SetAttribute(atrybut, wartosc);
		return pobierzAtrybut(atrybut);
	}

	bool ParserElementXml::usunAtrybut(const char* atrybut){
		if (!element_)
			return false;
		element_->DeleteAttribute(atrybut);
		return true;
	}

	ParserElementXml::operator bool()const{
		if (!element_)
			return false;
		return true;
	}

	std::shared_ptr<ParserElement> ParserElementXml::pobierzElement(const char* element){
		if (!element_)
			return nullptr;
		auto wezel = element_->FirstChildElement(element);
		if (wezel)
			return std::make_shared<ParserElementXml>(wezel);
		else
			return nullptr;
	}

	std::shared_ptr<ParserElement> ParserElementXml::pobierzNastepnyElement(const char* element) const {
		if (!element_)
			return nullptr;
		auto wezel = element_->NextSiblingElement(element);
		if (wezel)
			return std::make_shared<ParserElementXml>(wezel);
		else
			return nullptr;
	}
	std::shared_ptr<ParserElement> ParserElementXml::tworzElement(const char* element){
		if (!element_)
			return nullptr;
		auto wezel = element_->GetDocument()->NewElement(element);
		if (!wezel)
			return nullptr;
		element_->LinkEndChild(wezel);
		return std::make_shared<ParserElementXml>(wezel);
	}

	bool ParserElementXml::usunElement(){
		auto node = element_->Parent();
		if (!node)
			return false;
		node->DeleteChild(element_);
		element_ = nullptr;
		return true;
	}

	std::string ParserElementXml::error()const{
		tinyxml2::XMLPrinter printer;
		if (element_){
			element_->Accept(&printer);
			return printer.CStr();
		}
		else{
			return std::string("nullptr");
		}
	}
}