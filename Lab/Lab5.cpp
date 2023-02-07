#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
const int MAX = 1000;
const char CLASS[] = {'A', 'B', 'C'};

struct Points
{
   int x, y;
   char c;

   double dist(Points q)
   {
      return sqrt(pow(x - q.x, 2) + pow(y - q.y, 2));
   }
};

void generate_point(std::vector<Points> &chart)
{
   for (int i = 0; i < 1000; i++)
   {
      chart[i].x = rand() % 10000;
      chart[i].y = rand() % 10000;
      chart[i].c = CLASS[rand() % 3];
      // std::cout << "x= " << chart[i].x << "y= " << chart[i].y << "c= " << chart[i].c << std::endl;
   }
   return;
}

int part(std::vector<Points> &v, Points user, int low, int high)
{
   Points piv = v[low];

   while (low < high)
   {
      while (low < high && piv.dist(user) < v[high].dist(user))
      {
         high--;
      }
      v[low] = v[high];
      while (low < high && piv.dist(user) > v[low].dist(user))
      {
         low++;
      }
      v[high] = v[low];
   }
   v[low] = piv;
   return low;
}

void qs(std::vector<Points> &v, Points user, int low, int high)
{
   if (low >= high)
   {
      return;
   }
   int pivot = part(v, user, low, high);
   qs(v, user, low, pivot - 1);
   qs(v, user, pivot + 1, high);
}

void print_vector(const std::vector<Points> &chart)
{
   for (int i = 0; i < chart.size(); i++)
   {
      std::cout << "x= " << chart[i].x << "y= " << chart[i].y << "c= " << chart[i].c << std::endl;
   }
}

int main()
{
   srand(time(0));
   std::cout << "Enter X and Y" << std::endl;
   Points user;
   std::cin >> user.x;
   std::cin >> user.y;

   std::vector<Points> chart(1000);
   generate_point(chart);
   qs(chart, user, 0, chart.size() - 1);
   print_vector(chart);
   int A = 0;
   int B = 0;
   int C = 0;
   for (int i = 0; i < 5; i++)
   {
      if (chart[i].c == 'A')
      {
         A++;
      }
      else if (chart[i].c == 'A')
      {
         B++;
      }
      else
      {
         C++;
      }
   }
   if (A >= B && A >= C)
   {
      user.c = 'A';
   }
   else if (B > A && B >= C)
   {
      user.c = 'B';
   }
   else
   {
      user.c = 'C';
   }

   std::cout << "user point is"
             << "x= " << user.x << "y= " << user.y << "c= " << user.c << std::endl;

   return 0;
}
