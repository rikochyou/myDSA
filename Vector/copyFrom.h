#pragma once
template <typename T>
void Vector<T> ::copyFrom(T const* A,Rank lo, Rank hi){
	// 申请2倍容量的新空间
	_elem = new T[_capacity = 2 * (hi - lo)];
	// 规模重置
	_size = 0;
	// 逐一复制元素
	while(lo<hi){
		_elem[_size++] = A[lo++];
	}
	
}