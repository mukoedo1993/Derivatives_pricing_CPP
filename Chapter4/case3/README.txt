bridge pattern: 
A class that owns a object member of the class bridge.
The bridge is a class that has a pointer to the implementation.
The bridge is accountable for dealing with implemenation's details.
While our interface class only has to deal with the bridge.

It save a lot of repititive code on our interface.


In the case3, we have a bridge class.
Our interface class includes an object of bridge class.
And our object of bridge class includes a pointer to a pure base class.
So, we just need to operate on bridge class(assignments) so that we do not need to speicialize too much details
on derived class at each time.
