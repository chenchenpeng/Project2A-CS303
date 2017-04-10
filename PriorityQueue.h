#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <utility>
#include <vector>

template<typename Item_Type>
class Priority_Queue {
private:

	std::vector<std::pair<Item_Type, int>> V;

	void max_heapify(unsigned int root) {
		unsigned int left_child = 2 * root + 1;
		unsigned int right_child = 2 * root + 2;
		unsigned int largest = root;
		if (left_child < V.size() && V[left_child].second > V[largest].second) {
			largest = left_child;
		}
		if (right_child < V.size() && V[right_child].second > V[largest].second) {
			largest = right_child;
		}
		if (largest != root) {
			std::swap(V[root], V[largest]);
			max_heapify(largest);
		}
	}

public:

	void add_item(const Item_Type& item, int priority) {
		V.push_back(std::make_pair(item, priority));
		int son_index = V.size() - 1;
		int father_index = (son_index - 1) / 2;
		while (son_index > 0 && V[father_index].second < V[son_index].second) {
			std::swap(V[father_index], V[son_index]);
			son_index = father_index;
			father_index = (son_index - 1) / 2;
		}
	}

	void reprioritize() {
		if (!V.empty()) {
			Priority_Queue<Item_Type> H;
			for (unsigned int i = 0; i < V.size(); i++) {
				H.add_item(V[i].first, V[i].second);
			}
			V = H.V;
		}
	}

	Item_Type pop_max() {
		if (V.empty()) {
			throw std::exception("Empty Queue!");
		}
		Item_Type result = V[0].first;
		std::swap(V[0], V[V.size() - 1]);
		V.pop_back();
		if (!V.empty()) {
			max_heapify(0);
		}
		return result;
	}

	Item_Type& peek_max() {
		if (V.empty()) {
			throw std::exception("Empty Queue!");
		}

		return V[0].first;
	}

	bool empty() const {
		return V.empty();
	}

	unsigned int size() const {
		return V.size();
	}
};

#endif
