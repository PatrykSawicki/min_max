//MIN_MAX Value
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int maxi, mini;
int n; // number od drawn numbers
int * tab = new int[n];

void read_data()
{
   cout << " How many numbers do you want to draw? -> ";
   cin >> n;
}

void random_generator()
{
   default_random_engine rd{static_cast<long unsigned int>(time(0))};
   mt19937 gen(rd());
   uniform_int_distribution<> distance(0,99);

   for(int i = 0; i < n; i++)
   {
      tab[i]=distance(gen);
   }
}

void process_data()
{
    mini = maxi = tab[0];

    for(int i = 1; i < n; i++)
    {
        if (tab[i] < mini)
        {
            mini = tab[i];
        }
        if (tab[i] > maxi)
        {
            maxi = tab[i];
        }
    }
}

void show_results()
{
    cout<<"\n ";
    for(int i = 0; i < n; i++)
    {
       cout<<tab[i];
       if (i < n-1) cout <<",";
    }
    cout << "."<<endl;
    cout << " \n You have drawn " << n << " numbers." << endl;
    cout << "\n mini = "<<mini<<endl;
    cout << "\n maxi = "<<maxi<<endl;
    cout << endl;
}

int main()
{
    cout << "\n Min_Max Value" << endl;
    read_data();
    random_generator();
    process_data();
    show_results();
    delete [] tab;

    return 0;
}
