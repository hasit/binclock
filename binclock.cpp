#include<time.h>
#include<unistd.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string converttobin(int);

int main()
{
  time_t now;
  int seconds, minutes, hours;
  int binseconds, binminutes, binhours;
  struct tm* mytime;

  while(1)
    {
      now = time(0);
      mytime = localtime(&now);

      seconds = mytime->tm_sec;
      minutes = mytime->tm_min;
      hours = mytime->tm_hour;
      
      std::cout<<"H:"<<converttobin(hours)<<" M:"<<converttobin(minutes)<<" S:"<<converttobin(seconds)<<"\r"<<std::flush;
      sleep(1);
    }
 
  return 0;
}

string converttobin(int t)
{
  string bin;
  do
    {
      if((t&1)==0)
	{
	  bin += "0";
	}
      else
	{
	  bin += "1";
	}
      t >>= 1;
    } while (t);

  reverse(bin.begin(), bin.end());
  return bin;
}
