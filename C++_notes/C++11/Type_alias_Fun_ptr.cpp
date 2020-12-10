/*******************************************************************************
 *   Copyright (C) 2020 Lee Ltd. All rights reserved.
 *
 *   @Filename: Type_alias_Fun_ptr.cpp
 *
 *   @Author: lee-shun
 *
 *   @Email: 2015097272@qq,com
 *
 *   @Date: 2020-12-08
 *
 *   @Description:
 *
 ******************************************************************************/

#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
typedef void (*func)(int, int);
#ifdef __cplusplus
}
#endif

void hello(int a, int b) {
  std::cout << a << " and " << b << std::endl;
  return;
}

typedef void (*func2)(int, int);

int main(int argc, char **argv) {

  using func1 = void(*)(int, int);
  /* typedef func2 void(*)(int,int); ERROR */

  func fun = &hello;
  func fun1 = hello;

  func1 func_ = hello;

  fun(3, 5);
  fun1(3, 5);
  func_(3,5);

  printf("cpp --version %ld", __cplusplus);

  return 0;
}
