class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for (auto &interval: intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int min_room = 0, room = 0;
        int s = 0, e = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                room += 1;
                s += 1;
                min_room = max(min_room, room);
            } else {
                room -= 1;
                e += 1;
            }
        }
        return min_room;
    }
};
