#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
    // sorting the vector based on their end points
    sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) -> bool {
        return a.end < b.end;
    });

    vector<int> points; // create a vector to store the common points in the segments
    int point = segments[0].end; // set the point to the first end point i-e shortest end point
    points.push_back(point);

    for (size_t i = 1; i < segments.size(); ++i) {
        if (point < segments[i].start || point > segments[i].end) { // if the point is not in the segment
            point = segments[i].end; // update the point to the end point of the current segment
            points.push_back(point); // store it in the vector
        }
    }

    return points;
}

// 从覆盖线段最高到最低依次排序，然后去掉最高的在进行判断，将其覆盖的点移除重新排序，思路可行，复杂度太高，弃
//bool safe_remove(vector<Segment> &segments, vector<int> &points) {
//    vector<bool> flags(segments.size(), false);
//    // if i-th segment contains at least 1 point, then flags.at(i) will be true
//
//    for (size_t i = 0; i < points.size(); ++i) {
//        for (size_t j = 0; j < segments.size(); ++j) {
//            if (points[i] >= segments[j].start && points[i] <= segments[j].end)
//                flags[j] = true;
//        }
//    }
//
//    for (size_t k = 0; k < segments.size(); ++k) {
//        // Check if every segment contains at least 1 point
//        if (flags[k]) continue;
//        return false;
//    }
//    return true;
//}
//
//vector<int> optimal_points(vector<Segment> &segments) {
//    vector<int> points;
//    vector<bool> flags(segments.size(), false);
//
//    for (size_t i = 0; i < segments.size(); ++i) {
//        points.push_back(segments[i].start);
//        points.push_back(segments[i].end);
//    }
//    vector<int> cand = points;
//    for (size_t i = 0; i < points.size(); ++i) {
//        for (size_t j = 0; j < segments.size(); ++j) {
//            if (points[i] >= segments[j].start && points[i] <= segments[j].end)
//                flags[j] = true;
//        }
//    }
//
//    vector<int> cnts(points.size(), 0);
//    for (size_t i = 0; i < points.size(); ++i) {
//        for (size_t j = 0; j < segments.size(); ++j) {
//            if (flags[j]) cnts[i]++;
//        }
//    }
//
//    vector<int> max;
//    vector<int> index;
//
//    for (int m = 0; m < points.size(); m++){
//        index[m] = m;
//    }
//
//    for (size_t i = 0; i < points.size(); ++i) {
//        for (size_t j = 0; j < points.size() - i - 1; ++j) {
//            if (points.at(j) > points.at(j + 1)) {
//                int temp = points[j+1];
//                points[j+1] = points[j];
//                points[j] = temp;
//
//                int ind_temp = index[j];
//                index[j] = index[j + 1];
//                index[j + 1] = ind_temp;
//            }
//        }
//    }
//
//    for (size_t i = 0; i < points.size(); ++i) {
//        max.push_back(points.at(i));
//        index.push_back(i);
//    }
//
//    return points;
//}

// 下面的算法是错的，思路是先把所有线段的起始和终点记录到点坐标，在一个个删掉。
// 但是虽然在删的时候可能的确满足条件 因为你没遍历的点很多 但这不能保证留下的点正确 因为最优的点可能被你之前删掉了
//
//bool safe_remove(vector<Segment> &segments, vector<int> &points) {
//    vector<bool> flags(segments.size(), false);
//    // if i-th segment contains at least 1 point, then flags.at(i) will be true
//
//    for (size_t i = 0; i < points.size(); ++i) {
//        for (size_t j = 0; j < segments.size(); ++j) {
//            if (points[i] >= segments[j].start && points[i] <= segments[j].end)
//                flags[j] = true;
//        }
//    }
//
//    for (size_t k = 0; k < segments.size(); ++k) {
//        // Check if every segment contains at least 1 point
//        if (flags[k]) continue;
//        return false;
//    }
//    return true;
//}
//
//vector<int> optimal_points(vector<Segment> &segments) {
//    vector<int> points;
//    vector<int>::iterator it;
//
//    for (auto &segment : segments) {
//        points.push_back(segment.start);
//        points.push_back(segment.end);
//    }
//
//    vector<int> cand = points;
//    for (it = points.begin(); it != points.end(); it++) {
//        cand.erase(points.begin());
//        if (safe_remove(segments, cand)) {
//            points.erase(it);
//            points.pop_back();
//        }
//    }
//    return points;
//}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        cin >> segments[i].start >> segments[i].end;
    }

    vector<int> points = optimal_points(segments);

    cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        cout << points[i] << " ";
    }
    return 0;
}
