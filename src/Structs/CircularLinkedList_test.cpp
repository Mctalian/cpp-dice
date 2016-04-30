#include "CircularLinkedList.hpp"
#include "gtest/gtest.h"

// Then we define a test fixture class template.
template <class T>
class CircularLinkedListTest : public testing::Test {
protected:
    // The ctor calls the factory function to create a prime table
    // implemented by T.
    CircularLinkedListTest<T>() : cll(new CircularLinkedList<T>()) {}

    virtual ~CircularLinkedListTest<T>() { delete cll; }

    // Note that we test an implementation via the base interface
    // instead of the actual implementation class.  This is important
    // for keeping the tests close to the real world scenario, where the
    // implementation is invoked via the base interface.  It avoids
    // got-yas where the implementation class has a method that shadows
    // a method with the same name (but slightly different argument
    // types) in the base interface, for example.
    CircularLinkedList<T>* const cll;
};

typedef ::testing::Types<int> MyTypes;

// Tests CircularLinkedList.

TYPED_TEST_CASE(CircularLinkedListTest, MyTypes);

// Should Append a few values
TYPED_TEST(CircularLinkedListTest, AppendValues) {
    CircularLinkedList<TypeParam> cll;
    cll.append(3);
    cll.append(2);
    cll.append(1);

    Node<TypeParam>* current = cll.getHead();
    EXPECT_EQ(current->data, 3);

    current = current->next;
    EXPECT_EQ(current->data, 2);

    current = current->next;
    EXPECT_EQ(current->data, 1);

    current = current->next;
    EXPECT_EQ(current->data, 3);
}
