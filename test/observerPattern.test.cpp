#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace pracitce1 {

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
}  // namespace pracitce1

namespace practice2 {

class Subscriber {
   public:
    virtual ~Subscriber() = default;
    virtual void update(string) = 0;
};

class YouTubeSubscriber : public Subscriber {
    string _username;
    stack<string> updates;

   public:
    YouTubeSubscriber(string username) {
        _username = username;
    }

    const string& getUserName() {
        return _username;
    }

    void update(string updateMessage) override {
        updates.push(updateMessage);
    }

    string getNewestUpdate() {
        return updates.top();
    }
};

class YouTubeChannel {
    vector<YouTubeSubscriber*> subscribers;

   public:
    void subscribe(YouTubeSubscriber& s) {
        subscribers.push_back(&s);
    }

    void unsubscribe(YouTubeSubscriber& s) {
        auto it = find(subscribers.begin(), subscribers.end(), &s);
        subscribers.erase(it);
    }

    void notifySubscribers(string message) {
        for (auto s : subscribers) {
            s->update(message);
        }
    }
    int subscriberCount() {
        return subscribers.size();
    }
};

TEST(ytGroup, canCreateYouTubeSubscriber) {
    YouTubeSubscriber subscriber("peter1991");
    EXPECT_EQ(subscriber.getUserName(), "peter1991");
    subscriber.update("new video available");
    EXPECT_EQ(subscriber.getNewestUpdate(), "new video available");
}

TEST(ytGroup, canSubscribeMultipleYouTubers) {
    YouTubeChannel channel;
    YouTubeSubscriber sub1("peter1991");
    YouTubeSubscriber sub2("jack01");

    channel.subscribe(sub1);
    channel.subscribe(sub2);
    EXPECT_EQ(channel.subscriberCount(), 2);

    channel.notifySubscribers("new vid avail..");
    EXPECT_EQ(sub1.getNewestUpdate(), "new vid avail..");
    EXPECT_EQ(sub2.getNewestUpdate(), "new vid avail..");

    channel.unsubscribe(sub2);
    channel.notifySubscribers("new vid2 avail..");
    EXPECT_EQ(channel.subscriberCount(), 1);
    EXPECT_EQ(sub1.getNewestUpdate(), "new vid2 avail..");
    EXPECT_EQ(sub2.getNewestUpdate(), "new vid avail..");
}

}  // namespace practice2
