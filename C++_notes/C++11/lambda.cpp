/*******************************************************************************
 *   Copyright (C) 2020 Lee Ltd. All rights reserved.
 *
 *   @Filename: lambda.cpp
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
int main(int argc, char **argv) {

  /**
   * inline function
   */
  auto L = [] { std::cout << "hello lambda" << std::endl; };
  L();

  int id = 0;

  /**
   * ATTENTION:
   * 和函数不同
   * lambda实际上是做出了一种“算法对象”，有可能封装数据，
   * f1被创建时id被复制进来，
   * f2被创建时id被引用
   */
  auto f1 = [id]() mutable {
    std::cout << "id:" << id << std::endl;
    ++id;
  };

  /* 此处若没有mutable id无法++， 因为是引用 */
  auto f2 = [&id]() mutable {
    std::cout << "id:" << id << std::endl;
    ++id;
  };

  id = 42;
  f1();
  f1();
  f1();
  std::cout << id << std::endl;

  id = 42;
  f2();
  f2();
  f2();
  std::cout << id << std::endl;
  return 0;
}
