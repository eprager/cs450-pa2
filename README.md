# Date implemented in xv6
## Files Changed

I added a system call named as date, which returns today’s date. Although it is fairly simple, many files need to be modified.

### syscall.h

Reserve a system call number for my date system call
              
      #define SYS_date 22
              
### syscall.c 

Within the array: 
              
      static int (*syscalls[ ])(void)
       
I added       
                    
      [SYS_date] sys_date,
        
So that when a system call with number 22 occurrs, the function pointed by the function pointer sys_date will be called.  I also created a function prototype for this purpose.
                
      extern int sys_date(void);
                
### usys.S

      SYSCALL(date)
          
### user.h
  
      int date(struct rtcdate*);
            
### date.c

Finally, I added the new file to implement the date based on provided skeleton code.
Most importantly, the sys_date function.
  
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

# 
# xv6 INFORMATION


xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also https://pdos.csail.mit.edu/6.828/, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (entryother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people have made contributions: Russ Cox (context switching,
locking), Cliff Frey (MP), Xiao Yu (MP), Nickolai Zeldovich, and Austin
Clements.

We are also grateful for the bug reports and patches contributed by Silas
Boyd-Wickizer, Anton Burtsev, Cody Cutler, Mike CAT, Tej Chajed, eyalz800,
Nelson Elhage, Saar Ettinger, Alice Ferrazzi, Nathaniel Filardo, Peter
Froehlich, Yakir Goaron,Shivam Handa, Bryan Henry, Jim Huang, Alexander
Kapshuk, Anders Kaseorg, kehao95, Wolfgang Keller, Eddie Kohler, Austin
Liew, Imbar Marinescu, Yandong Mao, Matan Shabtay, Hitoshi Mitake, Carmi
Merimovich, Mark Morrissey, mtasm, Joel Nider, Greg Price, Ayan Shafqat,
Eldar Sehayek, Yongming Shen, Cam Tenny, tyfkda, Rafael Ubal, Warren
Toomey, Stephen Tu, Pablo Ventura, Xi Wang, Keiichi Watanabe, Nicolas
Wolovick, wxdao, Grant Wu, Jindong Zhang, Icenowy Zheng, and Zou Chang Wei.

The code in the files that constitute xv6 is
Copyright 2006-2018 Frans Kaashoek, Robert Morris, and Russ Cox.

ERROR REPORTS

We switched our focus to xv6 on RISC-V; see the mit-pdos/xv6-riscv.git
repository on github.com.

BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run
"make". On non-x86 or non-ELF machines (like OS X, even on x86), you
will need to install a cross-compiler gcc suite capable of producing
x86 ELF binaries (see https://pdos.csail.mit.edu/6.828/).
Then run "make TOOLPREFIX=i386-jos-elf-". Now install the QEMU PC
simulator and run "make qemu".
