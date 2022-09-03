#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <ctime>
using namespace std;
class Contestant
{
public:
    string name;
    double score;
    Contestant() {}
    Contestant(string n, double s)
    {
        name = n;
        score = s;
    }
};

int main(int argc, const char *argv[])
{
    vector<Contestant> cV;
    for (int i = 0; i < 5; i++)
    {
        string cName = "ABCDE";
        cName = cName[i];
        Contestant c(cName, 0);
        cV.push_back(c);
    }

    deque<int> scoreD;
    srand((unsigned int)time(NULL));
    for (vector<Contestant>::iterator it = cV.begin(); it != cV.end(); it++)
    {
        int score;
        for (int i = 1; i <= 10; i++)
        {
            score = rand() % 41 + 60;
            scoreD.push_back(score);
        }
        sort(scoreD.begin(), scoreD.end()); 
        scoreD.pop_front();
        scoreD.pop_back();
        int sum = 0;
        for (deque<int>::iterator it = scoreD.begin(); it != scoreD.end(); it++)
        {
            sum += (*it);
        }
        (*it).score = (double)sum / scoreD.size() + 2;

        cout << "the final score of contestant " << (*it).name << " is " << (*it).score << endl;
    }

    return 0;
}