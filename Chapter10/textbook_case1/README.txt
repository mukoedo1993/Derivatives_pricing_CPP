In the chapter 10, we present a solution that allows us to add new
pay-offs without changing any of the existing files. We simply add new
files to the project. Our solution is a design pattern known as the 
FACTORY DESIGN. It is so called because it can be used to manufature objects. 
Whilst we restrict attention to a simple factory which manufactures pay-offs, the basic
pattern can be sed in much wider contexts.


THus if the registration function contains a static variable which is the factory, then
on the first call to the registration function the factory comes into existence. Recall that
a static variable defined in a function persists from one call to the enxt, and only disappears when
the program exits. So all the registration function calls will register the pay-off blueprints
with the same factory.

However, we are not yet done because the creator function will need to have access to the same
factory object as the registration function, and if the factory is hidden inside the registration function will
not be possible. 

The solution to the problem is known as the singleton pattern.

The singleton pattern gives a way of creating a class with these properties. The first thing
is that all constructors and assignment operators are made private. This means that factories can 
only be created from inside methods of the class this gives us firm control over the existence of 
factory objects.


//https://stackoverflow.com/questions/16498969/how-do-i-typedef-a-function-pointer-with-the-c11-using-syntax
