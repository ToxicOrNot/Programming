#include <iostream>
#include <unordered_set>
#include <deque>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> search(unordered_map<string, vector<string>>& graph, const string& start, const string& goal) {
    unordered_set<string> visited;
    deque<vector<string>> queue = { {start} };

    while (!queue.empty()) {
        vector<string> path = queue.front();
        queue.pop_front();
        string room = path.back();

        if (visited.find(room) != visited.end()) {
            continue;
        }

        visited.insert(room);

        if (room == goal) {
            return path;
        }

        for (const string& neighbour : graph[room]) {
            vector<string> new_path = path;
            new_path.push_back(neighbour);
            queue.push_back(new_path);
        }
    }

    return {};
}

int main() {
    unordered_map<string, vector<string>> maze = {
        {"A", {"S"}},
        {"B", {"C", "D", "S"}},
        {"C", {"B", "J"}},
        {"D", {"B", "G", "S"}},
        {"E", {"G", "S"}},
        {"F", {"G", "H"}},
        {"G", {"D", "E", "F", "H", "J"}},
        {"H", {"F", "G", "I"}},
        {"I", {"H", "J"}},
        {"J", {"C", "G", "I"}},
        {"S", {"A", "B", "D", "E"}}
    };

    vector<string> result = search(maze, "S", "I");

    if (!result.empty()) {
        for (const string& room : result) {
            cout << room << " ";
        }
        cout << endl;
    } else {
        cout << "Path not found" << endl;
    }

    return 0;
}
