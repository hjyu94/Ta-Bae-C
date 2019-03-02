#include "13.2 MyArray.h" // ��� �� ����.

template<typename T>
inline int MyArray<T>::getLength()
{
	return m_length;
}

// cpp ���Ϸ� �Լ��� ���Ǹ� ���� ���� ���
// ���ø� ��� ����


// explicit instantiation

template void MyArray<char>::print();
// print��� �Լ��� char type�� ���� instantiation �ϰڴ�!
template void MyArray<int>::print();
template void MyArray<double>::print();
template void MyArray<float>::print();

template class MyArray<char>;
template class MyArray<int>;
template class MyArray<double>;
template class MyArray<float>;
// class ��ü�� Ư�� Ÿ�Կ� ���� instantiation ���ټ��� �ִ�.
