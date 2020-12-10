/*******************************************************************************
 *   Copyright (C) 2020 Lee Ltd. All rights reserved.
 *
 *   @Filename: test_range_for_loop.cpp
 *
 *   @Author: lee-shun
 *
 *   @Email: 2015097272@qq,com
 *
 *   @Date: 2020-12-08
 *
 *   @Description:
 *
 *******************************************************************************/

#include <iostream>
#include <vector>
int main(int argc, char **argv) {
  for (int i : {2, 4, 5, 6, 7, 8, 2, 1, 1}) {
    std::cout << "i= " << i << std::endl;
  }
  typedef typename std::pair<double,double> pai;
  std::vector<pai> vec;
  for (int i = 0; i < 10; ++ i) {
      vec.push_back(pai(i,i));
  }
  for (pai elem : vec)
  {
    std::cout << "vec1= " << elem.first << std::endl;
    std::cout << "vec2= " << elem.second << std::endl;
  }
  return 0;
}
