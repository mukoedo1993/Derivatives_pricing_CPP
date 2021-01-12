
// Author: Dimitri Reiswich

class SimpleDiscountFactor2: public Observable, Observer{
private:
	DiscountFactor df_;
	Time mat_;
	Handle<SimpleYield> y_;
public:
	SimpleDiscountFactor2(const Handle<SimpleYield>& y, 
				Time& mat):y_(y),mat_(mat){
				// register yield as an observable!
				registerWith(y_);
				df_=exp(-(*y_)->getYield()*mat_);
	}
	void update(){
		// something has changed, recalculate yield
		df_=exp(-(*y_)->getYield()*mat_);
		notifyObservers();
	}
	Real getDiscount() const{
		return df_;
	}
};
