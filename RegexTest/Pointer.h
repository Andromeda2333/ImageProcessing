#pragma once
template<typename T>
//ָ��ģ��
class Pointer
{
public:
	Pointer(T* inPtr);
	virtual ~Pointer();

	//���� *,const�ͷ�const����
	T& operator*();
	const T& operator*()const;

	//���� ->,const�ͷ�const����
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
