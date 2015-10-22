#pragma once
template <class T>
class MyClass
{
public:
	MyClass(void);
	~MyClass(void);
	T Add(T& a,T& b)const;
};

template <class T>
MyClass<T>::~MyClass( void )
{

}

template <class T>
MyClass<T>::MyClass( void )
{

}

template <class T>
T MyClass<T>::Add( T& a,T& b ) const
{
	T c=a+b;
	return c;
}

