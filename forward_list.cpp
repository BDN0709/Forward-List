template <class _Ty> 
class List
{
public:

	List();
	~List();

	void push_back(const _Ty data);

	void push_front(const _Ty data);

	void insert(const _Ty data, const int index);

	int size() const { return Size; }

	_Ty& operator [] (const int index);

	void pop_back();

	void pop_front();

	void removeAt(const int index);

	void clear();

private:

	template <class _Ty>
	class Node
	{
	public:
		Node* pNext;
		_Ty data;

		Node(_Ty data = _Ty(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node <_Ty>* head;

	int Size;
};

template <class _Ty>
List <_Ty>::List()
{
	Size = 0;
	head = nullptr;
}

template <class _Ty>
List <_Ty>::~List()
{
	clear();
}

template <class _Ty>
void List<_Ty>::push_back(const _Ty data)
{
	if (head == nullptr)
		head = new Node <_Ty>(data);
	else
	{
		Node <_Ty>* current = this->head;

		while (current->pNext != nullptr)
			current = current->pNext;

		current->pNext = new Node <_Ty>(data);

	}

	Size++;

	return;
}

template<class _Ty>
void List<_Ty>::push_front(const _Ty data)
{
	head = new Node <_Ty>(data, head);

	Size++;

	return;
}

template<class _Ty>
void List<_Ty>::insert(const _Ty data, const int index)
{
	if (!index)
		push_front(data);
	else if (index == Size)
		push_back(data);
	else
	{
		Node <_Ty>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		previous->pNext = new Node<_Ty>(data, previous->pNext);
		
		Size++;
	}

	return;
}

template <class _Ty>
_Ty& List <_Ty>::operator[](const int index)
{
	unsigned int counter = 0;

	Node <_Ty>* current = this->head;

	while (current->pNext != nullptr)
	{
		if (counter == index)
			return current->data;

		current = current->pNext;

		counter++;
	}

	return current->data;
}

template<class _Ty>
void List<_Ty>::pop_back()
{
	removeAt(Size - 1);

	return;
}

template<class _Ty>
void List<_Ty>::pop_front()
{
	Node <_Ty>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

	return;
}

template<class _Ty>
void List<_Ty>::removeAt(const int index)
{
	if (!index)
		pop_front();
	else
	{

		Node <_Ty>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		Node <_Ty>* current = previous->pNext;

		previous->pNext = current->pNext;

		delete current;

		Size--;
	}

	return;
}

template<class _Ty>
void List<_Ty>::clear()
{
	while (Size)
		pop_front();

	return;
}