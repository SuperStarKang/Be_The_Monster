#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int is_prime(int n) {
   if (n == 1)
      return (0);
   for (int i=2; i<=n/i; i++) {
      if (n % i == 0)
         return (0);
   }
   return (1);
}

void   recur(int N, int idx, char *num) {
   if (idx == N) {
      cout<<num<<endl;
      return ;
   }
   for (int i=1; i<=9; i++) {
      num[idx] = i + '0';
      if (is_prime(atoi(num))) {
         recur(N, idx+1, num);
		 for (int j=idx; j<N; j++)
		 	num[j] = '\0';
      }
   }
}

int main(void) {
   int N;
   cin>>N;

   char num[N];
   for (int i=0; i<=N; i++)
      num[i] = '\0';
   recur(N, 0, num);
   return 0;
}
