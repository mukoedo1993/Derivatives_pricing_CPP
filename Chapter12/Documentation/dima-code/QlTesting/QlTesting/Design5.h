
// Author: Dimitri Reiswich

class SimpleDiscountedCF:public Observer{
private:
	boost::shared_ptr<SimpleDiscountFactor> df_;
	Real discountedUnit_;
public:
	SimpleDiscountedCF(const boost::shared_ptr<SimpleDiscountFactor>& df):df_(df){
			discountedUnit_=df_->getDiscount();
			registerWith(df_);
	}
	void update(){
		// something has changed, recalculate discount factor
		discountedUnit_=df_->getDiscount();
	}
	Real discountCashFlow(const Real& amount) const{
		return discountedUnit_*amount;
	}
};
