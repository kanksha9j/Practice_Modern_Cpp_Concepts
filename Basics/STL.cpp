#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;

/*
Sequence: array,vector,list,deque,forward_list
Associative:set,map,multiset,multimap
Unordered:unordered_set,unordered_map,unordered_multiset,unordered_multimap
common functions:
default constructor, 
uniform initialized constructor, 
copy constructor, 
size(), clear(), begin(), 
end(), default allocator
*/

void Vector()
{
	//push 5 elements
	vector<int> vec{1,2,3,4,5};
	for (int i = 0;i < 5;i++)
	{
		vec.push_back(10);
	}
	cout << vec.size() << endl;

	//print all elements. using for,while iterator
	for (auto x : vec)
	{
		cout << x << " ";
	}

	cout << endl;
	
	vec[2] = 100;
	auto itr = vec.begin();
	while (itr != vec.end())
	{
		cout << *itr << " ";
		itr++;
	}

	cout << endl;
	//insert element in between- shifts elements causing assignment,copy
	vec.insert(vec.begin()+1, 20);  //1,20,2,3

	for (auto x : vec)
	{
		cout << x << " ";
	}

	cout << endl;

    //remove last element
	vec.pop_back();

	//remove in between
	vec.erase(vec.begin()+1);

	for (auto x : vec)
	{
		cout << x << " ";
	}

	cout << endl;

	vec.clear();   //clears the vector
	cout << vec.size() << endl;
}

void Array() {
	std::array<int, 5> arr{1,2,3,4,5};
	auto itr = arr.begin();
	int* ptr = arr.data();
	for (auto i = 0; i < arr.size();i++)
	{
		cout << ptr[i];
	}
	cout << endl;

	for (auto x : arr)
	{
		cout << x;
	}
	cout << endl;
}

void Deque()
{
	//Deque operations similar to vector except adding and removing from front.

	//add elements front and back
	std::deque<int> deq{ 1,2,3,4,5 };
	for (int i = 0; i < 5;i++)
	{
		deq.push_front(10);
		deq.push_back(10);
	}

	//random access
	deq[0] = 100; 

	//print using iterators
	auto itr = deq.begin();
	while (itr != deq.end())
	{
		cout << *itr << " ";
		itr++;
	}

	cout << endl;
	//print all elements
	for (auto x : deq)
	{
		cout << x << " ";
	}
	cout << endl;

	//add, insert in between
	deq.insert(deq.begin() + 2, 20);

	for (auto x : deq)
	{
		cout << x << " ";
	}
	cout << endl;

	deq.erase(deq.begin() + 2);
	deq.erase(deq.end()-1);
	//deq.erase(deq.end()); //cant do that

	//remove from front and back
	deq.pop_back();
	deq.pop_front();

	for (auto x : deq)
	{
		cout << x << " ";
	}
	cout << endl;

	deq.clear();
	cout << deq.size() << endl;

}

void List()
{
	//two way traversing. not random access container
	list<int>lst{ 1,2,3,4,5 };

	//lst[23] = 100; //not allowed

	for (auto i = 0;i < 5;i++)
	{
		lst.push_back(10);
		lst.push_front(10);
	}

	//lst.insert(lst.begin() + 2, 20); //not allowed as its iterators are not random access.
	//but you can: or also use for loop with iterator and after exact loc can insert like this:
	auto it = next(lst.begin(), 1);
	lst.insert(it, 20);

	cout << "After insert" << endl;
	for (auto x : lst)
	{
		cout << x << " ";
	}
	cout << endl;

	lst.insert(lst.begin(),20);
	lst.insert(lst.end(), 20);

	auto itr = lst.begin();
	while (itr != lst.end())
	{
		cout << *itr << " ";
		itr++;
	}
	cout << endl;
	
	lst.erase(lst.begin());
	//lst.erase(lst.end());
	
	lst.pop_back();
	lst.pop_front();

	lst.clear();

	cout << lst.size() << endl;
}

