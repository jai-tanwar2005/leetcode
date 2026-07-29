class Tweet {
public:
    int id;
    int time;
    Tweet* next;

    Tweet(int time, int id) {
        this->time = time;
        this->id = id;
        next = nullptr;
    }
};

class User {
public:
    int id;
    unordered_set<int> following;
    Tweet* tweetHead;

    User(int id) {
        this->id = id;
        tweetHead = nullptr;
        follow(id); // Follow yourself
    }

    void follow(int userId) {
        following.insert(userId);
    }

    void unfollow(int userId) {
        if (userId != id)
            following.erase(userId);
    }

    void addTweet(Tweet* tweet) {
        tweet->next = tweetHead;
        tweetHead = tweet;
    }
};

struct Compare {
    bool operator()(Tweet* a, Tweet* b) {
        return a->time < b->time; // Max Heap
    }
};

class Twitter {
private:
    unordered_map<int, User*> userMap;
    int timeCounter;

public:
    Twitter() {
        timeCounter = 0;
    }

    void postTweet(int userId, int tweetId) {
        timeCounter++;

        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = new User(userId);
        }

        userMap[userId]->addTweet(new Tweet(timeCounter, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        if (userMap.find(userId) == userMap.end())
            return ans;

        priority_queue<Tweet*, vector<Tweet*>, Compare> pq;

        User* user = userMap[userId];

        for (int followee : user->following) {
            if (userMap.find(followee) != userMap.end()) {
                Tweet* head = userMap[followee]->tweetHead;
                if (head)
                    pq.push(head);
            }
        }

        while (!pq.empty() && ans.size() < 10) {
            Tweet* curr = pq.top();
            pq.pop();

            ans.push_back(curr->id);

            if (curr->next)
                pq.push(curr->next);
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end())
            userMap[followerId] = new User(followerId);

        if (userMap.find(followeeId) == userMap.end())
            userMap[followeeId] = new User(followeeId);

        userMap[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end())
            return;

        userMap[followerId]->unfollow(followeeId);
    }
};



/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */