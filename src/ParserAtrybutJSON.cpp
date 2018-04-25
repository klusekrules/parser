#include "ParserAtrybutJSON.h"
#include "WyjatekParser.h"
#include <string>

namespace SPar{

	ParserAtrybutJSON::ParserAtrybutJSON(Json::ValueIterator iterator, Json::ValueIterator end)
		: iterator_(iterator), end_(end)
	{
	}

	std::shared_ptr<ParserAtrybut> ParserAtrybutJSON::pobierzNastepnyAtrybut() const{
		if (iterator_ != end_){
			auto iter = iterator_;
			++iter;
			if (iter != end_)
				return std::make_shared<ParserAtrybutJSON>(iter, end_);
		}
		return nullptr;
	}

	bool ParserAtrybutJSON::ustawNazwe(const char*){
		return false;
	}

	const char* ParserAtrybutJSON::pobierzNazwe() const{
		if (iterator_!=end_)
			return iterator_.name().c_str();
		return nullptr;
	}

	bool ParserAtrybutJSON::ustawWartosc(const char* wartosc){
		if (iterator_ != end_){
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	const char* ParserAtrybutJSON::pobierzWartosc() const{
		if (iterator_ != end_)
			return iterator_->asCString();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::ustawWartoscBool(bool wartosc) const{
		if (iterator_ != end_) {
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::pobierzWartoscBool() const{
		if (iterator_ != end_)
			return iterator_->asBool();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscBool(bool & wartosc) const{
		if (iterator_ != end_ && iterator_->isConvertibleTo(Json::booleanValue)) {
			wartosc = iterator_->asBool();
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::ustawWartoscInt(int wartosc){
		if (iterator_ != end_){
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	int ParserAtrybutJSON::pobierzWartoscInt() const{
		if (iterator_ != end_)
			return iterator_->asInt();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscInt(int & wartosc) const{
		if (iterator_ != end_ && iterator_->isConvertibleTo(Json::intValue)) {
			wartosc = iterator_->asInt();
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::ustawWartoscUnsignedInt(unsigned int wartosc){
		if (iterator_ != end_){
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	unsigned int ParserAtrybutJSON::pobierzWartoscUnsignedInt() const{
		if (iterator_ != end_)
			return iterator_->asUInt();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscUnsignedInt(unsigned int & wartosc) const {
		if (iterator_ != end_ && iterator_->isConvertibleTo(Json::uintValue)) {
			wartosc = iterator_->asUInt();
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::ustawWartoscLongLong(long long wartosc){
		if (iterator_ != end_){
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	long long ParserAtrybutJSON::pobierzWartoscLongLong() const{
		if (iterator_ != end_)
			return iterator_->asInt64();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscLongLong(long long & wartosc) const {
		if (iterator_ != end_ && iterator_->isInt64()) {
			wartosc = iterator_->asInt64();
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::ustawWartoscUnsignedLongLong(unsigned long long wartosc){
		if (iterator_ != end_){
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	unsigned long long ParserAtrybutJSON::pobierzWartoscUnsignedLongLong() const{
		if (iterator_ != end_)
			return iterator_->asUInt64();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscUnsignedLongLong(unsigned long long & wartosc) const {
		if (iterator_ != end_ && iterator_->isUInt64()) {
			wartosc = iterator_->asUInt64();
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::ustawWartoscFloat(float wartosc){
		if (iterator_ != end_){
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	float ParserAtrybutJSON::pobierzWartoscFloat() const{
		if (iterator_ != end_)
			return iterator_->asFloat();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscFloat(float & wartosc) const {
		if (iterator_ != end_ && iterator_->isConvertibleTo(Json::realValue)) {
			wartosc = iterator_->asFloat();
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::ustawWartoscDouble(double wartosc){
		if (iterator_ != end_){
			*iterator_ = wartosc;
			return true;
		}
		return false;
	}

	double ParserAtrybutJSON::pobierzWartoscDouble() const{
		if (iterator_ != end_)
			return iterator_->asDouble();
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscDouble(double & wartosc) const {
		if (iterator_ != end_ && iterator_->isConvertibleTo(Json::realValue)) {
			wartosc = iterator_->asDouble();
			return true;
		}
		return false;
	}

	bool ParserAtrybutJSON::ustawWartoscLongDouble(long double wartosc){
		if (iterator_ != end_){
			*iterator_ = std::to_string(wartosc);
			return true;
		}
		return false;
	}

	long double ParserAtrybutJSON::pobierzWartoscLongDouble() const{
		if (iterator_ != end_) {
			return std::stold(iterator_->asString());
		}
		throw WyjatekParser(EXCEPTION_PLACE, std::string(), this, STyp::Tekst(" => iterator_ == end_"));
	}

	bool ParserAtrybutJSON::pobierzWartoscLongDouble(long double & wartosc) const {
		if (iterator_ != end_ && iterator_->isConvertibleTo(Json::stringValue)) {
			wartosc = std::stold(iterator_->asString());
			return true;
		}
		return false;
	}

	ParserAtrybutJSON::operator bool()const{
		return iterator_ != end_;
	}

	std::string ParserAtrybutJSON::error()const{
		if (iterator_ != end_){
			return error_;
		}
		else{
			return std::string("nullptr");
		}
	}

}