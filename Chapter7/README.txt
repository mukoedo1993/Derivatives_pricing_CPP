A few components already:
random number generators, parameter classes, pay-off classes, statistics gatherers and a wrapper template.

Our target: to develop a flexible Monte-Carlo pricer for exotic options which pay off at some future date according to the value
of spot on a finite number of dates. Work within a deterministic interest rate world, and assume the Black-Scholes model of stock price evolution.


Identify four distinct actions:
(i): the generation of the stock price path
(ii): the generation of cash-flows given a stock price path
(iii): the discounting and summing of cash-flows for a given path
(iv): the averaging of the prices over all the paths

We still have to decide the syntax for the main method CashFlows. The method takes in an array defining spot values, 
and return cash-flows. 

......
So, in summary our objects will communicate as follows:
(i): The path generator asks the product what times it needs spot for, and it passes back an array

(ii): The accounting part of the engine asks the product what cash-flow times are possible, and it passes back an array. The engine then 
computes all the possible discount factors.

(iii): The accounting part of the engine asks the product the maximum number of cash flows it can generate, and sets up a vector
of that size.

(iv): For each path, the engine gets an array of spot values from the path generator.

(v): The array of spot values is passed into the product, which passes back the number of cash-flows, and puts their values into 
the vector.

(vi): The cash-flows are discounted appropriately and summed, and the total value is passed into the statistics gatherer.

(vii): After all the looping is done, the final results are obtained from the statistics gatherer.
