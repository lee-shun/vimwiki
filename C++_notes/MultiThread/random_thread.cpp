/*******************************************************************************
 *   Copyright (C) 2020 Lee Ltd. All rights reserved.
 *
 *   @Filename: random_thread.cpp
 *
 *   @Author: lee-shun
 *
 *   @Email: 2015097272@qq,com
 *
 *   @Date: 2020-12-10
 *
 *   @Description:
 *
 ******************************************************************************/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;
void myPrint(int inum) {
  cout << "myPrint 开始执行，线程编号=" << inum << endl;
  cout << "myPrint 结束，线程编号=" << inum << endl;
}

using namespace std;
int main(int argc, char **argv) {

  vector<thread> _threads;

  for (int i = 0; i < 10; ++i) {
    _threads.push_back(thread(myPrint, i));
  }

  /* for (auto iter = _threads.begin(); iter != _threads.end(); ++iter) { */
  /*   iter->join(); */
  /* } */

  for (auto &elem : _threads) {
    elem.join();
  }

  cout << "I love China!" << endl;

  return 0;
}
