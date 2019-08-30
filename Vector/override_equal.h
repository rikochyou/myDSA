#pragma once
template <typename T> Vector<T>& Vector<T> :: operator=(Vector<T> const& V) {
	// 释放
	if (_elem) delet[] _elem;
	// 复制
	copyFrom(V._elem, 0, V.size());
	// 返回引用
	return *this;
}