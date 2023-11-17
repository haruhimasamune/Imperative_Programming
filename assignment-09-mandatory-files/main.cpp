#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

struct Length
{
	int minutes;							// #minutes (0..)
	int seconds;							// #seconds (0..59)
};

struct Track
{
	string artist;                          // name of artist
	string cd;                              // cd title
	int    year;                            // year of appearance (if known)
	int    track;							// track number
	string title;                           // track title
	string tags;                            // tags
	Length time;							// playing time
	string country;                         // main countr(y/ies) of artist
};

/**********************************************************************************************************
 *
 * input and output code from prior week:
 *
 *********************************************************************************************************/
ostream& operator<< (ostream& out, const Length length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length is shown via out in the format: minutes, ':', seconds (two digits)
*/
    if (length.seconds >= 10)
        out << length.minutes << ':' << length.seconds;
    else
        out << length.minutes << ':' << '0' << length.seconds;
    return out;
}

istream& operator>> (istream& in, Length& length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length has been read from in: first minutes, then ':', then seconds
*/
    char colon = ':';
    in >> length.minutes >> colon >> length.seconds;
    return in;
}

ostream& operator<< (ostream& out, const Track& track)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of track is shown via out.
*/
    return out << track.artist << " - " << track.track << ". " << track.title
        << " (" << track.cd << ", " << track.year << ") [" << track.time << "]";
}

istream& operator>> (istream& in, Track& track)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the content of the first 8 lines from in have been read and are stored in the corresponding members of track.
    The following (empty) line from in has also been read.
*/
    char colon = ':';
    string emptyLine;
    getline(in, track.artist);
    getline(in, track.cd);
    in >> track.year;
    in >> track.track;
    in.ignore();  // read endline, this should be applied only between integer line and string line
    getline(in, track.title);
    getline(in, track.tags); 
    in >> track.time.minutes >> colon >> track.time.seconds;
    in.ignore(); 
    getline(in, track.country); 
    getline(in, emptyLine);  
    return in;
}

/**********************************************************************************************************
 *
 * (slice) helper function:
 *
 *********************************************************************************************************/
typedef Track El;                           // as explained in lecture, define algorithms on El

struct Slice
{  int from;     // from >= 0
   int length;   // length >= 0
};

Slice make_slice (int from, int length)
{// Precondition:
    assert (from >= 0 && length >= 0);
/*  post-condition:
    return slice with given from and length
*/
    Slice s = { from, length};
    return s;
}

Slice make_slice (const vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns the slice for the entire vector data.
*/
    Slice s = { 0, static_cast<int>( ssize (data) ) };
    return s;
}

bool valid_slice (Slice s)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if all selector values of s are not negative.
*/
    return 0 <= s.from && 0 <= s.length;
}
bool valid_slice (const vector<El>& data, Slice s)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if s is a valid slice for data
*/
    return valid_slice (s) && s.from + s.length <= ssize (data);
}

int first (Slice s)
{// Precondition:
    assert (valid_slice (s));
/*  Postcondition:
    result is index of first element in s (s.from)
*/
    return s.from;
}

int last (Slice s)
{// Precondition:
    assert (valid_slice (s));
/*  Postcondition:
    result is index of last element in s (s.from + s.length - 1)
*/
    return s.from + s.length - 1;
}

/**********************************************************************************************************
 *
 * compare operators:
 *
 *********************************************************************************************************/
bool operator== (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if all selector values of a are equal to their counterparts of b
*/
    return a.artist == b.artist &&
           a.cd == b.cd &&
           a.year == b.year &&
           a.track == b.track &&
           a.title == b.title &&
           a.tags == b.tags &&
           a.time.minutes == b.time.minutes &&
           a.time.seconds == b.time.seconds &&
           a.country == b.country;
}

bool operator!= (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if any selector values of a are not equal to their counterparts of b
*/
    return !(a == b);
}

