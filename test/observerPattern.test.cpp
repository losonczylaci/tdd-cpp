#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Subscriber {
   public:
    virtual ~Subscriber() = default;
    virtual void update() = 0;
};

class SubscriberMock : public Subscriber {
   public:
    MOCK_METHOD(void, update, (), (override));
};

class Publisher {
    vector<Subscriber*> subscribers;

   public:
    void subscribe(Subscriber& s) {
        subscribers.push_back(&s);
    }

    void unsubscribe(Subscriber& s) {
        auto it = find(subscribers.begin(), subscribers.end(), &s);
        subscribers.erase(it);
    }

    void notifySubscribers() {
        for (auto subscriber : subscribers) {
            if (subscriber != nullptr) {
                subscriber->update();
            }
        }
    }
};

class observerGroup : public ::testing::Test {
   protected:
    Publisher p;
    SubscriberMock s1;
    SubscriberMock s2;
};

TEST_F(observerGroup, shouldHandleMultipleSubscribes) {
    p.subscribe(s1);
    p.subscribe(s2);
    EXPECT_CALL(s1, update()).Times(1);
    EXPECT_CALL(s2, update()).Times(1);
    p.notifySubscribers();
}

TEST_F(observerGroup, shouldHandleUnsubscribe) {
    p.subscribe(s1);
    p.subscribe(s2);
    p.unsubscribe(s2);
    EXPECT_CALL(s1, update()).Times(1);
    EXPECT_CALL(s2, update()).Times(0);
    p.notifySubscribers();
}
