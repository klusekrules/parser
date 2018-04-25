#include "ParserDokumentJSON.h"
#include "ParserElementJSON.h"
#include <fstream>

namespace SPar{
	std::shared_ptr<ParserElement> ParserDokumentJSON::pobierzElement(const char* nazwa){
		if (root_.isObject()){
			for (auto iter = root_.begin(); iter != root_.end(); ++iter){
				if (strcmp(iter.name().c_str(), nazwa) == 0){
					return std::make_shared<ParserElementJSON>(iter, root_.end());
				}
			}
		}
		return nullptr;
	}

	std::shared_ptr<ParserElement> ParserDokumentJSON::tworzElement(const char* nazwa){
		if (root_.isObject()){
			root_[nazwa] = Json::objectValue;
			return pobierzElement(nazwa);
		}
		return nullptr;
	}

	bool ParserDokumentJSON::usunElement(std::shared_ptr<ParserElement> element){
		if (element){
			Json::Value *temp = nullptr;
			return root_.removeMember(element->pobierzNazwe(), temp);
		}
		return false;
	}

	bool ParserDokumentJSON::odczytaj(const char* nazwa){
		if (!nazwa)
			return false;
		nazwa_ = nazwa;
		std::ifstream plik(nazwa_);
		return Json::parseFromStream(Json::CharReaderBuilder(), plik, &root_, &error_);
	}

	bool ParserDokumentJSON::zapisz(const char* nazwa){
		if (nazwa)
			nazwa_ = nazwa;

		if (nazwa_.empty())
			return false;
			
		std::ofstream plik(nazwa_);
		plik << root_;
		plik.flush();
		return plik.good();
	}

	ParserDokumentJSON::operator bool()const{
		return !root_.isNull();
	}

	std::string ParserDokumentJSON::error()const{
		if (!root_.isNull()){
			return error_;
		}
		else{
			return std::string("nullptr");
		}
	}

}
