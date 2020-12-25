2.2 privacy:
The reason is that as soon we let the user access the data directly, it is much harder for us to change
how the class works. We can think of the class as a contract between coder and user. We, the coder, have provided the

Thus by making the data private, we can enforce the contract between the coder and user in such a way that the contract
does not say anything about the interior working of the class.

To conclude, by using private data we can rework the interior workings of a class and when we need to without working about
the impact on other code. The private data helps us to separate interface and implementations.
