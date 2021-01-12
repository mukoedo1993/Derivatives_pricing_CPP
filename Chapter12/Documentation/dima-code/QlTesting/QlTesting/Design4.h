
// Author: Dimitri Reiswich
class SimpleYield: public Observable{
private:
	Rate yield_;
public:
	SimpleYield(const Rate& yield):yield_(yield){
	}
	Rate getYield() const{return yield_;}
	
	void setYield(const Rate& yield){
		yield_=yield;
		// yield has changed, notify observers!
		notifyObservers();
	}
};
class SimpleDiscountFactor: public Observable, Observer{
private:
	DiscountFactor df_;
	Time mat_;
	boost::shared_ptr<SimpleYield> y_;
public:
	SimpleDiscountFactor(const boost::shared_ptr<SimpleYield>& y, 
				Time& mat):y_(y),mat_(mat){
				// register yield as an observable!
				registerWith(y_);
				df_=exp(-y_->getYield()*mat_);
	}
	void update(){
		// something has changed, recalculate yield
		df_=exp(-y_->getYield()*mat_);
		notifyObservers();
	}
	Real getDiscount() const{
		return df_;
	}
};
