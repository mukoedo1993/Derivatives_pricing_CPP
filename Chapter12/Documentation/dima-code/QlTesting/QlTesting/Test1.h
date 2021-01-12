
// Author: Dimitri Reiswich
#include<limits>
#include <boost/static_assert.hpp>

  template <class Type> class NullNew {
      
  public:
        
		NullNew() {}

		operator Type() const { 
			BOOST_STATIC_ASSERT(std::numeric_limits<Type>::has_quiet_NaN);
			return std::numeric_limits<Type>::quiet_NaN(); 
		}

		bool operator==(const NullNew<Type>&) {
			return true;
		}
  };

  class Foo{
	private:
	  Real var_;
	public:
		Foo():var_(10.0){}

		bool operator==(const Foo& rhs) {
			return var_==rhs.var_;
		}
  };