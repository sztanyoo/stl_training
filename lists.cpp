#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <functional>
#include <stdexcept>

using namespace std;

template <typename Container>
void printContainer(const Container& c)
{
  // http://www.cplusplus.com/reference/iterator/
  for( typename Container::const_iterator i = c.begin(); i != c.end(); ++i )
  {
    cout << *i << endl;
  }
}

void listDemo()
{
  // http://www.cplusplus.com/reference/list/
  list<int> l;
  l.push_back(11);
  l.push_back(16);
  l.push_back(13);
  l.push_back(42);
  l.push_back(14);


  cout << "The original list:\n";
  printContainer< list<int> >( l ); 




  cout << "The first element in the list is: " << l.front() << endl;


  // inserting an element before 13
  cout << "Insert 777 before 13" << endl;
  list<int>::iterator i13 = find( l.begin(), l.end(), 13);
  if ( l.end() != i13 )
  {
    l.insert( i13, 777 );
  }
  
  printContainer< list<int> >( l ); 
 

  cout << "The size of the list is: " << l.size() << endl
       << "maximum number of elements in the list:          " << l.max_size() << endl;


  // Iterator validity
  // TODO


  /* FORWARD LIST */

  // http://www.cplusplus.com/reference/forward_list/
  forward_list<int> fl;
  fl.push_front( 42 );
  cout << "maximum number of elements in the forward_list: " << fl.max_size() << endl;

  // size? -- no size() member
  forward_list<int>::iterator first = fl.begin();
  forward_list<int>::iterator last = fl.end();

  cout << "The distance is: " << distance(first,last) << '\n';


}


int main()
{
  listDemo();



  return 0;
}

