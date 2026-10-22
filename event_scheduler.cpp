
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Returns true if one person can attend every event
bool can_attend_all(vector<pair<int, int>> events) {
    sort(events.begin(), events.end());

    for (int i = 1; i < events.size(); i++) {
        if (events[i].first < events[i - 1].second) {
            return false;
        }
    }

    return true;
}

// it will retun minimum number of rooms required for meeting.

int min_rooms_required(vector<pair<int, int>> events) {
    if (events.empty()) {
        return 0;
    }

    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> rooms;
    int maxRooms = 0;

    for (const auto& event : events) {
        // Reuse a room if its meeting has ended
        while (!rooms.empty() && rooms.top() <= event.first) {
            rooms.pop();
        }

        rooms.push(event.second);

        // track the maximum number of rooms needed at any point
        maxRooms = max(maxRooms, (int)rooms.size());
    }

    return maxRooms;
}


int main() {
    vector<pair<int, int>> events = {
        {9, 10}, {10, 11}, {11, 12}
    };

    cout << boolalpha;
    cout << "Can attend all events: "
         << can_attend_all(events) << endl;

    cout << "Minimum rooms required: "
         << min_rooms_required(events) << endl;

    return 0;
}
