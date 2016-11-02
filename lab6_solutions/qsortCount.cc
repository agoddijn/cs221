#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

int * x;
int comps = 0;

void swap(int & a, int & b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int randint(int a, int b) {
  return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
  if (a >= b) return;
  int p = randint(a,b); // pivot
  swap(x[a], x[p]);
  int m = a;
  int i;
  // in-place partition:
  for (i = a+1; i <= b; i++) {
    comps++;
    if (x[i] < x[a])
      swap(x[++m], x[i]);
  }
  swap(x[a],x[m]);
  quicksort(a, m-1);
  quicksort(m+1, b);
}

void qc(int n) {
  if(n <= 1) return;
  int p = randint(0, n);
  comps += n;
  qc(n-p-1);
  qc(p-1);
}

float c(int n) {
  if (n <= 1) return 0;
  float sum = 0.0;
  for (int m=1; m <= n; m++)
   sum += n-1 + c(m-1) + c(n-m);
  return sum / n;
}

#define NN 10000
#define REPS 100
#define N 15

int main(int argc, char *argv[]) {
  for(int i = 0; i < N; i++) {
    // srand(time(0));
    // qc(NN);

    // x = new int[NN];
    // for (int i=0; i<NN; ++i) {
    //   x[i] = rand() % NN;
    // }

    // quicksort(0, NN-1);
    // for (int i=0; i<NN; ++i) {
    //   std::cout << x[i] << " ";
    // }

    std::cout << c(i) << "; " << i*log(i) << std::endl;
  }
  std::cout << comps / REPS << std::endl;

  delete[] x;
  return 0;
}
