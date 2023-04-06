#include<iostream>
#include<vector>
#include<chrono>
#include<iomanip>
#include<algorithm>
#include<ctime>
#include<random>

using std::cout;
using std::endl;
template <typename T>
void ourSwap(T& left, T& right) {
	T temp;
	temp = left;
	left = right;
	right = temp;
}
template <typename T>
int Partition(std::vector<T>& a, int start, int end) {
	int pivotValue, pivotIndex, mid;
	mid = (start + end) / 2;
	ourSwap(a[start], a[mid]);
	pivotIndex = start;
	pivotValue = a[start];
	for (int scan = start + 1; scan <= end; scan++) {
		if (a[scan] < pivotValue) {
			pivotIndex++;
			ourSwap(a[pivotIndex], a[scan]);
		}
	}
	ourSwap(a[start], a[pivotIndex]);
	return pivotIndex;
}
template<typename T>
void Quicksort(std::vector<T>&a, int start, int end) {
	int pivotPosition;
	if (start < end) {
		pivotPosition = Partition(a, start, end);
		Quicksort(a, start, pivotPosition - 1);
		Quicksort(a, pivotPosition + 1, end);
	}
}

template<typename T>
void printArray(std::vector<T> theArray) {
	for (int index = 0; index < theArray.size(); ++index) {
		cout << theArray[index] << " ";
	}
	cout << endl;
}

void randomVec(int size, std::vector<int>& vectInt)
{
	std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(0, 100000);
	for (int i = 0; i < size; i++)	//Fill with randoms 0 - 100,000
	{
		
		vectInt.push_back(intDistro(defEngine));
	}

}

void selectionSort(std::vector<int>& arr, int n)	//changed to use a vector passed by reference instead of an array
{													//Selection Sort example taken from geeksforgeeks https://www.geeksforgeeks.org/selection-sort/#
	int i, j, min_idx;
	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		// Swap the found minimum element
		// with the first element
		if (min_idx != i)
			ourSwap(arr[min_idx], arr[i]);			//Changed to use ourSwap
	}
}

//HEAPSORT
void heapsort(std::vector<int>& vec) 
{
	std::make_heap(vec.begin(), vec.end());
	for (int i = vec.size(); i > 0; i--) 
	{
		//I'm not sure if this is what you meant,
		//and it certainly doesn't look like anything I found online,
		//but it does work.
		std::pop_heap(vec.begin(), vec.begin() + i);
	}
}

double timeSel(std::vector<int>& vec)
{
	auto start = std::chrono::steady_clock::now();
	selectionSort(vec, vec.size());
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	return elapsed_seconds.count();
}

double timeQuick(std::vector<int>& vec)
{
	auto start = std::chrono::steady_clock::now();
	Quicksort(vec, 0, vec.size() - 1);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	return elapsed_seconds.count();
}

double timeHeap(std::vector<int>& vec)
{
	auto start = std::chrono::steady_clock::now();
	heapsort(vec);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	return elapsed_seconds.count();
}

bool quickFasterThanSel(int size, std::vector<double>& sTimes, std::vector<double>& qTimes)
{
	std::vector<int> vec;

	randomVec(size, vec);
	double timeS = timeSel(vec);
	vec.clear();

	randomVec(size, vec);
	double timeQ = timeQuick(vec);

	sTimes.push_back(timeS);
	qTimes.push_back(timeQ);

	if (timeQ < timeS)
		return true;
	else
		return false;
}

bool heapFasterThanSel(int size, std::vector<double>& sTimes, std::vector<double>& qTimes)
{
	std::vector<int> vec;

	randomVec(size, vec);
	double timeS = timeSel(vec);
	vec.clear();

	randomVec(size, vec);
	double timeH = timeHeap(vec);

	sTimes.push_back(timeS);
	qTimes.push_back(timeH);

	if (timeH < timeS)
		return true;
	else
		return false;
}


int main()
{
	std::vector<double>sTimes, qTimes;
	std::cout << "Is Quicksort faster than SelSort?\n";

	std::cout << "# of entries" << std::setw(15) << "Bool Value" << std::setw(16) << "Sel Time" << std::setw(16) << "Quick Time\n";

	std::cout << 5 << std::setw(17) << quickFasterThanSel(5, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[0] << std::setw(16) << qTimes[0] << std::endl;

	std::cout << 10 << std::setw(16) << quickFasterThanSel(10, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[1] << std::setw(16) << qTimes[1] << std::endl;

	std::cout << 20 << std::setw(16) << quickFasterThanSel(20, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[2] << std::setw(16) << qTimes[2] << std::endl;

	std::cout << 50 << std::setw(16) << quickFasterThanSel(50, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[3] << std::setw(16) << qTimes[3] << std::endl;

	std::cout << 100 << std::setw(15) << quickFasterThanSel(100, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[4] << std::setw(16) << qTimes[4] << std::endl;

	std::cout << 1000 << std::setw(14) << quickFasterThanSel(1000, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[5] << std::setw(16) << qTimes[5] << std::endl;

	std::cout << 10000 << std::setw(13) << quickFasterThanSel(10000, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[6] << std::setw(16) << qTimes[6] << std::endl;

	std::cout << 50000 << std::setw(13) << quickFasterThanSel(50000, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[7] << std::setw(16) << qTimes[7] << std::endl;
	
	qTimes.clear();
	sTimes.clear();

	std::cout << "\nIs Heapsort faster than SelSort?\n";

	std::cout << "# of entries" << std::setw(15) << "Bool Value" << std::setw(16) << "Sel Time" << std::setw(16) << "Heap Time\n";

	std::cout << 5 << std::setw(17) << heapFasterThanSel(5, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[0] << std::setw(16) << qTimes[0] << std::endl;

	std::cout << 10 << std::setw(16) << heapFasterThanSel(10, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[1] << std::setw(16) << qTimes[1] << std::endl;

	std::cout << 20 << std::setw(16) << heapFasterThanSel(20, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[2] << std::setw(16) << qTimes[2] << std::endl;

	std::cout << 50 << std::setw(16) << heapFasterThanSel(50, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[3] << std::setw(16) << qTimes[3] << std::endl;

	std::cout << 100 << std::setw(15) << heapFasterThanSel(100, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[4] << std::setw(16) << qTimes[4] << std::endl;

	std::cout << 1000 << std::setw(14) << heapFasterThanSel(1000, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[5] << std::setw(16) << qTimes[5] << std::endl;

	std::cout << 10000 << std::setw(13) << heapFasterThanSel(10000, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[6] << std::setw(16) << qTimes[6] << std::endl;

	std::cout << 50000 << std::setw(13) << heapFasterThanSel(50000, sTimes, qTimes);
	std::cout << std::setw(24) << sTimes[7] << std::setw(16) << qTimes[7] << std::endl;
	return 0;
}