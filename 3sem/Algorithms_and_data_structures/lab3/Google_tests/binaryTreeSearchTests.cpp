#include "gtest/gtest.h"
#include "../headers/binaryTreeSearch/binaryTreeSearch.h"

class TestBinaryTreeSearch : public ::testing::Test {
protected:
    binaryTreeSearch<int> *treeOfInts;
public:
    TestBinaryTreeSearch() {
        this->treeOfInts = new binaryTreeSearch<int>;
    }
    ~TestBinaryTreeSearch() {
        delete this->treeOfInts;
    }

    void setUpNotEmptyTree(){
        treeOfInts->insert(10);
        treeOfInts->insert(8);
        treeOfInts->insert(13);
        treeOfInts->insert(5);
        treeOfInts->insert(12);
        treeOfInts->insert(17);
    }
    void setUpEmptyTree() { }
};

TEST_F(TestBinaryTreeSearch, insertInEmptyTree) {
    setUpEmptyTree();
    treeOfInts->insert(5);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, insertInNotEmptyTree1) {
    setUpNotEmptyTree();
    treeOfInts->insert(2);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),2);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, insertInNotEmptyTree2) {
    setUpNotEmptyTree();
    treeOfInts->insert(9);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),9);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, insertInNotEmptyTree3) {
    setUpNotEmptyTree();
    treeOfInts->insert(11);
    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),11);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, containsInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(treeOfInts->contains(5));
}

TEST_F(TestBinaryTreeSearch, containsInNotEmptyTree1) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(10));
    GTEST_ASSERT_EQ(treeOfInts->contains(10), true);
}

TEST_F(TestBinaryTreeSearch, containsInNotEmptyTree2) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(8));
    GTEST_ASSERT_EQ(treeOfInts->contains(8), true);
}

TEST_F(TestBinaryTreeSearch, containsInNotEmptyTree3) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(12));
    GTEST_ASSERT_EQ(treeOfInts->contains(12), true);
}

TEST_F(TestBinaryTreeSearch, containsBadInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->contains(100));
    GTEST_ASSERT_EQ(treeOfInts->contains(100), false);
}

TEST_F(TestBinaryTreeSearch, removeInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(treeOfInts->remove(10));
}

TEST_F(TestBinaryTreeSearch, removeHeadInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(10));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeWhen1ChildInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(8));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeWhen2ChildInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(13));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeTreeLeafInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(treeOfInts->remove(12));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, removeBadInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_ANY_THROW(treeOfInts->remove(7));

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, isEmptyInEmptyTree) {
    setUpEmptyTree();
    GTEST_ASSERT_EQ(treeOfInts->isEmpty(), true);
}

TEST_F(TestBinaryTreeSearch, isEmptyInNotEmptyTree) {
    setUpNotEmptyTree();
    GTEST_ASSERT_EQ(treeOfInts->isEmpty(), false);
}

TEST_F(TestBinaryTreeSearch, breadthIteratorInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator());
}

TEST_F(TestBinaryTreeSearch, breadthIteratorInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator());

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorBreadth = treeOfInts->create_bft_iterator();

    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorBreadth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorBreadth->hasNext(), false);
}

TEST_F(TestBinaryTreeSearch, depthIteratorInEmptyTree) {
    setUpEmptyTree();
    ASSERT_ANY_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorDepth = treeOfInts->create_dft_iterator());
}

TEST_F(TestBinaryTreeSearch, depthIteratorInNotEmptyTree) {
    setUpNotEmptyTree();

    ASSERT_NO_THROW(iterator<elemOfBinaryTreeSearch<int>> *treeIteratorDepth = treeOfInts->create_dft_iterator());

    iterator<elemOfBinaryTreeSearch<int>> *treeIteratorDepth = treeOfInts->create_dft_iterator();

    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),10);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),8);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),5);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),13);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),12);
    GTEST_ASSERT_EQ(treeIteratorDepth->next().getData(),17);

    GTEST_ASSERT_EQ(treeIteratorDepth->hasNext(), false);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}