If we not declare the copy constructor then the compiler will perform a shallow copy as opposed to a deep copy.
A shallow copy means that data members have simply been copied, whilst this is adequate when no memory allocation is 
required it will lead to disaster when it does. If we have shallow copied a VanillaOption then both copies of the object we have 
pointed to will have the same effect in each copy. Whilst for our particular object this is not really an issue as we do not want to change it, in
a more complicated class this would certainly lead to trouble.

More seriously, when the one of the two VanillaOption objects goes out of scope, then its destructore will be called and the pointed-to PayOff object
will be deleted. The object remaining will now be in trouble as attempts to use its pointer will lead to methods of a non-existent object being called. On
top of which when the remaining object goes out of scope, the destructor will be called and there will be a second attempt to delete the pointed-to object. 
As the object has already been deleted, this will generally result in a crash.
