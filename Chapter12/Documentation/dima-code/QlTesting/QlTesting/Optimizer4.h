
// Author: Dimitri Reiswich

class CallProblemFunction: public CostFunction{	
private:
	
	Real C1_,C2_,C3_,C4_,K1_,K2_,K3_,K4_;
	Rate rd_,rf_;
	Integer phi_;
	Time tau_;
public:
CallProblemFunction(const Rate& rd, const Rate& rf, const Time& tau, const Integer& phi,
					const Real& K1,const Real& K2,const Real& K3,const Real& K4,
					const Real& C1,const Real& C2,const Real& C3,const Real& C4)
					:rd_(rd), rf_(rf), phi_(phi), tau_(tau),
					C1_(C1),C2_(C2),C3_(C3),C4_(C4),
					K1_(K1),K2_(K2),K3_(K3),K4_(K4){}

	Real value(const Array& x) const{

		Array tmpRes=values(x);
		Real res=tmpRes[0]*tmpRes[0];
		res+=tmpRes[1]*tmpRes[1];
		res+=tmpRes[2]*tmpRes[2];
		res+=tmpRes[3]*tmpRes[3];
		return res;
	}

	Disposable<Array> values(const Array& x) const{

			Array res(4); 
			res[0]=blackScholesPrice(x[0],K1_,rd_,rf_,x[1],tau_,phi_)-C1_;
			res[1]=blackScholesPrice(x[0],K2_,rd_,rf_,x[1],tau_,phi_)-C2_;
			res[2]=blackScholesPrice(x[0],K3_,rd_,rf_,x[1],tau_,phi_)-C3_;
			res[3]=blackScholesPrice(x[0],K4_,rd_,rf_,x[1],tau_,phi_)-C4_;

			return res;
	}
};