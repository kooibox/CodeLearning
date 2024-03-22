#include <stdio.h>
#include <time.h>
#include <stdint.h>

typedef struct{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
}bj_time;

bj_time timestamp_to_bj_time(time_t timestamp);
time_t bj_time_to_timestamp(bj_time time);

int main()
{
	time_t rawtime = 1592932611;//时间戳, time_t是长整型变量
	struct tm *info;//指向tm结构的指针
	char buffer[80];
	info = localtime( &rawtime );
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
	printf("格式化的日期 & 时间 : |%s|\n", buffer );
	printf("------------------\n");
	bj_time time;
	time = timestamp_to_bj_time(rawtime);
	/* 2020-6-25 19:11:50 */
	printf("%d-%d-%d %d:%d:%d\r\n",
		time.year, time.month, time.day, time.hour, time.minute, time.second);
	time_t timestamp;
	timestamp = bj_time_to_timestamp(time);
	printf("the timestamp of given time: %d\r\n", timestamp);
	return(0);
}


bj_time timestamp_to_bj_time(time_t timestamp)
{
	bj_time time;
	
	struct tm *t;
	
	/* 加上8个小时 */
	timestamp += 8*60*60;
	t = localtime(&timestamp);
	
	/* 日期修正 */
	time.year = t->tm_year + 1900;
	time.month = t->tm_mon + 1;
	time.day = t->tm_mday;
	time.hour = t->tm_hour;
	time.minute = t->tm_min;
	time.second = t->tm_sec;
	
	return time;
}

time_t bj_time_to_timestamp(bj_time time)
{
	struct tm t;
	time_t timestamp = 0;
	
	/* 日期修正 */
	t.tm_year = time.year - 1900;
	t.tm_mon = time.month - 1;
	t.tm_mday = time.day;
	t.tm_hour = time.hour;
	t.tm_min = time.minute;
	t.tm_sec = time.second;
	
	timestamp = mktime(&t) - 8*60*60;
	return timestamp;
}


