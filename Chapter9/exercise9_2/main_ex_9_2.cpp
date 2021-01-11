#include"trapezium_rule.h"
#include"f.h"
#include<iostream>
int main()
{
   double start =0;
   double end=2;
   ex9_2 ob1;
   std::cout<<trapezium_rule<ex9_2,&ex9_2::f>(start,end,10U,ob1);
}