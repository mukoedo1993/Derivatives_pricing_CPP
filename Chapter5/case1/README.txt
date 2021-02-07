I replaced the shared_ptr with unique_ptr in some cases, if we do not need to use copy constuctor or move constructor of
the unique_ptr.
