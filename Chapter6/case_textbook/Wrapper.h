#ifndef __ch6_statistics_gatherer__Wrapper__case1_
#define __ch6_statistics_gatherer__Wrapper__case1_

/*
 
 goal: memory handling for us, can copy inherited objects into base class objects
 
 - wrapper class contain a pointer to a single target object
 - own and point to
 - if copy the wrapper object, the pointed-to object is also copied
 - when wrapper object exits, the pointed-to object is deleted as well
 - overloading =, ->, *
 - *mywrapper: obtain the unbderlying object
 - mywrapper -> ... : obtain the method in undering object
 
 */


// specify class T later
// eg. Wrapper<MCStatistics> TheStatsGatherer;
template <class T>

class Wrapper
{
public:
    Wrapper():DataPtr(nullptr)
    {

    } // the default constructor which point to nothing
    Wrapper(const T& inner) // constructor
    {
        DataPtr = inner.clone();
    }
    ~Wrapper()
    {
        if (DataPtr != 0) // if DataPtr Point to some memory, release it
        {
            delete DataPtr;
        }
    }
    
    Wrapper(const Wrapper<T>& original) // constructor when pass in a Wrapper class
    {
        if (original.DataPtr != nullptr)
            DataPtr = original.DataPtr -> clone();
        else
            DataPtr = nullptr;
    }
    
    // return by reference to avoid unnecessary copy
    Wrapper& operator= (const Wrapper<T>& oringinal)// overloading "="
    {
        if (this != &oringinal)
        {
            if (DataPtr!= nullptr)
            {
                delete DataPtr;
                DataPtr = (oringinal.DataPtr != nullptr)? oringinal.DataPtr.clone():nullptr;
            }
            
        }
        return  *this; // return what this point to
    }
    
    // two version of dereferencing operator *
    // dereference both const and non-const objects
    T& operator*() // overloading "*" to get object from pointer
    {
        return *DataPtr;
    }
    
    const T& operator*() const // return a const object
    {
        return *DataPtr;
    }
    
    // overloading "->" to access method within pointed object
    const T*  operator ->() const
    {
        return DataPtr;
    }
    
    T* operator ->()
    {
        return DataPtr;
    }
    
    
private:
    T* DataPtr;
};
#endif