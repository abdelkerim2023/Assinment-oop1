#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    T *m_array;
    int m_size;

public:
    Array();
    Array(int size);
    Array(const Array &rhs);
    ~Array();
    int size();
    T &operator[](int index);
    Array &operator=(const Array &rhs);
};

template <typename T>
Array<T>::Array()
{
    m_array = new T[0];
    m_size = 0;
}
template <typename T>
Array<T>::Array(int size)
{
    m_array = new T[size];
    m_size = size;
}

template <typename T>
Array<T>::Array(const Array &rhs)
{
    m_size = rhs.m_size;
    m_array = new T[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_array[i] = rhs.m_array[i];
    }
}
template <typename T>
Array<T>::~Array()
{
    delete[] m_array;
}

template <typename T>
int Array<T>::size()
{
    return m_size;
}

template <typename T>
T &Array<T>::operator[](int k)
{
    if (k < 0 || k >= m_size)

    {
        std::cout << "Index out of bounds" << std::endl;
        exit(1);
    }
    return m_array[k];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
    if (this != &rhs)
    {
        delete[] m_array;
        m_size = rhs.m_size;
        m_array = new T[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = rhs.m_array[i];
        }
    }
    return *this;
}

main()
{
    Array<std::string> sArr(10);
    sArr[0] = "Hello";
    sArr[1] = "World";

    Array<std::string> arr(sArr);
    std::cout << arr[0] << " " << arr[1] << std::endl;
    arr = sArr;
    std::cout << arr[0] << " " << arr[1] << std::endl;

    Array<int> iArr(10);
    iArr[0] = 1;
    std::cout << iArr.size();

    
}
