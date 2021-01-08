There are, in fact, many different ways to tackle this problem. We method we have already studied is the engine templates. 
With this approach, we define a base class for which the main method is to carry out the bisection. The main method calls a pure 
virtual method to get the value of f(x). For any specific problem, we then define an inherited class which implements f appropriately. Whilist this method can 
work effectively, there are a couple of disadvantages.
