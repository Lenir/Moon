#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <vector>
using namespace std;
template <typename T>
void printVector(vector<T> const &vec){
  typename vector<T>::const_iterator it;
  for(it=vec.begin(); it != vec.end(); it++){
    cout<<*it<<endl;
  }
}
int main(void){
  vector<int> intVector;
  vector<string> strVector;
  strVector.push_back("Alpha");
  strVector.push_back("Beta");
  strVector.push_back("Chalie");
  strVector.push_back("Delta");
  strVector.push_back("Epsilon");
  intVector.push_back(0);
  intVector.push_back(1);
  intVector.push_back(2);
  intVector.push_back(3);
  intVector.push_back(4);
  intVector.push_back(5);
  intVector.erase(intVector.begin()+1,intVector.begin()+3);
  printVector(intVector);
  printVector(strVector);
  return 0;
}
