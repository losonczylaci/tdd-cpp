#include <gtest/gtest.h>
#include <memory>
#include <utility>

// segmentation fault
// TEST(smartPointerGroup, uniquePointer) {
//     int* ptr;
//     *ptr = 100;
//     std::unique_ptr<int> uptr(ptr);
//     EXPECT_EQ(*uptr, 100);
// }

TEST(smartPointerGroup, uniquePointerNew) {
    std::unique_ptr<int> uptr(new int(100));
    EXPECT_EQ(*uptr, 100);
    EXPECT_NE(uptr, nullptr);
    EXPECT_NE(uptr.get(), nullptr);
}

TEST(smartPointerGroup, uniquePointerRelease) {
    std::unique_ptr<int> uptr(new int(100));
    int* a = uptr.release();
    EXPECT_EQ(uptr, nullptr);
    EXPECT_NE(a, nullptr);
}

TEST(smartPointerGroup, uniquePointerReset) {
    std::unique_ptr<int> uptr(new int(100));
    uptr.reset(new int(200));
    EXPECT_NE(uptr, nullptr);

    uptr.reset();
    EXPECT_EQ(uptr, nullptr);
}

TEST(smartPointerGroup, uniquePointerSwap) {
    std::unique_ptr<int> uptr1(new int(1));
    std::unique_ptr<int> uptr2(new int(2));
    EXPECT_EQ(*uptr1, 1);
    EXPECT_EQ(*uptr2, 2);

    uptr1.swap(uptr2);
    EXPECT_EQ(*uptr1, 2);
    EXPECT_EQ(*uptr2, 1);
}

TEST(smartPointerGroup, uniquePointerMove) {
    std::unique_ptr<int> uptr1(new int(1));
    std::unique_ptr<int> uptr2(new int(2));
    EXPECT_NE(uptr1, nullptr);
    EXPECT_NE(uptr2, nullptr);

    uptr1 = std::move(uptr2);
    EXPECT_EQ(uptr2, nullptr);
    EXPECT_EQ(*uptr1, 2);
}
