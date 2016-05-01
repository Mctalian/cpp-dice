#include "CircularLinkedList.hpp"
#include "gtest/gtest.h"

// Define a test fixture class template.
template <class T>
class CircularLinkedListTest : public testing::Test {
protected:
    // The ctor calls the factory function to create a prime table
    // implemented by T.
    CircularLinkedListTest<T>() : cll(new CircularLinkedList<T>()) {}

    virtual ~CircularLinkedListTest<T>() { delete cll; }

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

// Should track length
TYPED_TEST(CircularLinkedListTest, GetLength) {
    CircularLinkedList<TypeParam> cll;
    cll.append(3);

    ASSERT_EQ(cll.getLength(), 1);

    cll.append(2);

    ASSERT_EQ(cll.getLength(), 2);

    cll.append(1);

    ASSERT_EQ(cll.getLength(), 3);
}
