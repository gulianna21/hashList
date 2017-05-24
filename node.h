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

#endif //_NODE_H_