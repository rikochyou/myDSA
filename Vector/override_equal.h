#pragma once
template <typename T> Vector<T>& Vector<T> :: operator=(Vector<T> const& V) {
	// �ͷ�
	if (_elem) delet[] _elem;
	// ����
	copyFrom(V._elem, 0, V.size());
	// ��������
	return *this;
}