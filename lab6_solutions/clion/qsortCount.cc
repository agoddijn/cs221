#include <iostream>
#include <ctime>
#include <cstdlib>

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
  int p = randint(1, n);
  comps += n;
  qc(n-p-1);
  qc(p+1);
}

#define NN 10
#define REPS 1

int main(int argc, char *argv[]) {
  for(int i = 0; i < REPS; i++) {
    qc(NN);
    //srand(time(0));

    // change the following code
    // x = new int[NN];
    // for (int i=0; i<NN; ++i) {
    //   x[i] = rand() % NN;
    // }

    //quicksort(0, NN-1);
    // for (int i=0; i<NN; ++i) {
    //   std::cout << x[i] << " ";
    // }
  }
  std::cout << comps / REPS << std::endl;

  delete[] x;
  return 0;
}
