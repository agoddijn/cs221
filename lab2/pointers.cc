#include <iostream>

int main () {
  int x = 5, y = 15;
  int * p1, *p2;
	// value of	x	y	p1	p2
  p1 = &x;
  std::cout << "x: " << x << ", y: " << y << ", p1: " << p1 << ", p2: " << p2 << std::endl;
  p2 = &y;
  std::cout << "x: " << x << ", y: " << y << ", p1: " << p1 << ", p2: " << p2 << std::endl;
  *p1 = 6;
  std::cout << "x: " << x << ", y: " << y << ", p1: " << p1 << ", p2: " << p2 << std::endl;
  *p1 = *p2;
  std::cout << "x: " << x << ", y: " << y << ", p1: " << p1 << ", p2: " << p2 << std::endl;
  p2 = p1;
  std::cout << "x: " << x << ", y: " << y << ", p1: " << p1 << ", p2: " << p2 << std::endl;
  *p1 = *p2+10;
  std::cout << "x: " << x << ", y: " << y << ", p1: " << p1 << ", p2: " << p2 << std::endl;
  return 0;
}
