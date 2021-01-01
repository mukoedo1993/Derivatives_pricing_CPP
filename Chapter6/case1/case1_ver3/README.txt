See ver1 and ver2 for more details.

ver3_: 

I updated some files. I optimized these files within my capability. 

PayOffBridge's assignment should keep alarm at any possible nullptr managed by unique_ptrs.

Because, according to the implementation of the class PayOffBridge, we shouldn't face it. If it happens, there is absolutely an error.

The default constructor just doesn't exist, so every object of this class should have a unique_ptr which is NOT a nullptr.
So, I added a throw statement if terrible things like that happen.
