// 8/20/22
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int minStops = 0, currentStationIndex = 0, totalStations = size(stations);

        while(startFuel < target) {
            while(currentStationIndex < totalStations and stations[currentStationIndex][0] <= startFuel) {
                pq.push(stations[currentStationIndex][1]);
                currentStationIndex++;
            }

            if(pq.empty()) return -1;

            startFuel += pq.top();
            pq.pop();
            minStops++;
        }

        return minStops;
    }
};