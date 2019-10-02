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
  printf(1, "%d-%d-%d %d:%d:%d\n", r.day, r.month, r.year, r.hour, r.minute, r.second);

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