bool operator< (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    check the assignment for the proper definition of < on Tracks
*/
    if (a.artist < b.artist)
        return true;
    if (a.artist > b.artist)
        return false;
    if (a.cd < b.cd)
        return true;
    if (a.cd > b.cd)
        return false;
    if (a.year < b.year)
        return true;
    if (a.year > b.year)
        return false;
    if (a.track < b.track)
        return true;
    if (a.track > b.track)
        return false;
    if (a.title < b.title)
        return true;
    if (a.title > b.title)
        return false;
    if (a.tags < b.tags)
        return true;
    if (a.tags > b.tags)
        return false;
    if (a.time.minutes < b.time.minutes)
        return true;
    if (a.time.minutes > b.time.minutes)
        return false;
    if (a.time.seconds < b.time.seconds)
        return true;
    if (a.time.seconds > b.time.seconds)
        return false;
    if (a.country < b.country)
        return true;
    else
        return false;
}

bool operator>(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a does not precede b according to the ordering < on Tracks (don't forget to implement operator<)
*/
	return b < a;
}

bool operator<=(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a < b or a == b according to their definitions on Tracks (don't forget to implement operator< and operator==)
*/
	return a < b || a == b;
}

bool operator>=(const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    returns true only if a > b or a == b according to their definitions on Tracks (don't forget to implement operator< and operator==)
*/
	return a > b || a == b;
}

bool is_sorted (const vector<El>& data, Slice s)
{// pre-condition:
    assert (valid_slice (data, s));
/*  post-condition:
    result is true if data.at(first (s)) <= data.at(first (s) + 1) ... data.at(last(s)-1) <= data.at(last(s))
*/

    for (int currentIndex = first(s); currentIndex < last(s); currentIndex++)
    {
        if (data.at(currentIndex) > data.at(currentIndex + 1))
            return false; 
    }
    return true;
}

void swap (El& a, El& b)
{// Precondition:
    assert (true);
/*  post-condition:
    The values of a and b swap with each other
*/
const El TEMP = a;
a = b;
b = TEMP;
}

/**********************************************************************************************************
 *
 * insertion sort algorithm:
 *
 *********************************************************************************************************/

void insert (vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data, s));
    assert (is_sorted (data, s));
    assert (last (s) < ssize (data) - 1);
/*  Postcondition:
    data.at (last (s)+1) is moved in data.at (first (s))...data.at (last (s)+1) and is_sorted (data, make_slice (s.from s.length+1))
*/
    for (int currentIndex = last(s) + 1; currentIndex > 0; currentIndex--)
    {
        if (data.at(currentIndex - 1) > data.at(currentIndex))
            swap(data.at(currentIndex - 1), data.at(currentIndex));
    }
}

void insertion_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    int sorted = 1;
    while (sorted < ssize(data))
    {
        insert (data, make_slice(0, sorted));
        sorted++;
    }
}

/**********************************************************************************************************
 *
 * selection sort algorithm:
 *
 *********************************************************************************************************/
int max_value_at (const vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data, s));
    assert (s.length > 0);
/*  Postcondition:
    data.at (result) is the maximum of every element in data.at (first (s)) ... data.at (last (s))
*/
    int maxIndex = first(s);
    for (int currentIndex = first(s); currentIndex < last(s); currentIndex++)
    {
        if (data.at(currentIndex) > data.at(maxIndex))
            maxIndex = currentIndex; 
    }
    return maxIndex;
}

void selection_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    int sorted = 0;
    while (sorted < ssize(data) - 1) // The last one left unsorted is the smallest one
    {
        int lastUnsorted = ssize (data) - sorted - 1;
        int maxUnsorted = max_value_at(data, make_slice(0, lastUnsorted + 1));
        swap (data.at(maxUnsorted), data.at(lastUnsorted));
        sorted++;
    }
}

/**********************************************************************************************************
 *
 * bubble sort algorithm:
 *
 *********************************************************************************************************/
