#pragma once
template <typename T>
void Vector<T> ::copyFrom(T const* A,Rank lo, Rank hi){
	// ����2���������¿ռ�
	_elem = new T[_capacity = 2 * (hi - lo)];
	// ��ģ����
	_size = 0;
	// ��һ����Ԫ��
	while(lo<hi){
		_elem[_size++] = A[lo++];
	}
	
}