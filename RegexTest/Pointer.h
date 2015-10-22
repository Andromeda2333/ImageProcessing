#pragma once
template<typename T>
//指针模板
class Pointer
{
public:
	Pointer(T* inPtr);
	virtual ~Pointer();

	//重载 *,const和非const类型
	T& operator*();
	const T& operator*()const;

	//重载 ->,const和非const类型
	T* operator->();
	const T* operator->()const;
protected:
	T* mPtr;
private:
	Pointer(const Pointer<T>& src);
	Pointer<T>& operator =(const Pointer<T>& rhs);
};

template<typename T>
const T* Pointer<T>::operator->() const
{
	return mPtr;
}

template<typename T>
T* Pointer<T>::operator->()
{
	return mPtr;
}

template<typename T>
const T& Pointer<T>::operator*() const
{
	return *mPtr;
}

template<typename T>
T& Pointer<T>::operator*()
{
	return *mPtr;
}

template<typename T>
Pointer<T>& Pointer<T>::operator=(const Pointer<T>& rhs)
{
	mPtr = rhs.mPtr;
	return *this;
}

template<typename T>
Pointer<T>::Pointer(const Pointer<T>& src)
{
	this->mPtr = src.mPtr;
}

template<typename T>
Pointer<T>::~Pointer()
{
	delete mPtr;
	mPtr = nullptr;
}

template<typename T>
Pointer<T>::Pointer(T* inPtr)
{
	this->mPtr = inPtr;
}
