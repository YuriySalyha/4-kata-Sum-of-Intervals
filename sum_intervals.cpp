#include <vector>
#include <utility>
#include <string>
int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals.size() < i || intervals.size() == 1) {
            break;
        }
        for (int j = 0; j < intervals.size(); j++) {
            if (intervals.size() == 1) {
                break;
                //return intervals[0].second - intervals[0].first;
            }
            if (j == i) {
                continue;
            }
            if (intervals.size() < j) {
                break;
            }
            if (intervals[j].first < intervals[i].second && ((intervals[j].first > intervals[i].first || intervals[j].first == intervals[i].first) || (intervals[j].second > intervals[i].first))) {
                int indexForDelete;
                if (intervals[j].second > intervals[i].second) {
                    intervals[i].second = intervals[j].second;
                }
                else {
                    intervals[j].second = intervals[i].second;
                }
                if (intervals[j].first > intervals[i].first) {
                    indexForDelete = j;
                }
                else {
                    indexForDelete = i;
                }
                intervals.erase(intervals.begin() + indexForDelete);
                j--;

            }
        }
    }
    int result = 0;
    for (int i = 0; i < intervals.size(); i++) {
        result += intervals[i].second - intervals[i].first;
    }
    return result;
}
