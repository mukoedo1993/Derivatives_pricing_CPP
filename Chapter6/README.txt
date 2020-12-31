Benefits for using random number stream?
1: We want to be able to insulate the random number stream used by a particular simulation
from the rest of the program.
2: We can decorate it.
3:Using Low-discrepancy numbers(quasi-random numbers) instead.


sec6_2:
abstract base class:
As we want the possibility of having many random number generators to be able to add new ones
later on without recoding, we use an abstract base class to specify an interface.

