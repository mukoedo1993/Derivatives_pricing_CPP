template<class T, double(T::*Value)(double)const>
                double trapezium_rule(double Start,
                                        double End,
                                        unsigned numbers,
                                        const T& TheObject)
    {
         double size =(End-Start)/static_cast<double>(numbers);
         double sum=size*((TheObject.*Value)(Start)+(TheObject.*Value)(End))*0.5;
         for(unsigned i=1;i<numbers-1;++i)
         {
           sum+= size*(TheObject.*Value)(Start+i*size);
         }
            return sum;
    }