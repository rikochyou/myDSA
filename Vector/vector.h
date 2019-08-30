#pragma once
typedef int Rank;
#define DEFAULT_CAPACITY 10

template <typename T> class Vector
{
protected:
	Rank _size; int _capacity; T* _elem;
	void copyFrom(T const* A, Rank lo, Rank hi);
	void expand();
	void shrink();
	bool bubble(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank hi); //选取最大元素
	void selectionSort(Rank lo, Rank hi); //选择排序算法
	void merge(Rank lo, Rank mi, Rank hi); //归并算法
	void mergeSort(Rank lo, Rank hi); //归并排序算法
	Rank partition(Rank lo, Rank hi); //轴点构造算法
	void quickSort(Rank lo, Rank hi); //快速排序算法
	void heapSort(Rank lo, Rank hi); //堆排序


public:
	// 构造函数
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)//容量为c, 规模为s，所有元素初始为v
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}
	Vector(T const* A, Rank n) {
		copyFrom(A, 0, n);
	}
	Vector(T const* A, Rank lo, Rank hi) {
		copyFrom(A, lo, hi);
	}
	Vector(Vector<T> const& V) {
		copyFrom(V._elem, V._size);
	}
	Vector(Vector<T> const& V, Rank lo, Rank hi) {
		copyFrom(V._elem, lo, hi);
	}
	// 析构函数
	~Vector() { delete[] _elem };

	// 只读接口
	Rank size() const {
		return _size;
	}
	bool empty() const {
		return !_size;
	}
	int disorder() const;
	Rank find(T const& e) const { return find(e, 0, _size); }
	Rank find(T const& e, Rank lo, Rank hi) const;
	Rank search(T const& e) const {  // 有序向量整体查找
		return (0 >= _size) ? -1 : search(e, 0, _size);
	};
	Rank search(T const& e, Rank lo, Rank hi) const; // 有序向量区间查找

	// 可写访问接口
	T& operator[] (Rank r) const; // 重载下标操作符
	Vector<T> & operator=(Vector<T> const&);
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& e) { return insert(_size, e); }
	void sort(Rank lo, Rank hi);
	void sort() { sort(0, _size; }
	void unsort(Rank lo, Rank hi);
	void unsort() { unsort(0, _size); }
	int dedupliacte();
	int uniquify();
	void traverse(void(*)(T&));
	template <typename VST> void traverse(VST&);

};

#include "vector_implementation.h"