## How to use 
1. cmake .. and make -j
2. LD_PRELOAD=/usr/local/lib/libprofiler.so CPUPROFILE=test.prof ./my_program
3. google-pprof --pdf my_program test.prof > profiling.pdf
