//****THIS IS ALL NEW********

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
  return('%m/%d/%y%n %H:%M:%S')

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

