#ifndef SEM2TASK3_LIST_H
#define SEM2TASK3_LIST_H

namespace Lessons {
    template<typename T>
    struct ListElement {
        T value;
        ListElement *next;

        ListElement() {
            this->value = 0;
            this->next = nullptr;
        }
    };

    template<typename T>
    class List {
    private:
        ListElement<T> *Head;
        ListElement<T> *End;

        ListElement<T> *Find(T value);

        ListElement<T> *FindPrevious(T value, bool last = false);

        int size{};

    public:
        List();

        ~List();

        void PushFront(T value);

        void PushBack(T value);

        void PushBefore(T next, T value);

        void PushAfter(T previous, T value);

        T PopFront();

        T PopBack();

        T PopCurrent(T value);

        int CountElementWithValue(T value);

        T operator[](int i);

        [[nodiscard]] inline int GetSize() const { return size; }
    };

    template<typename T>
    int List<T>::CountElementWithValue(T value) {
        int count = 0;
        for (ListElement<T> *tmpElement = Head; tmpElement != End->next; tmpElement = tmpElement->next) {
           if(tmpElement->value == value) count++;
        }
        return count;
    }

    template<typename T>
    List<T>::List() {
        this->Head = nullptr;
        this->End = Head;
        this->size = 0;
    }

    template<typename T>
    List<T>::~List() {

    }

    template<typename T>
    T List<T>::operator[](int i) {
        if (i >= size) {
            std::cout << "Index out of bound" << std::endl;
            return 0;
        }
        ListElement<T> *tmpElement = Head;
        for (int j = 0; j < i; ++j) {
            tmpElement = tmpElement->next;
        }

        return tmpElement->value;
    }

    template<typename T>
    ListElement<T> *List<T>::Find(T value) {
        ListElement<T> *returnElement = nullptr;
        for (ListElement<T> *tmpElement = Head; tmpElement != End->next; tmpElement = tmpElement->next) {
            if (tmpElement->value == value) {
                returnElement = tmpElement;
                return returnElement;
            }
        }
        if(returnElement == nullptr) std::cerr<<"Element not Found"<<std::endl;

        return returnElement;
    }

    template<typename T>
    ListElement<T> *List<T>::FindPrevious(T value, bool last) {
        ListElement<T> *returnElement = nullptr;
        for (ListElement<T> *tmpElement = Head; tmpElement->next != End->next; tmpElement = tmpElement->next) {
            if (tmpElement->next->value == value) {
                returnElement = tmpElement;
                if (!last) {
                    return returnElement;
                }
            }
        }

        return returnElement;
    }

    template<typename T>
    void List<T>::PushFront(T value) {
        this->size++;
        auto *tmpElement = new ListElement<T>();
        tmpElement->value = value;
        tmpElement->next = Head;
        this->Head = tmpElement;
        if(!End) End = Head;
    }

    template<typename T>
    void List<T>::PushBack(T value) {
        this->size++;
        auto *tmpElement = new ListElement<T>();
        tmpElement->value = value;
        tmpElement->next = nullptr;
        if(!Head){
            Head = tmpElement;
            End = Head;
            return;
        }
        this->End->next = tmpElement;
        this->End = tmpElement;
    }

    template<typename T>
    void List<T>::PushBefore(T next, T value) {
        auto *tmpElement = new ListElement<T>();
        tmpElement->value = value;
        tmpElement->next = Find(next);
        ListElement<T> *prevElement = FindPrevious(next);
        prevElement->next = tmpElement;
        this->size++;
    }

    template<typename T>
    void List<T>::PushAfter(T previous, T value) {
        auto *tmpElement = new ListElement<T>();
        tmpElement->value = value;
        tmpElement->next = Find(previous)->next;
        ListElement<T> *prevElement = Find(previous);
        prevElement->next = tmpElement;
        this->size++;
    }

    template<typename T>
    T List<T>::PopFront() {
        ListElement<T> *tmpElement = Head;
        this->Head = Head->next;
        T value = tmpElement->value;
        delete tmpElement;
        this->size--;
        return value;
    }

    template<typename T>
    T List<T>::PopBack() {
        ListElement<T> *tmpElement = End;
        this->End = FindPrevious(End->value, true);
        this->End->next = nullptr;
        T value = tmpElement->value;
        delete tmpElement;
        this->size--;
        return value;
    }

    template<typename T>
    T List<T>::PopCurrent(T value) {
        ListElement<T> *tmpElement = Find(value);
        ListElement<T> *prevElement = FindPrevious(value);
        prevElement->next = tmpElement->next;
        T retValue = tmpElement->value;
        delete tmpElement;
        this->size--;
        return retValue;
    }
}

#endif //SEM2TASK3_LIST_H
