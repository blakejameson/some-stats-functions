#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

double mean(vector<double> &values);
double median(vector<double> &values);
double mode(vector<double> &values);
int main() {
    vector<double> values = {4,5,4,4};
    mode(values);
    return 0;
}

double mean(vector<double> &values){
    double total=0;
    int count=0;
    double average=0;
    for (double value:values){
        total += value;
        count++;
    }
    average = total/count;
    return average;
}

double median(vector<double> &values){
    int middle=0;
    double left_middle=0;
    double right_middle=0;
    int size=values.size();
    sort(values.begin(), values.end());
    if (values.size()%2==0){
        left_middle= values.at(size/2);
        right_middle = values.at((size/2)-1);
        return (left_middle+right_middle)/2;
    }
    else{
        return values.at(values.size()/2);
    }
}

double mode(vector<double> &values){
    unordered_map<double,int> counts;

    for (double value:values){
        auto result= counts.find(value);
        if ((counts.find(value)){
            counts[value]=1;
        }
        else{
            counts[value]=counts[value] + 1;
        }

    }

    for (auto lol:counts){
        cout << lol.first <<endl;
        cout << lol.second <<endl;
    }

    double most=0;

    for (auto& lol: counts){
        if (lol.second>=most){
            most=lol.first;

        }
    }
    return most;

}
