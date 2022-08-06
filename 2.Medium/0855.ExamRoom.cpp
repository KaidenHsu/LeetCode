// 8/6/22
class ExamRoom {
private:
	set<int> seats;
	int capacity;

public:
	ExamRoom(int N) {
		capacity = N;
	}

	int seat() {
		int dist = 0, curr = 0;

		if (!seats.empty()) {
			auto itr = seats.begin();
            
            //calculate distance at the begining
			dist = *itr;

			if (dist == 0) itr++;
            
            //calculate distance in between
			while (itr != seats.end()) {
                int mid_dist = (*itr - *prev(itr)) / 2;

				if (mid_dist > dist) {
					dist = mid_dist;
					curr = *prev(itr) + dist;
				}

				itr++;
			}
            
            //calculate distance at the end
			if (dist < ((capacity - 1) - *(seats.rbegin()))) curr = capacity - 1;
		}

		return *(seats.insert(curr).first);
	}

	void leave(int p) {
		seats.erase(p);
	}
};