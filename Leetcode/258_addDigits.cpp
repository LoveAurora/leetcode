#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int addDigits(int num)
{
  if(num<10)
    return num;
  

  while (num > 10)
  {
    num = toString(num);
  }

  return num;
}
int toString(int num)
{
  string str = to_string(num);
  int len = str.length(), sum = 0;
  for (int i = 0; i < len; i++)
  {
    sum += (int)str[i];
  }
  return sum;
}