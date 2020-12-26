It's worth understanding how the compiler implements this. Rather than saying,
"hmm, what type is this object? Ah, it's a call so I'll use the call pay-off function,"
it adds extra data to each object of the class which specifies what function to use. In fact,
essentially what it stores is a function pointer. So virtual functions are really a fancy way of using
function pointers. In fact, if you run a program involving virtual function pointers through a debugger, and
examine through the watch window as the virtual function table. This virtual function table is a list of addresses
to be called for the virtual functions associated with the class. So if when running a program, a virtual function is encountered,
the table is looked up and execution jumps into the functions pointed to. Note that this operation takes a small amount of time so efficiency
fanatics dislike virtual functions as they cause a small decrease in execution speed. Note also that the amount of memory per object has also 
increased as the object now contains a lot of extra data.


virtual functions benefits: 
1:  they are syntactically a lot simpler.
2:  we get extra functionality. 




.........................
case 1: gives us a way to calculate put and call options price and export the results simultaneously. 
