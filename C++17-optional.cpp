
#include <iostream>
#include <optional>
using namespace std;

//function that returns empty value if divide by 0
std::optional<double> func(int a, int b)
{
 if (b==0) return std::nullopt;
 return static_cast<double> (a)/b;
}

int main() {
  int a=10, b=12;
  auto res = func(a,b);
  if(res) 
  {
    //conceptually But conceptually: it acts like a container that holds zero or one element.
    cout<<*res<<endl; //way to access optional value
    cout<<res.value()<<endl;  //way to access optional value
  }else{
    cout<<"division by zero"<<endl;
  }
  return 0;
}
