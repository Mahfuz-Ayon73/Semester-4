#include <bits/stdc++.h>

using namespace std;

struct process
{
   int id;
   int burstTime;
   int priority;
   int arrivalTime;
   int changed_burstTime;
};

bool burstTimeCompare(process &a, process &b)
{
   return a.burstTime < b.burstTime;
}

bool arivalTimeCompare(process &a, process &b)
{
   return a.arrivalTime < b.arrivalTime;
}

void display(vector<process> &processes)
{
   for (int i = 0; i < processes.size(); i++)
   {
      cout << processes[i].id << " " << processes[i].burstTime << " " << processes[i].priority << " " << processes[i].arrivalTime << "\n";
   }
}

void preemptive_SJF(vector<process> &processes)
{
   int prefix = 0, len, i = 1 , before = 0 , j = 0;
   vector<process> queue, wait;

  // queue.push_back(processes[0]);

   for (int i = 0; i < processes.size(); i++)
   {
      if (processes[i].arrivalTime <= prefix)
      {
         queue.push_back(processes[i]);
      }
   }

    sort(queue.begin(), queue.end(), burstTimeCompare);

   // prefix += queue[0].burstTime;

   // len = wait.size();

    cout << "0";

   while (i < 10)
   {
      if(queue[0].changed_burstTime+prefix < processes[j+1].arrivalTime)
      {
         cout << "___" << "P" << queue[0].id << "___" << prefix;
         cout << "..."<< processes[j+1].arrivalTime;
         prefix = processes[j+1].arrivalTime;
         queue.erase(queue.begin());    
         queue.push_back(processes[j+1]);
         j++;
      }
      else if(queue[0].changed_burstTime+prefix > processes[j+1].arrivalTime)
      {
          if(prefix - processes[j+1].arrivalTime < processes[j+1].burstTime)
          {
            queue.push_back(processes[j+1]);
            prefix = processes[j+1].arrivalTime;
            cout << "___" << "P" << queue[0].id << "___" << prefix;
            queue[0].changed_burstTime = queue[0].burstTime - (processes[j+1].arrivalTime - queue[0].burstTime);
          }
      }
     

      i++;
   }
}
int main()
{
   // vector<int> burstTime , arrivalTime , priority ;
   vector<int> compltionTime;

   vector<process> processes = {
       {1, 20, 40, 0, 20},
       {2, 25, 30, 25, 25},
       {3, 25, 30, 30, 25},
       {4, 15, 35, 60, 15},
       {5, 10, 5, 100, 10},
       {6, 10, 10, 105, 10}};

   //    burstTime = {20,25,25,15,10,10};
   //    arrivalTime = {0,25,30,60,100,105};
   //    priority = {40,30,30,35,5,10};

   preemptive_SJF(processes);
}