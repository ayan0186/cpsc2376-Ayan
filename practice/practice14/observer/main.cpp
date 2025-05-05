#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

class GradeBook {
    std::vector<int> grades;
    std::vector<std::function<void(const std::vector<int>&)>> listeners;
    void notify() {
        for(auto& f : listeners) f(grades);
    }
public:
    void subscribe(const std::function<void(const std::vector<int>&)>& f) {
        listeners.push_back(f);
    }
    void addGrade(int g) {
        grades.push_back(g);
        notify();
    }
    void changeGrade(std::size_t idx,int g) {
        if(idx<grades.size()) grades[idx]=g;
        notify();
    }
};

class AverageTracker {
    double avg = 0;
public:
    AverageTracker(GradeBook& gb) {
        gb.subscribe([this](const std::vector<int>& v){
            if(v.empty()) return;
            avg = std::accumulate(v.begin(),v.end(),0.0) / v.size();
            std::cout << "Average updated: " << avg << '\n';
        });
    }
};

class Notifier {
    int threshold;
public:
    Notifier(GradeBook& gb,int thresh=60):threshold(thresh){
        gb.subscribe([this](const std::vector<int>& v){
            if(v.empty()) return;
            int last=v.back();
            if(last<threshold)
                std::cout<<"Email sent to student@example.com (grade "<<last<<")\n";
        });
    }
};

int main(){
    GradeBook gb;
    AverageTracker avg(gb);
    Notifier note(gb);

    std::cout<<"Commands: a <grade> | c <index> <grade> | q\n";
    char cmd;
    while(std::cin>>cmd && cmd!='q'){
        if(cmd=='a'){
            int g; std::cin>>g;
            gb.addGrade(g);
        }else if(cmd=='c'){
            std::size_t idx; int g; std::cin>>idx>>g;
            gb.changeGrade(idx,g);
        }
    }
}
