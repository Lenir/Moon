#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
using namespace std;
string globalVar = "Yup, I am!";
int main(void){
  pid_t pid;
  pid = fork();
  string localVar = "Yes, I am!";
  if(pid == -1){
    perror("fork failed!");
  }else if(pid == 0){
    cout<<"Child Process : Local Var, Global Var, are you there?"<<endl;
    cout<<"  LocalVar : "<<localVar<<", and I'm on addr "<<&localVar<<endl;
    cout<<"  GlobalVar : "<<globalVar<<", and I'm on addr "<<&globalVar<<endl;
  }else{
    cout<<"Parent Process : Local Var, Global Var, are you there?"<<endl;
    cout<<"  LocalVar : "<<localVar<<", and I'm on addr "<<&localVar<<endl;
    cout<<"  GlobalVar : "<<globalVar<<", and I'm on addr "<<&globalVar<<endl;
    cout<<"  Child PID : "<<pid<<endl;
  }
  return 0;
}
