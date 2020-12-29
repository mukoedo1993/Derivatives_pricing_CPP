Our Monte Carlo routine is now easily extensible to handle any pay-off and time-dependent parameters.
However, there are plenty of valid criticisms that could still be made. One thing that is definitely lacking
is the absence of any indication of the simulation's convergence. We could make the routine return standard error,
or convergence table, or simply have it return the value for every single path and analyze the results elsewhere.

.....Strategy pattern................
As we are trying to develop an object-oriented routine, we make the statistics gatherer an input. Thus the Monte  Carlo routine
will take in a statistics gatherer object, store the results in it and the statistics gatherer will then output the statistics as
required. This technique of using an auxiliary class to decide how part of an algorithm is implemented is sometimes called the strategy pattern.



