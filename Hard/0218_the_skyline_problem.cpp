class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }

        sort(events.begin(), events.end());

        multiset<int> heights = {0};
        vector<vector<int>> result;
        int prevMax = 0;

        for (const auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                heights.insert(-h);
            } else {
                auto it = heights.find(h);
                if (it != heights.end()) {
                    heights.erase(it);
                }
            }

            int currMax = *heights.rbegin();

            if (currMax != prevMax) {
                result.push_back({x, currMax});
                prevMax = currMax;
            }
        }

        return result;
    }
};
