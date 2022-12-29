#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "PrioQueue.h"

using namespace std;

int main(int argc, char *argv[]){
ArgumentManager am (argc, argv);
string input = am.get("input");
string output = am.get("output");

//ifstream input("input1.txt");
//ofstream ofs("output1.txt");

ifstream ifs(input);
ofstream ofs(output);
string line;
string task;
double val;
PrioQueue q;
while (getline(ifs, line))
{
    if(line.empty()){
        continue;
    }else{
        int i=0;
        while(!isdigit(line[i])){
            i++;
        }
        val = stod(line.substr(i, line.find('\2')));
        task = line.substr(0, i-1);
        q.enqueue(task,val);
    }

}
q.print(ofs);
return 0;


}
