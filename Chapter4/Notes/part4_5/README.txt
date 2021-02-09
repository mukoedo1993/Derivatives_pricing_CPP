What we would really like is a pay-off class that has the nice polymorphic features
that our class does, whilst taking care of its own memory management. There are a couple of
approaches to solving this problem. One is to use a wrapper class that has been templatized:
this is really generic programming rather than object-oriented programming, and we explore this approach
in Section 5.4. Suppose we take the vanilla option class and get rid of the member Expiry and the method 
GetExpiry. We then are left with a class does nothing except store a pointer to an option pay-off and takes care
of memory handling. This is precisely what we want.
