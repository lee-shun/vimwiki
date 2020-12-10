/*******************************************************************************
 *   Copyright (C) 2020 Lee Ltd. All rights reserved.
 *
 *   @Filename: template_template_param.cpp
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
#include <vector>

using namespace std;
template <typename T, template <class> class Container> class XCls {
private:
  Container<T> c;

public:
  XCls() {}
};

template <typename T> using Vec = std::vector<T, allocator<T>>;

int main(int argc, char **argv) { 
    XCls<string,Vec> c1;
    return 0; }
