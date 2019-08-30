#pragma once
template <typename T> void Vector <T> ::expand() {
	// 检查是否需要扩容
	//是否满员，是否低于最小容量
	if (_size < _capacity) return;
	if (_size < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
	// 扩容
	// 申请新空间
	T* oldElem = _elem; 
	_elem = new T[_capacity <<= 1];
	// 复制
	for (int i = 0; i < _size; i++) {
		_elem[i] = oldElem[i];
	}
	// 释放原空间
	delete[] oldElem;
	
	
}