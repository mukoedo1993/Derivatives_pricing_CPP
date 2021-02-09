(1): The path generator asks the product what times it needs spot for, and it passes back an array.
See: PathDependent::PossibleCashFlowTimes() const = 0;

(2): The accounting part of the engine asks the product what cash-flow times are possible, and it passes back an array.
The engine then computes all the possible discount factors.

(3): The accounting part of the engine asks the product the maximum number of cash flows it can generate, and sets up a vector
of that size.

(4): For each path, the engine gets an array of spot values from the path generator.

(5): The array of spot values is passed into the product, which passes back the number of cash-flows, and puts their values into the vector.

(6): The cash-flows are discounted appropriately and summed, and the total value is passed into the statistics gatherer.

(7): After all the looping is done, the final results are obtained from the statistics gatherer.
