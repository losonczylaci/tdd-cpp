#include <gtest/gtest.h>
#include <memory>
#include <utility>

using namespace std;

// segmentation fault
// TEST(smartPointerGroup, uniquePointer) {
//     int* ptr;
//     *ptr = 100;
//     unique_ptr<int> uptr(ptr);
//     EXPECT_EQ(*uptr, 100);
// }

TEST(smartPointerGroup, uniquePointerNew) {
    unique_ptr<int> uptr(new int(100));
    EXPECT_EQ(*uptr, 100);
    EXPECT_NE(uptr, nullptr);
    EXPECT_NE(uptr.get(), nullptr);
}

TEST(smartPointerGroup, uniquePointerRelease) {
    unique_ptr<int> uptr(new int(100));
    int* a = uptr.release();
    EXPECT_EQ(uptr, nullptr);
    EXPECT_NE(a, nullptr);
}

TEST(smartPointerGroup, uniquePointerReset) {
    unique_ptr<int> uptr(new int(100));
    uptr.reset(new int(200));
    EXPECT_NE(uptr, nullptr);

    uptr.reset();
    EXPECT_EQ(uptr, nullptr);
}

TEST(smartPointerGroup, uniquePointerSwap) {
    unique_ptr<int> uptr1(new int(1));
    unique_ptr<int> uptr2(new int(2));
    EXPECT_EQ(*uptr1, 1);
    EXPECT_EQ(*uptr2, 2);

    uptr1.swap(uptr2);
    EXPECT_EQ(*uptr1, 2);
    EXPECT_EQ(*uptr2, 1);
}

TEST(smartPointerGroup, uniquePointerMove) {
    unique_ptr<int> uptr1(new int(1));
    unique_ptr<int> uptr2(new int(2));
    EXPECT_NE(uptr1, nullptr);
    EXPECT_NE(uptr2, nullptr);

    uptr1 = move(uptr2);
    EXPECT_EQ(uptr2, nullptr);
    EXPECT_EQ(*uptr1, 2);
}

TEST(smartPointerGroup, sharedPointer) {
    shared_ptr<int> sptr(new int(100));
    EXPECT_NE(sptr, nullptr);
    EXPECT_NE(sptr.get(), nullptr);
    EXPECT_EQ(*sptr, 100);
    EXPECT_EQ(sptr.unique(), true);
    EXPECT_EQ(sptr.use_count(), 1);
}

TEST(smartPointerGroup, sharedPointerUseCount) {
    shared_ptr<int> sptr(new int(100));
    auto sptrCopy = sptr;
    EXPECT_EQ(sptr.unique(), false);
    EXPECT_EQ(sptr.use_count(), 2);
}

TEST(smartPointerGroup, sharedPointerReset) {
    shared_ptr<int> sptr(new int(100));
    auto sptrCopy = sptr;
    sptr.reset();
    EXPECT_EQ(sptr, nullptr);
    EXPECT_NE(sptrCopy, nullptr);
}

TEST(smartPointerGroup, sharedPointerSwap) {
    shared_ptr<int> sptr1(new int(1));
    shared_ptr<int> sptr2(new int(2));
    EXPECT_EQ(*sptr1, 1);
    EXPECT_EQ(*sptr2, 2);
    sptr1.swap(sptr2);
    EXPECT_EQ(*sptr2, 1);
    EXPECT_EQ(*sptr1, 2);
}

void deleter(const int* o) {
    // do other things
    delete o;
}

TEST(smartPointerGroup, sharePointerCustomDeleter) {
    shared_ptr<int> sptr(new int(100), deleter);
}

TEST(smartPointerGroup, sharedPointerWeak) {
    shared_ptr<int> sptr(new int(100));
    weak_ptr<int> wptr = sptr;
    EXPECT_EQ(sptr.use_count(), 1);

    auto tsptr = wptr.lock();
    EXPECT_EQ(*tsptr, 100);
    EXPECT_EQ(sptr.use_count(), 2);

    tsptr.reset();
    EXPECT_EQ(sptr.use_count(), 1);
}
