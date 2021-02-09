See the textbook_case directory for more details.


Our Monte Carlo routine is now easily extensible to handle any pay-off and time-dependent parameters.
However, there are plenty of valid criticisms that could still be made. One thing that is definitely lacking
is the absence of any indication of the simulation's convergence. We could make the routine return standard error,
or convergence table, or simply have it return the value for every single path and analyze the results elsewhere.

.....Strategy pattern................
As we are trying to develop an object-oriented routine, we make the statistics gatherer an input. Thus the Monte  Carlo routine
will take in a statistics gatherer object, store the results in it and the statistics gatherer will then output the statistics as
required. This technique of using an auxiliary class to decide how part of an algorithm is implemented is sometimes called the strategy pattern.

What should the routine do? It must have two principal methods. The first should take in data for each path. The second must output the desired
statistics.
Since we do not wish to specify what sort of statistics are being gathered in advance, we proceed via an abstract base class using virtual methods,
just aw we did for the PayOff and Parameters classes. However, as most of the time we will not need to copy these objects we do not bother with the
bridge but work with the base class by reference.



