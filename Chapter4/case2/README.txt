What do we really want to do? We want the vanilla option to store its own copy of the pay-off. However, we do not want the vanilla
option to know the type of the pay-off object nor anything about any of its inherited classes for all the reasons we discussed in the last
chapter. Our solution there was to use virtual functions: how can we use them here? Well the object knows its own type so it can certainly make
a copy of itself.


Derived-to-base conversion(pointer)
