Question:
Modify the code so that it will work under variable volatility. The key is to ensure that the integral of
the square of the vol across each time step is the same. This means that the time steps will be of uneuqal length.



Tips:
  In previous questions, we need to make time step a constant. i.e.: Tn-Tn-1 =Tn-1-Tn-2.
  But now, we need to make the squareIntegral of time a constant, i.e.: Tn^2 -Tn-1^2= Tn-1^2 -Tn-2^2
  
  
