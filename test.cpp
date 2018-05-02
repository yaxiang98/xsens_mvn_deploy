#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int time_code = 6678;
  double float_time_code;
  int sec, nanosec;
  int to_stamp_sec;
  int a;
  int hour, min;
  float_time_code = (double)time_code/1;
 
  while(1) {
    printf("time_code = %d, float_time_code = %lf", time_code, float_time_code);
    printf("time_code = %d\n", time_code);
    if (time_code <= 99999) { //if time_code < 99.999;
    float_time_code /= 1000;
    
    sec = (int)float_time_code;
    
    nanosec = (int)((float_time_code - sec)*1000);
    
    to_stamp_sec = sec;
    printf("sec = %d, nsec = %d\n", to_stamp_sec, nanosec);
    }
  }
  return 0;
}
