#ifndef _NODE_H_
#define _NODE_H_

template <class KEY, class DATA>
class Node
{
protected:
	KEY k;
	DATA val;
public:
	KEY GetKey();
	DATA GetData();
	void SetKey(KEY k_);
	void SetVal(DATA val_);
	bool isuse = false;
	bool operator==(Node<KEY, DATA>&);
	bool operator!=(Node<KEY, DATA>&);
	Node<KEY, DATA> operator=(Node<KEY, DATA>& r);
};

template <class KEY, class DATA>
KEY Node<KEY, DATA>::GetKey()
{
	return k;
}
template <class KEY, class DATA>
DATA Node<KEY, DATA>::GetData()
{
	return val;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetKey(KEY k_)
{
	k = k_;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetVal(DATA val_)
{
	val = val_;
}

template<class KEY, class DATA>
bool Node<KEY, DATA>::operator==(Node<KEY, DATA> &r)
{
	return k == r.k;
}

template<class KEY, class DATA>
bool Node<KEY, DATA>::operator!=(Node<KEY, DATA> &r)
{
	return k != r.k;
}

template<class KEY, class DATA>
Node<KEY, DATA> Node<KEY, DATA>::operator=(Node<KEY, DATA>& r)
{
	k = r.k;
	val = r.k;
	return *this;
}

#endif //_NODE_H_