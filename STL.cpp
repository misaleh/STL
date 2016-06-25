/* 
based on : https://www.youtube.com/watch?v=KAS83uXf_8s&index=26&list=PLPt2dINI2MIZPFq6HyUB1Uhxdh1UDnZMS
*/
#include <functional>
#include <utility>
#include <numeric>
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<valarray>
#include <iterator>

using namespace std;

#define all(v)			((v).begin()), ((v).end())
#define SIZE(v)			((int)((v).size()))

typedef vector<int> vi;

void PrintVector(vi v2,string s = "")
{	
	cout<<s;
	for(int i = 0 ; i < v2.size() ; i++)
	cout<<v2[i]<<" ";
	cout<<endl;
}
template<class T>
void printValArray(valarray<T> v2, string s = "")
{
    cout<<s;
    for (int i = 0; i < (int)v2.size(); ++i)
            cout<<v2[i]<<" ";
        cout<<"\n";
}
 

int isOdd(int x)
{
	return (x%2);
}

bool sortPairsCmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first * b.second < a.second * b.second;
}

int toInt(string str) {
    int num;
    istringstream iss(str); //put string in input stream
    iss>>num; return num; //read from stream as integer
}
 
template <class T> string toStr(T par) {
    ostringstream oss;  //output stream string
    oss<<par;    //write par to the stream
    return oss.str(); //return string of output
}
 

