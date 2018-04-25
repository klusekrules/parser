#include "ParserElementJSON.h"
#include "ParserAtrybutJSON.h"

namespace SPar {

	ParserElementJSON::ParserElementJSON(Json::ValueIterator iterator, Json::ValueIterator end)
		: iterator_(iterator), end_(end)
	{
	}

	bool ParserElementJSON::ustawNazwe(const char* nazwa){
		return false;
	}

	const char* ParserElementJSON::pobierzNazwe() const{
		return iterator_.name().c_str();
	}

	bool ParserElementJSON::ustawTekst(const char* tekst){
		if (iterator_ != end_ && !iterator_->isArray() && !iterator_->isObject()){
			*iterator_ = tekst;
			return true;
		}
		return false;
	}

	const char* ParserElementJSON::pobierzTekst()const{
		if (iterator_ != end_ && !iterator_->isArray() && !iterator_->isObject()){
			return iterator_->asCString();
		}
		return nullptr;
	}

	std::shared_ptr<ParserAtrybut> ParserElementJSON::pobierzAtrybut(const char* atrybut){
		if (iterator_ != end_ && iterator_->isArray() || iterator_->isObject()){
			for (auto iter = iterator_->begin(); iter != iterator_->end(); ++iter){
				if (strcmp(iter.name().c_str(), atrybut) == 0){
					return std::make_shared<ParserAtrybutJSON>(iter, iterator_->end());
				}
			}
		}
		return nullptr;
	}

	std::shared_ptr<ParserAtrybut> ParserElementJSON::tworzAtrybut(const char* atrybut, const char* wartosc){
		if (iterator_ != end_ && iterator_->isArray() || iterator_->isObject()){
			(*iterator_)[atrybut] = wartosc;
			return pobierzAtrybut(atrybut);
		}
		return nullptr;
	}

	bool ParserElementJSON::usunAtrybut(const char* atrybut){
		if (iterator_ != end_)
			return false;
		iterator_->removeMember(atrybut);
		return true;
	}

	ParserElementJSON::operator bool()const{
		return iterator_ != end_;
	}

	std::shared_ptr<ParserElement> ParserElementJSON::pobierzElement(const char* element){
		if (iterator_ != end_ && iterator_->isArray() || iterator_->isObject()){
			for (auto iter = iterator_->begin(); iter != iterator_->end(); ++iter){
				if (strcmp(iter.name().c_str(), element) == 0){
					return std::make_shared<ParserElementJSON>(iter, iterator_->end());
				}
			}
		}
		return nullptr;
	}

	std::shared_ptr<ParserElement> ParserElementJSON::pobierzNastepnyElement(const char* element) const {
		if (iterator_ != end_){
			auto iter = iterator_;
			++iter;
			if (iter != end_){
				return std::make_shared<ParserElementJSON>(iter, end_);
			}
		}
		return nullptr;
	}
	std::shared_ptr<ParserElement> ParserElementJSON::tworzElement(const char* element){
		if (iterator_ != end_ && iterator_->isArray() || iterator_->isObject()){
			(*iterator_)[element] = Json::objectValue;
			return pobierzElement(element);
		}
		return nullptr;
	}

	bool ParserElementJSON::usunElement(){
		return false;
	}

	std::string ParserElementJSON::error()const{
		if (iterator_ != end_){
			return error_;
		}
		else{
			return std::string("nullptr");
		}
	}

}
