#include<algorithm>
#include<iostream>
#include<string>
#include<time.h>
#include<unistd.h>

using namespace std;

void decide_matrix(int, int, int);
void set_matrix(int, int);

int matrix[4][6];

int main()
{
  time_t now;
  int seconds, minutes, hours;
  struct tm* mytime;

  while(1)
    {
      now = time(0);
      mytime = localtime(&now);

      seconds = mytime->tm_sec;
      minutes = mytime->tm_min;
      hours = mytime->tm_hour;
      
      decide_matrix(hours, minutes, seconds);
      for(int i=0;i<4;i++)
	{
	  for(int j=0;j<6;j++)
	    {
	      cout<<matrix[i][j];
	    }
	  cout<<"\n";
	}
      cout<<"\r\x1b[A\x1b[A\x1b[A\x1b[A"<<flush;
      sleep(1);
    }
 
  return 0;
}

void decide_matrix(int h, int m, int s)
{
  set_matrix(h/10,0);
  set_matrix(h%10,1);
  set_matrix(m/10,2);
  set_matrix(m%10,3);
  set_matrix(s/10,4);
  set_matrix(s%10,5);
}

void set_matrix(int t, int o)
{
  if(t==0)
    {
      for(int i=0;i<4;i++)
	{
	  matrix[i][o]=0;
	}
    }
  else
    {
      for(int i=3;i>-1;i--)
	{
	  if((t&1)==0)
	    {
	      matrix[i][o]=0;
	    }
	  else
	    {
	      matrix[i][o]=1;
	    }
	  t>>=1;
	}
    }	  
}
