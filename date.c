//****THIS IS ALL NEW********
//EMMA PRAGER
//CS 450
//PA  2

#include "types.h"
#include "user.h"
#include "date.h"

int
main(int argc, char *argv[])
{
  struct rtcdate r;

  if (date(&r)) {
    printf(2, "date failed\n");
    exit();
  }

  // your code to print the time in any format you like...
  day_name(r.year,r.month,r.day);	// day of the week
  month_name(r.month);  	// month of the year
  printf(1," %d",r.day); 	 // date
  printf(1," %d:%d:%d",r.hour,r.minute,r.second);  // current time
  printf(1," UTC");  // UTC format
  printf(1," %d\n",r.year);  // prints current year

  exit();
}

int sys_date(void)
{
  struct rtcdate *r;
  if(argptr(0, (void*)&r, sizeof(r)) < 0)
    return -1;
  cmostime(r);
  return 0;
}


