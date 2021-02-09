#ifndef WRAPPER_H
#define WRAPPER_H


template<class T>
class Wrapper
{
    public: 
    Wrapper()
    {
        DataPtr = nullptr;
    }
    Wrapper(const T& inner)
    {
        DataPtr = inner.clone();
    }

    Wrapper(T* DataPtr_)
    {
        DataPtr = DataPtr_;
    }
    ~Wrapper()
    {
        if(DataPtr!=nullptr)
            delete DataPtr;
    }

    Wrapper(const Wrapper<T>& original)
    {
        if(original.DataPtr !=nullptr)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr =nullptr;
    }

    Wrapper<T>& operator=(const Wrapper<T>& original)
    {
        if(this != &original)
        {
            T* newPtr =(original.DataPtr!=nullptr)?
                original.DataPtr->clone():nullptr;

            if(DataPtr!=nullptr)
            delete DataPtr;

            DataPtr =newPtr;
        }
        return *this;
    }

    T& operator*()
    {
        return *DataPtr;
    }

    const T& operator*()const
    {
        return *DataPtr;
    }

    const T* const operator->()const
    {
        return DataPtr;
    }

    T* operator->()
    {
        return DataPtr;
    }

private:
    T* DataPtr;
};

#endif