void Forwardlist()
{
	cout << "forward list" << endl;
	forward_list<int> flst{ 1,2,3,4,5 };

	for (int i = 0;i < 5;i++)
	{
		//flst.push_back(10);   //not allowed
		flst.push_front(10);
	}

	//flst[2] = 100; //not allowed

	//flst.insert(flst.begin()+2,20);  not allowed because iterator not random access
	flst.insert_after(flst.begin(), 20); //it inserts at 2nd place, because the forward pointer is pointing to next node. 

	for (auto i = flst.begin();i != flst.end();i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	flst.erase_after(flst.begin());

	auto it = next(flst.begin(), 1);

	flst.insert_after(flst.begin(), 100);


	for (auto i = flst.begin();i != flst.end();i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	flst.clear();
	//cout << flst.size() << endl; //size not allowedbecause it requires full traversal for size
}

#include<functional>   //for greater than
void Set()
{
	cout << "Set" << endl;
	set<int,greater<int>> st{ 2,3,1,4,5 }; //internally stores in ascending order
	st.insert(10);            //so doent matter where you insert
	st.insert(20);
	st.insert(20);            //does not take duplicate

	auto itr = st.begin();
	while (itr != st.end())
	{
		cout << *itr++ << " ";
	}
	cout << endl;

	st.erase(6); //erases the value 6 , but its not there
	st.erase(st.begin());

	itr = st.find(10);
	if (itr != st.end())
	{
		cout << "Value found" << endl;
	}
	else {
		cout << "value not found" << endl;
	}

	for (auto x : st)
	{
		cout << x << " ";
	}
	cout << endl;

	//multiset
	multiset<int> mst{ 2,3,6,1,5,4 };
	mst.insert(10);                     //takes duplicate
	mst.insert(10);
	mst.insert(20);

	for (auto x : mst)
	{
		cout << x << " ";
	}
	cout << endl;
	auto found = mst.equal_range(10);  //find all elements with key 10. returns pair<iterator,iterator>
	while (found.first != found.second)
	{
		cout << *found.first++ << " ";   //found.first points to first element =10
	}
	cout << *found.second<<endl; //it is the element after last 10 value or mst.end() if no value after

}

void Map()
{
	cout << "Map:" << endl;
	map<int, string> mp{
		{1,"Ak"}, {2,"Vi"}, {3, "Pr"}
	};

	mp.insert(pair<int, string>{5, "Aj"});  //uniform initialization preferred.
	mp.insert(pair<int, string>(4, "Ab"));
	mp.insert(pair<int, string>(4, "Ab"));  //duplicate is omitted ,old value is only kept
	mp.insert(make_pair( 6,"Bb" )); //requires round brackets.
	mp[0] = "Aka";
	mp.erase(6);

	for (const auto &x : mp)
	{
		cout << x.first << " "<<x.second<< ",";
	}
	cout << endl;

	auto itr = mp.find(5); //find based on key
	if (itr != mp.end())
	{
		cout << "Value found:" << itr->second<< endl;
	}
	else {
		cout << "value not found" << endl;
	}
	//avoid using mp[i] subscript to search  in map, as if it goes out of bound it will be error.


	//For duplicates use multimAp
	cout << "multiMap:" << endl;
	multimap<int, string> mmp{
		{1,"Ak"}, {2,"Vi"}, {3, "Pr"}
	};

	mmp.insert(pair<int, string>{5, "Aj"});  //uniform initialization preferred.
	mmp.insert(pair<int, string>(4, "Ab"));
	mmp.insert(pair<int, string>(4, "Ab"));  //duplicate is omitted ,old value is only kept
	mmp.insert(make_pair(6, "Bb")); //requires round brackets.
	//mmp[0] = "sdfg";not allowed

	auto found = mmp.equal_range(4);
	while (found.first != found.second)
	{
		cout << found.first->first << " " << found.first->second << endl;
		found.first++;
	}
}

void Unordered_Set()
{
//too many elements in bucket degrades performance i.e when load factor is 1.
	std::unordered_set<string> uSet;//1-type of element,2-type of hash function,3-equality,4-allocator
	uSet.insert("Ab");
	uSet.insert("Zu");
	uSet.insert("Ac");
	uSet.insert("Ze");
	uSet.insert("Ad");
	uSet.insert("Zf");
	uSet.insert("As");
	uSet.insert("Zf");
	uSet.insert("Ag");
	uSet.insert("Zh");
	//performance will still be better than associative container

	for (const auto x : uSet)
	{
		cout << "Bucket #" << uSet.bucket(x) << "contains" << x << endl;
	}
	cout << endl;
	cout << "Bucket cnt:" << uSet.bucket_count() << endl;
	cout << "Load factor:" << uSet.load_factor() << endl;
	cout << "No. of elements" << uSet.size() << endl;

}

void Unordered_Map()
{
	unordered_map<string, string> uMap; //1-type of key,2- type of value,3-hash function, 4-equality, 5-allocator
	uMap["A"] = "B";
	uMap["B"] = "C";
	uMap["C"] = "D";
	uMap["D"] = "E";
	uMap["E"] = "F";
	uMap["F"] = "G";

	for (const auto x : uMap)
	{
		cout << "Bucket #" << uMap.bucket(x.first) << "contains" << x.second << endl;
	}
	cout << endl;
	cout << "Bucket cnt:" << uMap.bucket_count() << endl;
	cout << "Load factor:" << uMap.load_factor() << endl;
	cout << "No. of elements" << uMap.size() << endl;

	//Multimap
	cout << "unordered multimap" << endl;
	unordered_multimap<string, string> uMmap;
	//cannot use uMap[] subscript to insert. can make duplicates
	uMmap.insert(std::make_pair("A", "fh" ));
	uMmap.insert(std::make_pair("A", "fh"));
	uMmap.insert(std::make_pair("B", "fh"));
	uMmap.insert(std::make_pair("C", "fh"));
	uMmap.insert(std::make_pair("D", "fh"));

	for (const auto x : uMmap)
	{
		cout << "Bucket #" << uMmap.bucket(x.first) << "contains" << x.second << endl;
	}

	cout << endl;
	cout << "Bucket cnt:" << uMmap.bucket_count() << endl;
	cout << "Load factor:" << uMmap.load_factor() << endl;
	cout << "No. of elements" << uMmap.size() << endl;

}

void Hash()
{
	hash<string> h;
	cout << "Hash" << h("Hello") << endl;
}

int STL()
//int main()
{

//LIFO is stack behaviour,FIFO is queue behaviour
//Vector,list,deque,forward list - all are LIFO efficient
//FIFO not efficient- vector,forwardlist

//std::Array : supports iterators, knows size, random access, cannnot grow at runtime.
//backward compatible with C style array.
	Array();

//Vector: dynamic array, can grow at runtime, random access, 
//not good performance for insertion deletion of random element.
	Vector();

//Deque: efficient for addition & removal at both ends
//not efficient for add,delete in random location.
//grows automatically, provides random access.
	Deque();

//List: implemented as 2-way linked list. efficient for insertion/deletion anywhere
//does not provide random access
/*  Node <-  Node  <-  Node
         ->        ->
*/
	List();

//Forward list: implemented as single way linked list, small memory footprint, efficient for insertion& deletion
//no support for size
	Forwardlist();

//Set: implemented as binary tree,value acts as key,fast search, cannot modify value directly, stored in sorted order
// not as efficeinet as list for insertion,deletion but efficient for lookup or retrieval of values. use if frequently want to lookup
	Set();

//Map:implemented as binary tree, stores a pair of key and value, fast search, cannot modify key directly,stores in sorted key order
	Map();

//Unorderd containers: are associative containers internally implemented as hash tables.
//when an elemnt is added it goes through hash function and then a key is produced, at that key
//the element is stored. if the hash function generates same key, then there is a collision. in such case a pointer to
// linked list is created and the collided element is stored. eeach storage/slot is also called bucket.
//the load factor is entries/capacity. if a certain load factor is reached, the performance can be degraded, as searching will not be efficient.
	Unordered_Set();
	Unordered_Map();

//Hash function for custom data types. Hashing means converting a key (like a string or number) into an index 
// in an internal array using a hash function.
//STL does hash for std data types-int,string,char,float. So for custom type like cllass,struct, create your own hash functtion
	Hash();

//for storing custom type in STL , you need to overload >,<,=
//for custom hash , create function object for hashing, another func obj for equality 
	return 0;
}