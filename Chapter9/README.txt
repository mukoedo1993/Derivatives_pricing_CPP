There are, in fact, many different ways to tackle this problem. We method we have already studied is the engine templates. 
With this approach, we define a base class for which the main method is to carry out the bisection. The main method calls a pure 
virtual method to get the value of f(x). For any specific problem, we then define an inherited class which implements f appropriately. Whilist this method can 
work effectively, there are a couple of disadvantages.


1: The first is that the function call is virtual which can lead to efficiency problems. There are two causes: 1: the first is that to call a virtual function, the processor has to look up the table. 

2: A more subtle and serious speed issue is that it is not possible to inline virtual functions.

3: In addition, the compiler may be able to make additional optimizations as it sees all the code together at once.

4: The second disadvantage of inheriting from a solver base class is that it inhibits other inheritance. If we wish to inherit the class defining our function from some other class, we cannot inherit from the solver class as well without using multipler inheritance. Of course, one could use multiple inheritance but it tends to be tricky to gte it work in a bug-free fashion and I therefore tend to avoid it. 

5: Having decided that we want to be able to input a function to our routine without using virtual functons...

Using a function pointer ...
templatization: The crucial point is that...
with templaization the type of the function being used in the optimization is decided at compile time rather than at runtime. 

This means that the compiler can carry out optimizations and inlining that depende on the type of the function since that information is now available to it.


.......
