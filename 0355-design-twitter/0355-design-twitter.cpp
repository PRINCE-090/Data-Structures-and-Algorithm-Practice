class Twitter {
    private:
    struct Tweet{
        int tweetId;
        int time;
        Tweet* next;

        Tweet(int id,int t,Tweet *n = nullptr){
            tweetId  = id;
            time = t;
            next = n;
        }
    };
    int timer = 0;
    unordered_map<int, Tweet*>userTweets;
    unordered_map<int,unordered_set<int>>following;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId] = new Tweet(tweetId,timer++,userTweets[userId]);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,Tweet*>>pq;
        if(userTweets.count(userId)){
            Tweet*tweet = userTweets[userId];
            pq.push({tweet->time,tweet});
        }
        for(int followeeId : following[userId]){
            if(userTweets.count(followeeId)){
                Tweet* tweet = userTweets[followeeId];
                pq.push({tweet->time,tweet});
            }
        }
        vector<int>feed;
        while(!pq.empty() && feed.size() < 10){
            auto[time,tweets] = pq.top();
            pq.pop();
            feed.push_back(tweets->tweetId);

            if(tweets->next){
                pq.push({tweets->next->time,tweets->next});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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