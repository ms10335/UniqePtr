#include <iostream>
#include <memory>

template <typename T>
class MyUniquePtr {
private:
    T* ptr_;

public:
    MyUniquePtr()
        : ptr_(nullptr) {}  //def constructor
    MyUniquePtr(T* ptr)
        : ptr_(ptr ? ptr : nullptr) {}

    //diable a copy constructor and operator= because it is a unique_ptr
    MyUniquePtr(const MyUniquePtr& ptr) = delete;
    MyUniquePtr& operator=(const MyUniquePtr& ptr) = delete;

    //destructor
    ~MyUniquePtr() { delete ptr_; }

    //move semantic
    MyUniquePtr(MyUniquePtr&& resource) {
        ptr_ = resource.ptr_;
        resource.ptr_ = nullptr;
    }
    MyUniquePtr& operator=(MyUniquePtr&& resource) {
        ptr_ = resource.ptr_;
        resource.ptr_ = nullptr;
    }
    // function
    T* get() {
        if (ptr_) {
            return ptr_;
        }
        return nullptr;
    }
    T* release() {
        if (ptr_) {
            T* tmp = ptr_.get();
            ptr_ = nullptr;
            return tmp;
        }
        return ptr_.get();
    }
    void reset();

    //operators overloads
    T* operator->() {
        return this->ptr_;
    }
    T& operator*() {
        return *(this->ptr_);
    }
};

int main() {
    MyUniquePtr<int> ptr1(new int{21});

    // MyUniquePtr<int>ptr2(ptr1); protect from copying

    std::unique_ptr<int> newTip = std::make_unique<int>(10);
    newTip.release();
    return 0;
}