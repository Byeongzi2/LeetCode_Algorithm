#define nullarea 1600000001

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int vecSize = points.size();
        unordered_map<int, set<int>> hashMap;
        int minx, miny, maxx, maxy;
        long long ans = nullarea;

        for (const auto& nowPoint : points) {
            hashMap[nowPoint[0]].insert(nowPoint[1]);
        }


        for(int i=0; i<vecSize;i++) {
            for(int j=i; j<vecSize; j++) {
                minx=points[i][0];
                miny=points[i][1];
                maxx=points[j][0];
                maxy=points[j][1];

                if ((minx != maxx) && (miny != maxy)) {
                    if(hashMap[minx].count(maxy) && hashMap[maxx].count(miny)) {
                        long long areaSize = abs((maxx - minx) * (maxy-miny));
                        if(areaSize < ans) ans = areaSize;
                    }
                }
            }
        }

        if(ans == nullarea) return 0;
        else return ans;
    }
};