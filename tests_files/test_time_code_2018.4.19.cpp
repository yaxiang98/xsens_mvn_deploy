#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int time_code = 6678;
  float float_time_code = 0.0;
  int sec, nanosec;
  int to_stamp_sec = 0;
  int a = 0;
  int hour, min;
  float_time_code = (float)time_code;
  printf("time_code = %d, float_time_code = %f", time_code, float_time_code);
  while(1) {
    if (time_code <= 99999) { //if time_code < 99.999;
    float_time_code /= 1000;
    //(debug) printf("float_time_code = header->time_code/1000 = %f\n", float_time_code);
    sec = (int)float_time_code;
    //(debug) printf("sec = (int)float_time_code = %d\n", sec);
    nanosec = (int)((float_time_code - sec)*1000);
    //(debug)printf("nanosec = %d\n", nanosec);
    to_stamp_sec = sec;
    printf("sec = %d, nsec = %d\n", to_stamp_sec, nanosec);
		
    //**convert to time stamp**
    // *time_stamp_sec = to_stamp_sec;
    // *time_stamp_nsec = nanosec;
    } else if (time_code > 99999 && time_code <= 9999999) { //if 99.999 < time_code <= 99:99.999;
      float_time_code = float_time_code/100000;
      min = (int)float_time_code;
      a = (int)((float_time_code - min)*100000);
      float_time_code = (float)a;
      float_time_code /= 1000;
      sec = (int)float_time_code;
      nanosec = (int)((float_time_code - sec)*1000);
      to_stamp_sec = sec + min*60;
      
      printf("min = %d, sec = %d, nsec = %d\n", min, to_stamp_sec, nanosec);
      //**convert to time stamp**
      // *time_stamp_sec = to_stamp_sec;
      //*time_stamp_nsec = nanosec;
    } else if (time_code > 9999999 && time_code <= 999999999) { //if 99:99.999 < time_code < 99:99:99.999;
      float_time_code /= 10000000;
      hour = (int)float_time_code;
      a = (int)((float_time_code - hour)*10000000);
      float_time_code = (float)a;
      float_time_code = float_time_code/100000;
      min = (int)float_time_code;
      a = (int)((float_time_code - min)*100000);
      float_time_code = (float)a;
      float_time_code /= 1000;
      sec = (int)float_time_code;
      nanosec = (int)((float_time_code - sec)*1000);
      to_stamp_sec = sec + min*60 + hour*60*60;
      
      printf("hour = %d, min = %d, sec = %d, nsec = %d\n", hour, min, to_stamp_sec, nanosec);
      //convert to time stamp
      // *time_stamp_sec = to_stamp_sec;
      // *time_stamp_nsec = nanosec;
    }
    
    //sleep(5);
  }
  return 0;

}
