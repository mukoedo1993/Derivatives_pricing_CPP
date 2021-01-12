
// Author: Dimitri Reiswich

	class MySimpleRate{
	private:
		Rate rate_;
	public:
		MySimpleRate(const Real& rate):rate_(rate){}
		Rate rate() const{return rate_;}	
		void accept(Visitor<MySimpleRate>& v) {
			Visitor<MySimpleRate>* v1 = dynamic_cast<Visitor<MySimpleRate>*>(&v);
			if (v1 != 0)
				v1->visit(*this);
		}
	};

	
	class MyContinuousRate{
	private:
		Rate rate_;
	public:
		MyContinuousRate(const Real& rate):rate_(rate){}
		Rate rate() const{return rate_;}			
		void accept(Visitor<MyContinuousRate>& v) {
			Visitor<MyContinuousRate>* v1 = dynamic_cast<Visitor<MyContinuousRate>*>(&v);
			if (v1 != 0)
				v1->visit(*this);
		}
	};