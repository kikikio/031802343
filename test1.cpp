# include <iostream>
# include <map>
# include <cstdlib>
# include <cmath>
# include "count_min_sketch.hpp"
# include <stdio.h>
using namespace std;

int main(int argc, char **argv) 
{
  CountMinSketch c(0.01, 0.1);
  for(int i=0;i<10;i++)c.update("hello",i);
  c.update("world",1);
  printf("%d\n",c.estimate("hello"));
  printf("%d\n",c.estimate("world"));
  
}


