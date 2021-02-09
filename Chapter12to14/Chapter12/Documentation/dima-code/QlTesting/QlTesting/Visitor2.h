
// Author: Dimitri Reiswich

 //template <class Type> class NullNew {
  

template <class RateType> class MyDiscounter : public Visitor<RateType>{

private:
	Real time_;
	RateType rate_;
	DiscountFactor df_;

public:
	
	MyDiscounter(const Real& time, const RateType& rate)
							:time_(time),rate_(rate){
	}

	Real getDiscount(){
		rate_.accept(*this);
		return df_;
	}

	void visit(MySimpleRate& rate){
		df_=1/(1+rate.rate()*time_);
	}

	void visit(MyContinuousRate& rate){
		df_=std::exp(-rate.rate()*time_);
	}
};