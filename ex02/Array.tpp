#include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(0)
{
	//std::cout << "Default constructor" << std::endl;
	this->_array = NULL;
}
template<typename T>
Array<T>::Array(int size) : _size(size)
{
	//std::cout << "Constructor with parameter" << std::endl;
	if (this->_size < 0)
		throw (Array<T>::IndexOutOfRangeExcept());
	this->_array = new T[this->_size];
}
template<typename T>
Array<T>::Array(const Array &src) : _size(src._size)
{
	//std::cout << "Copy Constructor" << std::endl;
	this->_array = NULL;
	if (this->_size > 0)
		*this = src;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const &rhs)
{
	//std::cout << "Assignation operator" << std::endl;
	if (this->_array)
		delete this->_array;
	this->_size = rhs._size;
	this->_array = new T[this->_size];
	copyArray(rhs);
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	//std::cout << "Destructor" << std::endl;
	if (this->_array)
		delete this->_array;
}

template<typename T>
void Array<T>::copyArray(Array<T> const &src)
{
	int	i = 0;

	while (i < this->_size)
	{
		this->_array[i] = src._array[i];
		i++;
	}
}
template<typename T>
const char *Array<T>::IndexOutOfRangeExcept::what() const throw ()
{
	return ("Index out of range!");
}

template<typename T>
T & Array<T>::operator[](int i)
{
	if (i < 0 || i >= this->_size)
		throw (Array<T>::IndexOutOfRangeExcept());
	return (this->_array[i]);
}

template<typename T>
T *Array<T>::getArray(void) const
{
	return (this->_array);
}

template<typename T>
size_t Array<T>::size(void) const
{
	return (this->_size);
}

template<typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &src)
{
	size_t	len = src.size();
	T 		*arr = src.getArray();

	for (int i = 0; i < len; i++)
		o << arr[i] << std::endl;
	return (o);
}
