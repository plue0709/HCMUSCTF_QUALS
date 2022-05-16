#include <iostream>
using namespace std;

unsigned short int & HIWORD(unsigned int & x) {
    return *(reinterpret_cast<unsigned short int *>(&x) + 1);
}

unsigned short int & LOWORD(unsigned int & x) {
    return *(reinterpret_cast<unsigned short int *>(&x) + 0);
}
unsigned int hash(unsigned a1)
{
  unsigned int v2; // [rsp+10h] [rbp-4h]
  unsigned int v3; // [rsp+10h] [rbp-4h]
  unsigned int v4; // [rsp+10h] [rbp-4h]
  unsigned int v5; // [rsp+10h] [rbp-4h]

  v2 = 73244475 * ((73244475 * (a1 ^ HIWORD(a1))) ^ ((73244475 * (a1 ^ HIWORD(a1))) >> 16));
  v3 = (8 * (HIWORD(v2) ^ v2)) ^ HIWORD(v2) ^ v2;
  v4 = (16 * ((v3 >> 5) + v3)) ^ ((v3 >> 5) + v3);
  v5 = (((v4 >> 17) + v4) << 25) ^ ((v4 >> 17) + v4);
  return (v5 >> 6) + v5;
}

int main() {
  unsigned int a1 =573785173;
  unsigned int v2; // [rsp+10h] [rbp-4h]
  unsigned int v3; // [rsp+10h] [rbp-4h]
  unsigned int v4; // [rsp+10h] [rbp-4h]
  unsigned int v5;
  unsigned int result;
  while(a1>268435456)
  {
  	a1 = hash(a1);
}
    result = a1;
  	cout<<"Result = "<<result<<endl;

  return 0;	
}
