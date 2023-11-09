#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
class vertix {
public:
    T d;
    vertix* next;
    vertix() : next(NULL) {}
    vertix(T value, vertix* ptr = NULL) : d(value), next(ptr){};
};

template<class T>
class list
{
    vertix<T>* h; // represent head of list
    vertix<T>* t; // represent the tail of th list
public:
    list() {
        h = t = nullptr; //def constructor
    }
    // pramet constructor get the size only from the user
    list(int Size)
    {
        vertix<T>* ptr = new vertix<T>;
        ptr->next = NULL;
        h = ptr;
        t = ptr;
        ptr = nullptr;
        for (size_t i{ 0 }; i < Size - 1; ++i)
        {
            vertix<T>* ptr = new vertix<T>;
            ptr->next = NULL;
            h = ptr;
            t = ptr;
            ptr = nullptr;
        }
    }
    // pramet construcor get the size of list and the values of it's index
    list(int Size, T val)
    {
        vertix<T>* ptr = new vertix<T>;
        ptr->d = val;
        ptr->next = NULL;
        h = ptr;
        t = ptr;
        ptr = nullptr;
        for (size_t i{ 0 }; i < Size - 1; ++i)
        {
            vertix<T>* ptr = new vertix<T>;
            ptr->d = val;
            ptr->next = NULL;
            h = ptr;
            t = ptr;
            ptr = nullptr;
        }
    }
    list<T>& operator = (list<T> another_list){
        if( this == &another_list )
            return *this;
        iterator itr =another_list.begin( );
        this->push_back(*itr);
        do{
            ++itr;
            this->push_back(*itr);
        }while(itr != another_list.end());
        return *this;
    }

    // iterator class
    class iterator {
        friend class list;
    public:
        vertix<T>* vit; // current vertix iterator
        vertix<T>* hit; // represent head iterator;
        iterator()
        {
            vit = hit = nullptr;
        }

        iterator (vertix < T >* head)
        {
            vit = hit = head;
        }

        iterator(vertix<T>* ptrv, vertix<T>* head)
        {
            vit = ptrv;
            vit = vit->next;
            hit = head;

        }
        // prefix increment operator (++iterator)
        void operator++()
        {
            try{
                if(vit->next== nullptr)
                {
                    throw exception();
                }
                else
                {
                    vit = vit->next;
                }
            }
            catch (exception e)
            {
                cout << "Out of the range!";
            }
        }
        // postfix increment operator (iterator++)
        void operator++(int increment)
        {
            try{
                if(vit->next== nullptr)
                {
                    throw exception();
                }
                else
                {
                    vit = vit->next;
                }
            }
            catch (exception e)
            {
                cout << "\nOut of the range!\n";

            }
        }
        // postfix decrement operator(--iterator)
        void operator--()
        {
            list<T> ::iterator it;
            it.vit = this->hit;
            it.hit = this->hit;
            if (this->hit == this->vit)
            {
                cout << endl << "Not in the range\n";
                return;
            }
            while (it.vit->next != nullptr)
            {
                if (it.vit->next == this->vit)
                {
                    this->vit = it.vit;
                    return;
                }
                ++it;
            }
        }
        // postfix decrement operator (iterator--)
        void operator--(int decremaent)
        {
            list<T> ::iterator it;
            it.vit = this->hit;
            it.hit = this->hit;
            if (this->hit == this->vit)
            {
                cout << endl << "Not in the range\n";
                return;
            }
            while (it.vit->next != nullptr)
            {
                if (it.vit->next == this->vit)
                {
                    this->vit = it.vit;
                    return;
                }
                ++it;
            }
        }

        T& operator*()const
        {
            return vit->d;
        }
        bool operator==(const iterator& it) const
        {
            return vit == it.vit;
        }
        bool operator!=(const iterator& it) const
        {
            return vit != it.vit;
        }
    };

    iterator erase(iterator pos)
    {
        vertix<T>* pop = pos.vit->next;
        pos.vit->next = pos.vit->next->next;
        if (pop == t) t = pos.vit;
        delete pop;
        return pos;
    }
    void push_back(T val)
    {
        vertix<T>* ptr = new vertix<T>;
        ptr->d = val;
        ptr->next = nullptr;
        if (h == nullptr)
        {
            h = t = ptr;
            ptr = nullptr;
            return;
        }
        t->next = ptr;
        t = ptr;
    }

    void insert(T val, int pos)
    {
        vertix<T>* prev = new vertix<T>, * curr = new vertix<T>, * ptr = new vertix<T>;
        curr = h;
        for (size_t i{ 1 }; i < pos; ++i)
            prev = curr, curr = curr->next;
        ptr->d = val;
        prev->next = ptr;
        ptr->next = curr;
    }

    // create function to insert element in the front in the list
    void push_front(T val)
    {
        vertix < T >* ptr = new vertix< T >;
        ptr->d = val;
        ptr->next = h;
        h = ptr;
    }

    // create function to delete from the front of the list
    void pop_front()
    {
        vertix < T >* ptr = new vertix< T >;
        ptr = h;
        h = h->next;
        delete ptr;
    }
    // create function to insert at posision
    void push_at(T value, int pos)
    {
        vertix < T >* prev = new vertix < T >;
        vertix < T >* curr = new vertix < T >;
        vertix < T >* ptr = new vertix < T >;
        curr = h;
        for(size_t i{1}; i < pos; ++i)
            prev = curr , curr = curr->next;
        ptr->d = value;
        prev-> next = ptr;
        ptr->next = curr;
    }

    // create function to delete position
    void pop_from(int pos)
    {
        vertix < T >* curr = new vertix < T >;
        vertix < T >* prev = new vertix < T >;
        curr = h;
        for(size_t i{1};i < pos; ++i)
            prev = curr, curr = curr->next;
        prev->next = curr->next;
    }
    // display the list
    void print()
    {
        vertix<T>* ptr = new vertix<T>;
        ptr = h;
        while (ptr != nullptr)
        {
            cout << ptr->d << ' ';
            ptr = ptr->next;
        }
        cout << '\n';
    }

    int size()
    {
        int sz = 0;
        vertix<T>* ptr = new vertix<T>;
        ptr = h;
        while (ptr != nullptr)
        {
            sz += 1;
            ptr = ptr->next;
        }
        return sz;
    }

    iterator begin() const  {
        return iterator(h);
    }

    iterator end() const {
        return iterator (t,h);
    }
    void pop_back()
    {
        vertix < T >* curr = new vertix< T >;
        vertix < T >* prev = new vertix < T >;
        curr = h;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        t = prev;
        prev->next = nullptr;
        delete curr;
    }
    ~list()
    {
        do
        {
            pop_back();
        }while (h != t);
        delete h, delete t;
    }
};
int main()
{
    // create list
    list<int> myList;
    // push (insert) some values to list
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    // print the size of the list
    cout << "size of the list: " <<  myList.size() << '\n';
    myList.insert(5,2);
    cout << "insert value 5 at positon 2: ";myList.print();
    myList.pop_from(2);
    cout << "Delete value in position 2: ";
    myList.print();
    myList.push_front(7);
    cout << "insert value 7 at the front of list: ";
    myList.print();
    cout << "Delete the last value in the list: ";
    myList.pop_back();
    myList.print();
    list < int > :: iterator it = myList.begin();
    cout << "The front of the list using iterator: " << *it << '\n';
    it++;
    cout << "Iterator after increment: " << *it << '\n';
    it++;
    it++; // out of the rage
    cout << "Iterator before decrement: " << *it << '\n';
    cout << "Iterator after decrement: "; it--; cout << *it;
    myList.print();
}


