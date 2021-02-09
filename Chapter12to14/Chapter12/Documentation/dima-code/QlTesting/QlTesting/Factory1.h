
// Author: Dimitri Reiswich
class MyOption{
public:
	enum Type{Call=1,Put=-1,None=0};
	
	MyOption(Time mat, Volatility vol, Type type, Real spot,
		Rate forRate, Rate domRate, Real strike):mat_(mat),vol_(vol),
		type_(type),spot_(spot),forRate_(forRate),domRate_(domRate),
		strike_(strike){
	}

	Time getMat()const{return mat_;}
	Real getSpot()const{return spot_;}
	Real getStrike()const{return strike_;}
	
private:
	Time mat_; Volatility vol_;
	Real spot_,strike_;
	Rate forRate_,domRate_;
	Type type_;
};