bool bubble (vector<El>& data, Slice unsorted)
{// Precondition:
    assert (valid_slice (data, unsorted));
/*  Postcondition:
    immediate pairs in data with slice unsorted are swapped if left element is larger than right element, and result is
    true only if this is done at least once (don't forget to implement operator< and operator==)
*/
    int leftIndex = first(unsorted);
    int endIndex = last(unsorted);
    int swaps =  0;
    while (leftIndex < endIndex - 1)
    {
        if (data.at(leftIndex) > data.at(leftIndex + 1))
        {
            swap(data.at(leftIndex), data.at(leftIndex + 1));
            swaps++;
        }
        leftIndex++;
    }
    return swaps != 0;
}

void bubble_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement operator< and operator==)
*/
    int sorted = 0;
    Slice unsorted = make_slice (0, ssize(data) - sorted);
    while (bubble(data, unsorted) == true)
    {
        sorted++;
        unsorted = make_slice (0, ssize(data) - sorted);
    }
}

/**********************************************************************************************************
 *
 * heap sort algorithm:
 *
 *********************************************************************************************************/
int left_sibling (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the left sibling of an element at index i in a heap structured array/vector
*/
    return i-1;
}

int right_sibling (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the right sibling of an element at index i in a heap structured array/vector
*/
    return i+1;
}

int parent (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the parent of an element at index i in a heap structured array/vector
*/
    return (i-1) / 2;
}

int left_child (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the left child of an element at index i in a heap structured array/vector
*/
    return 2*(i+1)-1;
}

int right_child (int i)
{// Precondition:
    assert (0 <= i);
/*  Postcondition:
    result is the index (if existing) of the right child of an element at index i in a heap structured array/vector
*/
    return 2*(i+1);
}

bool is_a_heap (const vector<El>& data, Slice s)
{// Precondition:
    assert (valid_slice (data,s));
/*  Postcondition:
    result is true only if all existing children in slice s of data have a value that is not greater than their parent
*/
    for (int i = first(s); i < last(s); i++)
    {
        int leftChild = left_child (i);
        int rightChild = right_child (i);
        if (leftChild <= last(s) && data.at(leftChild) > data.at(i))
            return false;
        if (rightChild <= last(s) && data.at(rightChild) > data.at(i)) 
            return false;
    }
    return true;
}

void push_up ( vector<El>& data, int elem )
{// Precondition:
    assert (0 <= elem && elem < ssize (data) && is_a_heap (data, make_slice (0,elem)));
/*  Postcondition:
    is_a_heap (data, make_slice (0, elem+1))
*/
    int dad = parent(elem);
    while (elem > 0 && data.at(dad) < data.at(elem))
    {
        swap(data.at(dad), data.at(elem));
        elem = dad;
        dad = parent(elem);
    }
}

void build_heap ( vector<El>& data )
{// Precondition:
    assert (true );
/*  Postcondition:
    is_a_heap (data, make_slice (0, ssize (data)))
*/
    for (int i = 0; i < ssize(data)-1; i++)
        push_up(data, i);
}

bool largest_child (const vector<El>& data, int parent, int unsorted, El& child, int& which)
{// Precondition:
    assert (0 <= unsorted && unsorted < ssize (data));
    assert (0 <= parent && parent < ssize (data));
/*  Postcondition:
    result is true only if the element at parent in data has one or two unsorted child elements;
    only in that case the value of the largest child is child and its index position is which
*/
    int leftChild = left_child (parent);
    int rightChild = right_child (parent);
    if (leftChild > unsorted) // 1. No unsorted child
        return false;
    else if (rightChild > unsorted) // 2. Only left child is unsorted
    {
        which = leftChild;
        child = data.at(leftChild);
        return true;
    }
    else if (data.at(leftChild) > data.at(rightChild)) // 3. Both unsorted, left larger
    {
        which = leftChild;
        child = data.at(leftChild);
        return true;
    }
    else // 4. Both unsorted, right larger
    {
        which = rightChild;
        child = data.at(rightChild);
        return true;
    }
}

