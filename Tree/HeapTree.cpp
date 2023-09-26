#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;

struct MinHeap 
{
private:
	vector<long int> heap;
	long int number;
	long int PARENT(long int i) 
	{ 
		return (i - 1) / 2; 
	}

	long int LEFT(long int i) 
	{ 
		return (2 * i + 1); 
	}

	long int RIGHT(long int i) 
	{ 
		return (2 * i + 2); 
	}

	void h_down(long int i)
	{
		long int left = LEFT(i);
		long int right = RIGHT(i);

		long int smallest = i;

		if (left < heap.size() && heap[left] < heap[i])
			smallest = left;

		if (right < heap.size() && heap[right] < heap[smallest])
			smallest = right;

		if (smallest != i) {
			swap(heap[i], heap[smallest]);
			h_down(smallest);
		}
	}

	void h_up(long int i)
	{
		if (i && heap[PARENT(i)] > heap[i]) 
		{
			swap(heap[i], heap[PARENT(i)]);			
			h_up(PARENT(i));
		}
	}
	
public:
	void set_number(long int i)
	{
		number = i;
		// cout << number << endl;
	}

	long int get_number()
	{
		return number;
	}
	bool empty()
	{
		return heap.size() == 0;
	}
	
	int size()
	{
		return heap.size();
	}
	void insert(long int key)
	{
		heap.push_back(key);
		long int index = heap.size() - 1;
		h_up(index);
	}

	void extractMin()
	{
		heap[0] = heap.back();
		heap.pop_back();

		h_down(0);
	}

	long int getMin()
	{
		return heap.at(0);
	}

	void shift(long int amount)
	{
		// cout << amount << heap.size() <<endl;
		for (int i = 0; i < heap.size(); i++)
		{
			// cout << "before"<< heap[i] << endl;
			// cout << heap[i]<< endl;
			heap[i] += amount;
			// cout << "after"<<heap[i] << endl;
		}
	}
};

class MinHeap2 
{
private:
	vector<struct MinHeap> heap;
	vector<long int> indexes;

	long int PARENT(long int i) 
	{ 
		return (i - 1) / 2; 
	}

	long int LEFT(long int i) 
	{ 
		return (2 * i + 1); 
	}

	long int RIGHT(long int i) 
	{ 
		return (2 * i + 2); 
	}
	bool isLeaf(long int pos) 
	{ 
		if (pos >= (heap.size() / 2) && pos <= heap.size())
			return true;

		return false;
	} 

	void heapify_down(long int i)
	{
		long int left = LEFT(i);
		long int right = RIGHT(i);

		long int smallest = i;

		if (heap[i].size() != 0)
		{
			if (left < heap.size() && heap[left].size() != 0 && (heap[left].getMin() < heap[i].getMin() || (heap[left].getMin() == heap[i].getMin()) && indexes[left] < indexes[i]))
				smallest = left;

			if (right < heap.size() && heap[right].size() != 0 && (heap[right].getMin() < heap[smallest].getMin() || (heap[right].getMin() == heap[smallest].getMin()) && indexes[right] < indexes[smallest]))
				smallest = right;
		}
		else
		{
			int flag = 0;
			if(right < heap.size() && heap[left].size() != 0 && heap[right].size() != 0)
			{
				if (heap[left].getMin() < heap[right].getMin() || ( (heap[left].getMin() == heap[right].getMin()) && indexes[left] < indexes[right]) )
					smallest = left;

				else if (heap[left].getMin() > heap[right].getMin() || ( (heap[left].getMin() == heap[right].getMin()) && indexes[left] > indexes[right]) )
					smallest = right;

				flag = 1;
			}
			else if (right < heap.size() && heap[left].size() == 0 && heap[right].size() != 0)
				smallest = right;

			else if (right < heap.size() && heap[left].size() != 0 && heap[right].size() == 0)
				smallest = left;
		
			if(left < heap.size() && heap[left].size() != 0 && flag == 0)
				smallest = left;
		}
		if (smallest != i)
		{
			swap(heap[i], heap[smallest]);
			swap(indexes[heap[i].get_number()], indexes[heap[smallest].get_number()]);

			heapify_down(smallest);
		}
	}

