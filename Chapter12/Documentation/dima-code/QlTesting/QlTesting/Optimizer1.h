
// Author: Dimitri Reiswich

class RosenBrockFunction: public CostFunction{
public:	
	Real value(const Array& x) const{
		QL_REQUIRE(x.size()==2,"Rosenbrock function is 2-dim.");
		Real res=(1-x[0])*(1-x[0]);
		res+=100.0*(x[1]-x[0]*x[0])*(x[1]-x[0]*x[0]);
		return res;
	}

	Disposable<Array> values(const Array& x) const{
		QL_REQUIRE(x.size()==2,"Rosenbrock function is 2-dim.");
		// irrelevant what you write in res for most of the optimizers
		// most of them are using value anyways. try with res[0]=100.0
		Array res(1); res[0]=value(x);
		return res;
	}
};
