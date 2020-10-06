#include <cstddef>
#include <iostream>

namespace data_structures
{
    template <typename T>
    class Deque
    {

    public:
        Deque();
        ~Deque();
        bool IsEmpty() const;
        std::size_t Size() const;
        void AddFirst(T);
        void AddLast(T);
        T RemoveFirst();
        T RemoveLast();

    private:
        struct Node
        {
            T val;
            Node *next;
            Node *prev;
        };

        Node *head_;
        Node *tail_;
        std::size_t size_;
    }; // class Deque

    template <typename T>
    Deque<T>::Deque() : head_(nullptr), tail_(nullptr), size_(0)
    {
    }

    template <typename T>
    Deque<T>::~Deque()
    {
        while (!IsEmpty())
        {
            RemoveFirst();
        }
    }

    template <typename T>
    bool Deque<T>::IsEmpty() const
    {
        return head_ == nullptr;
    }

    template <typename T>
    std::size_t Deque<T>::Size() const
    {
        return size_;
    }

    template <typename T>
    void Deque<T>::AddFirst(T item)
    {
        Node *old_head = head_;
        Node *new_node = new Node();
        new_node->next = old_head;
        new_node->prev = nullptr;
        new_node->val = item;
        head_ = new_node;
        if (size_ > 0)
            old_head->prev = head_;
        else if (size_ == 0)
            tail_ = head_;
        size_++;
    }

    template <typename T>
    void Deque<T>::AddLast(T item)
    {
        Node *old_tail = tail_;
        Node *new_node = new Node();
        new_node->prev = old_tail;
        new_node->next = nullptr;
        new_node->val = item;
        tail_ = new_node;
        if (size_ > 0)
            old_tail->next = tail_;
        else if (size_ == 0)
            head_ = tail_;
        size_++;
    }

    template <typename T>
    T Deque<T>::RemoveFirst()
    {
        if (size_ == 0)
            throw std::runtime_error("no such element");

        Node *old_head = head_;
        T item = old_head->val;
        head_ = old_head->next;
        delete old_head;
        size_--;
        if (size_ > 0)
            head_->prev = nullptr;
        else if (size_ == 0)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        return item;
    }

    template <typename T>
    T Deque<T>::RemoveLast()
    {
        if (size_ == 0)
            throw std::runtime_error("no such element");

        Node *old_tail = tail_;
        T item = old_tail->val;
        tail_ = old_tail->prev;
        delete old_tail;
        size_--;
        if (size_ > 0)
            tail_->next = nullptr;
        else if (size_ == 0)
        {
            head_ = nullptr;
            tail_ = nullptr;
        }
        return item;
    }

} // namespace data_structures