	void heapify_up(long int i)
	{
		if (i && (heap[PARENT(i)].size() == 0 || heap[PARENT(i)].getMin() > heap[i].getMin() || (heap[PARENT(i)].getMin() == heap[i].getMin() && indexes[i] < indexes[PARENT(i)])))
		{
			swap(heap[i], heap[PARENT(i)]);
			swap(indexes[heap[i].get_number()], indexes[heap[PARENT(i)].get_number()]);
		
			heapify_up(PARENT(i));
		}
	}
	
public:

	bool empty()
	{
		return heap.size() == 0;
	}
	
	void insert(struct MinHeap key)
	{
		heap.push_back(key);
		long int index = heap.size() - 1;
		indexes.push_back(index);
	}

	// void heapify(long int pos) 
 //    {
 //        if (!isLeaf(pos))
 //        {
 //            if(heap[LEFT(pos)].size() && heap[RIGHT(pos)].size() && (heap[pos].getMin() > heap[LEFT(pos)].getMin() || heap[pos].getMin() > heap[RIGHT(pos)].getMin()))
 //            {
 //                if (heap[LEFT(pos)].getMin() < heap[RIGHT(pos)].getMin())
 //                { 
 //                    swap(heap[pos], heap[LEFT(pos)]); 
 //                    heapify(LEFT(pos)); 
 //                }
 //                else
 //                { 
 //                    swap(heap[pos], heap[RIGHT(pos)]); 
 //                    heapify(RIGHT(pos)); 
 //                } 
 //            }
 //        }
 //    }
	void insertGrade(long int c, long int grade)
	{
		long int i = indexes[c];
		// cout << c << " " << i << endl;
		heap[i].insert(grade);
		heapify_up(i);
		// i = indexes[c];
		// // cout << c << " " << i << endl;
	 //    // for (long int j = startIdx; j >= 0; j--)
		// heapify_down(i);

		// get_heap();
		// cout << c << " " << i << endl;

	}

	void shiftGrades(long int c, long int amount)
	{
				// cout << "hereee" << endl;

		long int i = indexes[c];
		// cout << "iiiiiiii"<<i << endl;
		// get_heap();
		// cout << "here" << endl;
		heap[i].shift(amount);
		if (heap[i].size() == 0)
		{
			return;
		}
		if (amount > 0)
		{
			heapify_down(i);
		}
		else
			heapify_up(i);

		// get_heap();
	}
	void extractMinGrade()
	{
		if (!heap[0].size())
			return;

		heap[0].extractMin();

		heapify_down(0);
		// get_heap();
	}

	void get_heap()
	{
		for (long int i = 0; i < heap.size(); ++i)
		{

			if(heap[i].size() != 0)
				cout << i << "  " <<heap[i].getMin() << endl;
			else
				cout << i << "  empty " << endl;
		}
		for (long int i = 0; i < indexes.size(); ++i)
		{
			cout << indexes[i] << endl;
		}
	}
	long int getMinGrade()
	{
		// get_heap();
		if (heap[0].size() == 0)
			return -1;

		return heap.at(0).getMin();
	}
};


int main()
{
	string raw;
	getline(cin, raw, ' ');

	long int n_classes = stoi(raw);
	long int n_reqs,req, grade, amount, c;
	cin >> n_reqs;

	MinHeap2 school;
	for (long int i = 0; i < n_classes; ++i)
	{
		MinHeap heap;
		heap.set_number(i);
		school.insert(heap);
	}
	// cout << "here"<<n_reqs<<n_classes << endl;
	for (long int i = 0; i < n_reqs; ++i)
	{
		cin >> req;
		if (req == 1)
		{
			cin >> c;

			cin >> grade;

			school.insertGrade(c-1, grade);
			// cout << "here1" << endl;
			// school.get_heap();
		}
		if (req == 2)
		{
			cin >> c;

			cin >> amount;
			school.shiftGrades(c-1, amount);
			// cout << "here2" << endl;
		}
		if (req == 3)
		{
			cout << school.getMinGrade() << endl;
			school.extractMinGrade();	
				// cout << "here3" << endl;

		}
	}


	return 0;
}