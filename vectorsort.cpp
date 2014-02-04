#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>

using namespace std;

template <typename T>
bool myCompare( T a, T b )
{
  return a % 2;
}

template <typename Container>
void printContainer(const Container& c)
{
  // http://www.cplusplus.com/reference/iterator/
  for( typename Container::const_iterator i = c.begin(); i != c.end(); ++i )
  {
    cout << *i << endl;
  }
}

// What if we can use c++0x?
template <typename Container>
void printContainer0x11(const Container& c)
{
  // what is auto and cbegin?
  //for ( auto i = c.cbegin(); i != c.cend(); ++i )
  //{
  //  cout << *i << endl;
  //}

  for ( auto elem : c )
  {
    cout << elem << endl;
  }
}

void vectorDemo()
{
  // http://www.cplusplus.com/reference/vector/
  vector<int> v;
  v.push_back(11);
  v.push_back(16);
  v.push_back(13);
  v.push_back(42);
  v.push_back(14);


  cout << "The original vector:\n";
  printContainer< vector<int> >( v ); 




  cout << "The first element in the vector is: " << v.front() << endl;



  
  cout << "The 3rd element in the vector is: " << v[2] << endl;
 
 
 
  /* Accessing elements */ 
  
  // at() or operator[] ?
  try
  {
    cout << "The element at index 12 is: " << v.at(12) << endl;
  }
  catch ( const std::out_of_range& e )
  {
    cerr << "ERROR: Out of Range error: " << e.what() << endl;
  }


  cout << "The element at index 1200 is: " << v[1200] << endl;




  cout << "The size of the vector is: " << v.size() << endl
       << "maximum number of elements: " << v.max_size() << endl
       << "allocated storage capacity is: " << v.capacity() << endl;




  /* Finding elements */


  vector<int>::iterator a = find( v.begin(), v.end(), 13 );

  cout << "*a is: " << *a << endl;
  cout << "2 after a is: " << *(a+2) << endl;
  cout << "*++a is: " << *++a << endl;
  cout << "*a++ is: " << *a++ << endl;




  /* SORTING */


  // http://www.cplusplus.com/reference/algorithm/sort/
  sort( v.begin(), v.end(), myCompare<int> );

  cout << "The vector ordered by myCompare:" << endl;
  printContainer< vector<int> >( v ); 


  sort( v.begin(), v.end(), greater<int>() );
  cout << "The vector ordered by greater<int>:" << endl;
  printContainer0x11< vector<int> >( v ); 

}


int main()
{
  vectorDemo();



  return 0;
}
