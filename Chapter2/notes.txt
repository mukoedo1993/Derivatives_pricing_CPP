2.2 privacy:
The reason is that as soon we let the user access the data directly, it is much harder for us to change
how the class works. We can think of the class as a contract between coder and user. We, the coder, have provided the

Thus by making the data private, we can enforce the contract between the coder and user in such a way that the contract
does not say anything about the interior working of the class.

To conclude, by using private data we can rework the interior workings of a class and when we need to without working about
the impact on other code. The private data helps us to separate interface and implementations.




2.5 The Open-closed principle:
The previous section's discussion leads naturally to a programming idea known as the open-closed principle. The open refers to
the idea that code should always be opened for extension. So, In this particular case, we should always be able to add extra payoffs.
The 'closed' means that the file is 'closed for modification'. This refers to the idea that we should be able to do the extension without
modifying any existing code, and we should be able to do so without even changing anything in  any of the existing files.

function ptr? .....
