#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define LENGTH 10

// comment out following if want to see the difference in output when no move constructors / move assignment operators are defined
#define WITH_MOVE


class Dummy
{
public:
    Dummy() 
    {
        std::cout << "In Dummy(). this = " << (void*)this << std::endl;
    }

    Dummy(const Dummy& other) 
    {
        std::cout << "In Dummy(const Dummy&). this = " << (void*)this << std::endl;
    }

#ifdef WITH_MOVE
    Dummy(const Dummy&& other) 
    {
        std::cout << "In Dummy(const Dummy&&). this = " << (void*)this << std::endl;
    }
#endif

    Dummy& operator=(const Dummy& other)
    {
        std::cout << "In Dummy::operator=(const Dummy& other). this = " << (void*)this << std::endl;

        return *this;
    }

#ifdef WITH_MOVE
    Dummy& operator=(const Dummy&& other)
    {
        std::cout << "In Dummy::operator=(const Dummy&& other). this = " << (void*)this << std::endl;

        return *this;
    }
#endif

    ~Dummy()
    {
        std::cout << "In ~Dummy(). this = " << (void*)this << std::endl;
    }
};


class MemoryMoveBlock
{
public:
    explicit MemoryMoveBlock()
        : _data(new int[LENGTH])
        , _dummy("Test")
    {
        std::cout << "Created resource " << (void*)_data << std::endl;
        std::cout << "In MemoryMoveBlock(). this = " << (void*)this << " data = " << (void*) _data << "." << std::endl;
    }

    ~MemoryMoveBlock()
    {
        std::cout << "In ~MemoryMoveBlock(). this = " << (void*)this << " data = " << (void*) _data << "." << std::endl;

        if (_data != nullptr)
        {
            std::cout << "Deleting  resource " << (void*)_data << std::endl;
            delete[] _data;
        }
    }

    MemoryMoveBlock(const MemoryMoveBlock& other)
        : _data(new int[LENGTH])
        , _dummy(other._dummy)
    {
        std::cout << "Created resource " << (void*)_data << std::endl;
        std::cout << "In MemoryMoveBlock(const MemoryMoveBlock&). this = " << (void*)this << " data = " << (void*) _data << ". Copying resource." << std::endl;

        std::copy(other._data, other._data + LENGTH, _data);
    }

#ifdef WITH_MOVE
    MemoryMoveBlock(MemoryMoveBlock&& other)
        : _data(std::exchange(other._data, nullptr))              // explicit move of a member of non class type (note that std::exchange is c++14)
        , _dummy(std::move(other._dummy))              // explicit move of a member of class type
    {
        std::cout << "In MemoryBlock(MemoryBlock&&). this = " << (void*)this << " data = " << (void*) _data << ". Moved resource." << std::endl;
        std::cout << "After MemoryBlock(MemoryBlock&&). other = " << (void*)&other << " data = " << (void*)other._data <<  std::endl;
    }

    MemoryMoveBlock& operator=(MemoryMoveBlock&& other)
    {
        std::cout << "In operator=(MemoryMoveBlock&&). this = " << (void*)this << " data = " << (void*) _data << ". Moving resource." << std::endl;
        std::cout << "In operator=(MemoryMoveBlock&&). other = " << (void*)&other << " data = " << (void*)other._data <<  std::endl;

        if (this != &other) {
            std::cout << "Deleting  resource " << (void*)_data << std::endl;
            delete[] _data;

            _data = std::exchange(other._data, nullptr);
            _dummy = std::move(other._dummy);
        }

        std::cout << "After operator=(MemoryMoveBlock&&). this = " << (void*)this << " data = " << (void*) _data << std::endl;
        std::cout << "After operator=(MemoryMoveBlock&&). other = " << (void*)&other << " data = " << (void*)other._data <<  std::endl;
        return *this;
    }
#endif

    MemoryMoveBlock& operator=(const MemoryMoveBlock& other)
    {
        std::cout << "In operator=(const MemoryMoveBlock&). this = " << (void*)this << " data = " << (void*) _data << ". Copying resource." << std::endl;

        if (this != &other)
        {
            std::cout << "Deleting  resource " << (void*)_data << std::endl;
            delete[] _data;

            _data = new int[LENGTH];
            _dummy = other._dummy;
            std::cout << "Created resource " << (void*)_data << std::endl;
            std::copy(other._data, other._data + LENGTH, _data);
        }
        return *this;
    }

private:
    int* _data; // The non class resource.
    std::string _dummy; // The class resource
};


int main()
{
    // starting with simpler class so it is easier to read what happens
    {
        std::vector<Dummy> v;
        v.reserve(4); // avoid vector relocations which would produce additional move/copy constructor invocations

        std::cout << std::endl << "Pushing first item to vector" << std::endl;
        v.push_back(Dummy());

        std::cout << std::endl << "Pushing second item to vector" << std::endl;
        v.push_back(Dummy());

        std::cout << std::endl << "Inserting third item to vector at second position" << std::endl;
        v.insert(++v.begin(), Dummy());

        std::cout << std::endl << "Ending" << std::endl;
    }

    {
        std::vector<MemoryMoveBlock> v;
        v.reserve(4); // avoid vector relocations which would produce additional move/copy constructor invocations

        std::cout << std::endl << "Pushing first item to vector" << std::endl;
        v.push_back(MemoryMoveBlock());

        std::cout << std::endl << "Pushing second item to vector" << std::endl;
        v.push_back(MemoryMoveBlock());

        std::cout << std::endl << "Inserting third item to vector at second position" << std::endl;
        v.insert(++v.begin(), MemoryMoveBlock());

        std::cout << std::endl << "Ending" << std::endl;
    }

    return 0;
}

