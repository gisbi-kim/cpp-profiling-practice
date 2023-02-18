/*

gperftools src로 부터 최신버전 설치
https://transang.me/how-to-install-and-use-gperftools/

실제 사용법
1. cmake .. and make -j
2. LD_PRELOAD=/usr/local/lib/libprofiler.so CPUPROFILE=test.prof ./my_program
3. google-pprof --pdf my_program test.prof > profiling.pdf
(google-pprof generally installed by go under /home/gskim/go/bin/pprof)

시각화 그래프에서 별도로 등장하지 않는 함수명의 경우 count되지 못한 매우 짧은
시간을 소요한 경우.

*/

#include <algorithm>
#include <cstdlib>
#include <iostream>

constexpr int N = 10000000;
int *data;

void make_data() { data = new int[N]; }

void rand_data(int k) {
   for (int _k = 0; _k < k; _k++) {
      for (int i = 0; i < N; i++) {
         data[i] = std::rand();
      }
      std::cout << _k << "th sorting ..." << std::endl;
   }
}

void sort_data() { std::sort(data, data + N); }

void disp_result(int k) {
   const int m = 1000;
   for (int _k = 0; _k < k; _k++) {
      for (int i = 0; i < m; i++) {
         auto where = i + _k * m;
         std::cout << where << ": " << data[where] << std::endl;
      }
   }
}

void delete_data() { delete[] data; }

void run() {
   make_data();
   rand_data(50);
   sort_data();
   disp_result(1000);
   delete_data();
}

int main() {
   run();
   return 0;
}
