#include<stdio.h>

int main()
{	
	float time_code = 20833;
	int sec = 0;
	int nanosec;
		time_code = time_code/1000;
		sec = (int)time_code;
		nanosec = (int)((time_code - (float)sec)*1000);
		//conver to time stamp
		//*stamp_sec = sec;
		//*stamp_nsec = nanosec;
		printf("sec = %d\n", sec);
		printf("nanosec = %d\n", nanosec);
		printf("time_code = %f\n", time_code);
		return 0;
}
