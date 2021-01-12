
// Author: Dimitri Reiswich
class MakeMyOption{
public:

	MakeMyOption(): mat_(Null<Real>()),vol_(Null<Real>()),spot_(Null<Real>()),
					strike_(Null<Real>()),forRate_(Null<Real>()), 
					domRate_(Null<Real>()),type_(MyOption::None){
	}
	MakeMyOption& withMat(const double& mat){
		mat_=mat;
		return *this;
	}
	MakeMyOption& withVol(const double& vol){
		vol_=vol;
		return *this;
	}
	MakeMyOption& withSpot(const double& spot){
		spot_=spot;
		return *this;
	}
	MakeMyOption& withStrike(const double& strike){
		strike_=strike;
		return *this;
	}
	MakeMyOption& withForRate(const double& forRate){
		forRate_=forRate;
		return *this;
	}
	MakeMyOption& withDomRate(const double& domRate){
		domRate_=domRate;
		return *this;
	}
	MakeMyOption& withType(const MyOption::Type& type){
		type_=type;
		return *this;
	}
	operator MyOption()const{
		QL_REQUIRE(mat_!=Null<Real>(),"Maturity not set!");
		// Check other parameters too
		QL_REQUIRE(type_!=MyOption::None,"Option type not set!");
		return MyOption(mat_,vol_,type_,spot_,forRate_,domRate_,strike_);
	}

	Time getMat()const{return mat_;}
	Real getSpot()const{return spot_;}
	Real getStrike()const{return strike_;}
	
private:
	Time mat_; 
	Volatility vol_;
	Real spot_,strike_;
	Rate forRate_,domRate_;
	MyOption::Type type_;
};