int main() {
/*  ******************************** VECTORS ****************************** */
	unsigned int i  = 0; 
	vi v(10) ; //array of 10 cotain 0s
	vi v1(10,5);//array of 5s

/*convert array to vector   */
	int a[5] = {1,2,3,4,5}; //array
	vi v2(a,a+5); //first and last address
	cout<<v2.front()<<endl;  //works by refernce 
	cout<<v2.back()<<endl;   //works by refernce
	swap(v2.front(),v2.back());  //implemented function
	cout<<v2.back()<<endl;       //to check

/*  copy vectors  */
	vi v3(v2.begin(),v2.end()); //copy it
	cout<<v2.front()<<endl;

/* resize */
	v2.resize(6);
	v2[5] = 6;
	cout<<v2[5]<<endl; 

/* iterate on vector */
	for(i = 0 ; i < v2.size() ; i++)
	cout<<v2[i]<<" ";
//OR
	vi::iterator  it = v2.begin();
	while(it != v2.end())
	{
		cout<<(*it)<<" ";
		++it;
	}

/* sorting */
	sort(v2.begin() ,v2.end());  //in algorthim library
//decreasing
	sort(v2.begin(), v2.end(), greater<int>());	
	sort(v2.rbegin(), v2.rend());

/* 2D  array */
	vector <vector<int> >  v4(10,vector<int>(20,17)); // vector 10 * 20
	cout<<v4[9][19] <<endl;

/* comparing */ // compares every element (== , != , >= , > , <= , < )
	if(v3 < v2) cout<<"Hello"<<endl;
	
/*  Inserting and removing */
	v2.erase(v2.begin()+1);
	v2.insert(v2.begin()+4,21);
	v2.push_back(8);  //at the last of the vector 
	PrintVector(v2);
	v2.pop_back(); //remove last element
	PrintVector(v2);
	cout<<v2.size()<<endl;

/* find */
	cout << (find(all(v2),6) != v2.end() )<< endl; //if there will return 1
/*reverse */
	reverse(all(v2));
	PrintVector(v2);
/*random shuffel */
	random_shuffle(all(v2));
/* replace */
	replace(all(v2),3,17);
	PrintVector(v2);
	replace_if(all(v2), isOdd,18);//2nd, pointee to function that will be 
	PrintVector(v2);
/*search for consecutive number*/	
	it = search_n(all(v2),2,18); // all(v) , their number, their value , 
	if(it != v2.end())
		cout<<"index = "<< it - v2.begin()<<endl;
	//search for subarray
	int b[10] = {2,3,4,5,6,7,8,9,10,11};
	vi v5(b,b+10);
	search(all(v2),all(v5));
/* operation on sorted array */	
 	//binary search
	bool ans = binary_search(all(v5),10);
	cout<<"binary search = "<<ans<<endl;
	//find the first element greater than or equal a given element
	it = lower_bound(all(v5),4);
	if(it != v5.end())
		cout<<"Index of lower bound = "<<it - v5.begin() <<endl; 
	//find the first element greater than a given element
	it = upper_bound(all(v5),4);
	if(it != v5.end())
		cout<<"Index of upper bound = "<<it - v5.begin() <<endl; 
	//remove duplicates
	sort(all(v2));
	v2.resize(unique(all(v2)) - v2.begin());
	PrintVector(v2);
	
/* Max and Min */
	int mx =  *max_element(all(v5));//returns iterator
		cout<<"Max = "<<mx<<endl;
	int mn =  *min_element(all(v5));//returns iterator
		cout<<"Min = "<<mn<<endl;
/* swap group of elements */
	PrintVector(v2);
	PrintVector(v5);
	swap_ranges(v5.end()-2,v5.end(),v2.begin());
	PrintVector(v2);
	PrintVector(v5,"v5 = ");
/* Sum , multiplicatin or operation on all elements*/
	int vecSum = accumulate(all(v5),0);   //second is intial value  // in <numeric>
	cout<<"Sum = "<<vecSum <<endl;
	int vecMul = accumulate(all(v2),1,multiplies<int>()); //second is intial value
	cout<<"Mult = "<<vecMul<<endl;
	int sumofproduct = inner_product(all(v2),v2.begin(),0);// v[0]*v[0] + v[1]*v[1]..
	cout<<"S of P = "<<sumofproduct<<endl;
	int productofsum = inner_product(all(v2),v2.begin(),1,multiplies<int>(),plus<int>() );
	//(v[0]+v[0])*(v[1]+v[1])
	cout<<"P of S = "<<productofsum<<endl;
	//partial accumaltive sum (as cumsum in matlab)
	v1.clear();
	partial_sum(all(v5),back_inserter(v1));//sum on v2 and save in v1
	PrintVector(v1,"v1 = ");
	
/* count if condition*/
	int count  = count_if(all(v1),isOdd);
	cout<<"count odd = "<<count<<endl;
/* rotation*/
	rotate(v1.begin(),v1.begin()+2,v1.end()); //rotate left by 2
	PrintVector(v1,"rotate left v1 = ");
	rotate(v1.begin(),v1.end()-2,v1.end()); //rotate right by 2
	PrintVector(v1,"rotate right v1 = ");

/*clear*/
	v2.clear();
	PrintVector(v2);
	
/* ******************************QUEUES***************************************  */
//queue
	queue<int> q1;
	q1.push(1);
	q1.push(5);
	q1.push(8);
	cout<<"last element"<<q1.back()<<endl; //last element added in the queue
	cout<<"Queue elements: ";
	while(!q1.empty()) //return one if queue is empty
	{
		cout<<q1.front()<<" ";   // oldes element (first)
	q1.pop(); //remove last element 
	}
	cout<<"\n";

//deque
	deque<int> dq; 
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);
	dq.push_front(10);
	cout<<"front = "<<dq.front() <<" back = "<<dq.back()<<endl; 
	dq.pop_front();
	dq.pop_back();
	cout<<"front = "<<dq.front() <<" back = "<<dq.back()<<endl;

//priority queue
	priority_queue<int> pq;
// priority_queue<int, cmp> pq;   // pass cmp to sort them
	pq.push(20);
	pq.push(10);
	pq.push(30);
 
	cout<<"Priority Queue elements: ";
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<"\n";


/* ******************************* STACK ******************************* */
	stack<int> s;
	s.push(20);
	s.push(10);
	s.push(30);
	cout<<"Stack elements: ";
	while(!s.empty())
	{
    		cout<<s.top()<<" ";
     		s.pop();
	}
	cout<<"\n";
 
 
 /*  **************************** PAIR ************************************* */
	pair<int, char> p1 = make_pair(10, 'z');
	pair<string, pair<int, char> > p2 = make_pair("mostafa", p1);
	cout<<p2.first<<"\n";
	cout<<p2.second.first<<"\n";
	cout<<p2.second.second<<"\n";

