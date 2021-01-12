
// Author: Dimitri Reiswich
class SimpleDiscountFactor1: public Observable, Observer{
private:
	DiscountFactor df_;
	Date evalDate_,matDate_;
	boost::shared_ptr<SimpleYield> y_;
	DayCounter dc_;
public:
	SimpleDiscountFactor1(const boost::shared_ptr<SimpleYield>& y, 
				const Date& matDate, const DayCounter& dc)
				:y_(y),matDate_(matDate),dc_(dc){
				// register yield as an observable!
				evalDate_=Settings::instance().evaluationDate();
				registerWith(y_);
				registerWith(Settings::instance().evaluationDate());
				df_=exp(-y_->getYield()*dc_.yearFraction(evalDate_,matDate_));
	}
	void update(){
		// something has changed, recalculate discount factor
		evalDate_=Settings::instance().evaluationDate();
		df_=exp(-y_->getYield()*dc_.yearFraction(evalDate_,matDate_));
		notifyObservers();
	}
	Real getDiscount() const{
		return df_;
	}
};