void push_down (vector<El>& data, int unsorted)
{// Precondition:
    assert (is_a_heap (data, make_slice (1,unsorted)));
/*  Postcondition:
    is_a_heap (data, make_slice (0, unsorted+1))
*/
    int i = 0;
    int leftChild = left_child (i);
    int rightChild = right_child (i);
    int childIndex;
    El childValue;

    while ( (leftChild <= unsorted && data.at(leftChild) > data.at(i) )  || 
    (rightChild <= unsorted && data.at(rightChild) > data.at(i) ) ) // Unsorted child larger than dad
    {
        bool findChild = largest_child (data, i, unsorted, childValue, childIndex); // Use to initialize childIndex and childValue
        swap (data.at(i), childValue);
        i = childIndex;
    }
}

void pick_heap (vector<El>& data)
{// Precondition:
    assert (is_a_heap (data, make_slice (data)));
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    int unsorted = ssize(data) - 1;
    while (unsorted > 0)
    {
        swap (data.at(0), data.at (unsorted));
        unsorted--;
        push_down (data, unsorted);
    }
}

void heap_sort(vector<El>& data)
{// Precondition:
    assert (true);
/*  Postcondition:
    data is sorted in increasing order, according to < and == on El (don't forget to implement < and ==)
*/
    build_heap(data);
    pick_heap(data);
}

/**********************************************************************************************************
 *
 * main function:
 *
 *********************************************************************************************************/
enum SortAlgorithm
{
    InsertionSort,
    SelectionSort,
    BubbleSort,
    HeapSort
};

const int SORT_ALGORITHMS = HeapSort + 1;
const string SORT_ALGORITHM_NAMES[SORT_ALGORITHMS] = {
    "Insertion sort",
    "Selection sort",
    "Bubble sort",
    "Heap sort"
};

bool load_database (string filename, vector<El>& database)
{// Precondition:
    assert (true);
/*  Postcondition:
    `database` contains database loaded from file `filename` and return value is true if no errors occurred.
    return value is false otherwise.
*/
    ifstream database_file(filename);
    El element;

    if(!database_file.is_open()) {
        return false;
    }

    while(database_file >> element) {
        database.push_back(element);
    }

    return true;
}

SortAlgorithm get_sort_algorithm()
{// Precondition:
    assert (true);
/*  Postcondition:
    return value is the user chosen sorting algorithm.
*/
    int choice;

    do {
        cout << "\nSelect a sorting algorithm" << endl;
        for(int i = 1; i <= SORT_ALGORITHMS; i++) {
            cout << i << ". " << SORT_ALGORITHM_NAMES[i - 1] << endl;
        }

        cout << "> ";
        cin >> choice;

        if(choice < 1 || choice > SORT_ALGORITHMS) {
            cout << "Invalid sorting algorithm" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(choice < 1 || choice > SORT_ALGORITHMS);

    return static_cast<SortAlgorithm>(choice - 1);
}

#ifndef TESTING
int main()
{// Precondition:
    assert (true) ;
/*  Postcondition:
    The music database "Tracks.txt" has been read (if present and correctly formatted).
    The sorted database has been printed according to the user selected sorting algorithm.
*/
    vector<El> database;

    if(!load_database("Tracks.txt", database)) {
        cout << "Error: could not open Tracks.txt" << endl;
        return 1;
    }

    cout << "Loaded " << ssize(database) << " element(s) from database" << endl;
    SortAlgorithm algorithm = get_sort_algorithm();
    cout << "Sorting database using " << SORT_ALGORITHM_NAMES[algorithm] << endl;

    switch(algorithm)
    {
        case InsertionSort:
            insertion_sort(database);
            break;
        case SelectionSort:
            selection_sort(database);
            break;
        case BubbleSort:
            bubble_sort(database);
            break;
        case HeapSort:
            heap_sort(database);
            break;
    }

    cout << "Showing sorted database:" << endl;
    for(int i = 0; i < ssize(database); i++) {
        cout << database.at(i) << endl;
    }

	return 0;
}
#endif
