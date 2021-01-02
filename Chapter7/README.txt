A few components already:
random number generators, parameter classes, pay-off classes, statistics gatherers and a wrapper template.

Our target: to develop a flexible Monte-Carlo pricer for exotic options which pay off at some future date according to the value
of spot on a finite number of dates. Work within a deterministic interest rate world, and assume the Black-Scholes model of stock price evolution.


Identify four distinct actions:
(i): the generation of the stock price path
(ii): the generation of cash-flows given a stock price path
(iii): the discounting and summing of cash-flows for a given path
(iv): the averaging of the prices over all the paths