//vector of pairs
	vector< pair<int, int> > vp;
	vp.push_back( make_pair(1, 2) );
	vp.push_back( make_pair(4, 4) );
	sort( all(vp), sortPairsCmp); // compare function , i can implement to fit my application

/* **************************SETS (log(n))************************************** */

	set<string> strSet;
	strSet.insert("mostafa");
	strSet.insert("ali");
 	if(strSet.count("mostafa"))
		cout<<"Mostafa is in Set\n";
 
	set<string>::iterator strIt = strSet.lower_bound("mostafa");
	strIt = strSet.find("mostafa"); // return NULL if not and points to it if it is there
	cout<<*strIt<<endl;

/* ****************************** MAPS (log(n))************************************* */
	map<string, int> mp;
	mp["Mostafa"] = 10;
	mp["Saleh"] = 20;
// You could iterate on map and set normally like vector. Never to change keys while iterating
	vector< pair<string, int> > mptov( all(mp) ); //will convert map to vector of pairs
	for (i = 0; i < (int)mptov.size(); ++i)
		cout<<mptov[i].first<<" "<<mptov[i].second<<"\n";
 
/* *********************************** STRINGS *********************************** */
	string str1("Hello");
	string str2 = "World!";  //both are fine 
	cout<<str2.substr(2)<<endl;
	cout<<str2.substr(2,2)<<endl; //second parameter is the LENGTH of the substring not the index
	cout<<"Mostafa at: "<<(int)str1.find("Mostafa")<<"\n"; //CASTING IS IMPORTANT, return -1 if not in
	cout<<"Hello at: "<<(int)str1.find("Hello",0)<<"\n"; //second number is start index
	cout<<str1.find_last_of("Hwz")  <<"\n"; //search from of  one these character is first found
	cout<<str1.find_first_of("hwo", 1) <<"\n"; //from index 4
	cout<<str1.find_first_of("hoo", 4, 6) <<"\n"; //from index 4 to index 6
	cout<<str1.find_first_not_of("aic") <<"\n"; //first not found

// convert from string class to c string and it is inverse
	char array[4] = "hey";
	string t = array;
	const char* st = t.c_str();
//erase 
	str2.erase(3);//remove from index 4 to end
	str1.erase(1,2);//remove from 2 elements starting from index 1
	cout<<str2<<endl;
	cout<<str1<<endl;

/* ****************** STRING STREAM ************************ */
	vector<int> v7;
	v7.push_back(30);
	v7.push_back(10);
	v7.push_back(7);
	ostringstream oss;
	copy (all(v7), ostream_iterator<int>(oss, ","));   // convert vector to string
	cout<<oss.str()<<"\n";
	istringstream iss("10 20 30");  // helps much in reparsing input blocks
	int x;
	while(iss>>x) // same if cin stream
	cout<<"Readed X "<<x<<"\n";

/* *****************************  Value array ******************************* */
	int a1[] = {1, -2, 3, -4, -5};
	valarray<int> va1 (a1, 5);    // NOT (val, val+5)
	valarray<int> va2 = abs (va1); //absoulte for all array (similar to matlab)
	cout<<va2.sum()<<"\n";
	valarray<int> va3 = 2 * (va1 + va2);
	printValArray(va3, "va3: ");	
	valarray<bool> va4 = (va1 == va2);
	cout<<va4.min()<<" "<<va4.max()<<"\n";
	double arr[] = {0, 1, 2, 3};
	valarray<double> va5(arr, 4);
	valarray<double> va6 = 2.0 * (va5 + 3.0 * va5);  // 2.0 NOT 2 - same types used, not MIXED
	cout<<pow(2.0, va5).sum()<<"\n"; // 2^4 -1
	cout<<pow(va5, 2.0).sum()<<"\n";
	cout<<pow(2.5 * va5, va6).sum()<<"\n";

	return 0;
}	