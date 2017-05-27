#ifndef _HT_H_
#define _HT_H_

#include "node.h"
#include "LinkedList.h"

template <class KEY, class DATA>
class Table
{
protected:
	int size; //общий размер
	int count;//текущее число записей
	LinkedList<Node<KEY,DATA>>* mas; // данные
	int Hash(KEY K);
public:
Table(int size_ = 1); // конструктор
Table(Table& ht);
~Table();
Node<KEY,DATA>& operator[](KEY k_);
Table& operator=(Table& ht);
void Add(DATA val_,KEY k_);
void Del(KEY k_);
void resize(int newSize);
};


template <class KEY, class DATA>
Table<KEY, DATA>::Table(int size_)
{
	size = size_;
	count = 0;
	mas = new LinkedList<Node<KEY,DATA>>[size];
}

template <class KEY, class DATA>
Table<KEY, DATA>::Table(Table& ht)
{
	size=ht.size;
	count=ht.count;

	mas=new LinkedList<Node<KEY,DATA>>[ht.size];
	for(int i=0; i<ht.size;++i)
		mas[i]=ht.mas[i];
}

template <class KEY, class DATA>
Table<KEY, DATA>::~Table()
{
	delete[] mas;
	size=0;
	count=0;
}

template <class KEY, class DATA>
int Table<KEY, DATA>:: Hash(KEY K)
{
	return ((int)K)% size;

}
template <class KEY, class DATA>
Node<KEY,DATA>& Table<KEY, DATA>::operator[](KEY K)
{
	int index=Hash(K);
	Node<KEY, DATA> nod;
	nod.SetKey(K);
	if (!mas[index].contains(nod))
		throw 5;

	return mas[index].get(mas[index].indexOf(nod));
}

template<class KEY, class DATA>
Table<KEY,DATA> & Table<KEY, DATA>::operator=(Table & ht)
{
	size = ht.size;
	count = ht.count;
	p = ht.p;
	mas = new Node[ht.size];
	for (int i = 0; i<ht.size; ++i)
		mas[i] = ht.mas[i];
}

template <class KEY, class DATA>
void Table<KEY, DATA>::Add(DATA val_, KEY k_)
{
	int index=Hash(k_);

	Node<KEY, DATA> nod;
	nod.SetKey(k_);
	if (!mas[index].contains(nod))
	{
		Node<KEY, DATA> nod;
		nod.SetKey(k_);
		nod.SetVal(val_);
		mas[index].add(nod);
	}
	else
	{
		Node<KEY, DATA>* tmp = &mas[index].get(mas[index].indexOf(nod));
		tmp->SetVal(val_);
	}
}

template<class KEY, class DATA>
void Table<KEY, DATA>::Del(KEY k_)
{
	int index = Hash(k_);

	Node<KEY, DATA> nod;
	nod.SetKey(k_);
	if (mas[index].contains(nod))
	{
		mas[index].remove(mas[index].indexOf(nod));

	}
}

template<class KEY, class DATA>
void Table<KEY, DATA>::resize(int newSize)
{
	LinkedList<Node<KEY, DATA>>*tmp = mas;
	if (count > newSize)
		throw 112;
	mas = new LinkedList<Node<KEY, DATA>>[newSize];
	count = 0;
	int oldSize = size;
	size = newSize;
	for (int i = 0; i < oldSize; i++)
	{
		for(size_t x=0;x<tmp[i].size();x++)
			Add(tmp[i].get(x).GetData(), tmp[i].get(x).GetKey());
	}
	delete[] tmp;
}

#endif