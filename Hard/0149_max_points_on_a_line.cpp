class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int answer = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> slopes;
            int duplicates = 1;
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                long long dx = (long long)points[j][0] - points[i][0];
                long long dy = (long long)points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                long long g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                }

                long long key = (dx << 32) ^ (dy & 0xffffffffLL);
                slopes[key]++;
                best = max(best, slopes[key]);
            }

            answer = max(answer, best + duplicates);
        }

        return answer;
    }
};
