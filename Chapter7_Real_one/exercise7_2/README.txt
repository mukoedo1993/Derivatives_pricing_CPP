Q: Write a class to do discrete knock-out options that pay a rebate at the time of knock out.

Tips: 
For the call option part:
I arrange the file in a way such that it will throw an exception as soon as the Barrier is lower than the spot value. (The trade will end immediately).
For the put option part:
if spot is lower than barrier, The program throw an excpetion.
