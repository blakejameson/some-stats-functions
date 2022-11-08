#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

double mean(vector<double> &values);
double median(vector<double> &values);
double mode(vector<double> &values);
double population_variance(vector<double> &values);
double sample_variance(vector<double> &values);
double population_standard_deviation(vector<double> &values);
double sample_standard_deviation(vector<double> &values);



int main() {
    vector<double> values = {6,3,1};
    cout<<sample_standard_deviation(values);

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

        if (!(counts.count(value))){
            counts[value]=1;
        }
        else{
            counts[value]=counts[value] + 1;
        }
    }
    double most=0;
    double most_value=0;
    for (auto& lol: counts){
        if (lol.second>most_value){
            most=lol.first;
            most_value=lol.second;
        }
    }
    return most;
}

double population_variance(vector<double> &values){
    double average= mean(values);
    double size = values.size();
    double summation=0;
    for (double value:values){
        summation = summation + pow((value-average),2);
    }
    return summation/size;
}

double sample_variance(vector<double> &values){
    double average= mean(values);
    double size = values.size();
    double summation=0;
    for (double value:values){
        summation = summation + pow((value-average),2);
    }
    return summation/(size-1);
}

double population_standard_deviation(vector<double> &values){
    double variance = population_variance(values);
    double pop_std_dev= sqrt(variance);
    return pop_std_dev;
}

double sample_standard_deviation(vector<double> &values){
    double variance = sample_variance(values);
    double sample_std_dev= sqrt(variance);
    return sample_std_dev;

}
