#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{   
   setuid( 0 );
   char* path="PATH=/bin:/usr/bin:/sbin:/usr/sbin:/tools/bin";
   if (0 != access("/tools/bin/", F_OK)) {
      if (ENOENT == errno) {
         path="PATH=/bin:/usr/bin:/sbin:/usr/sbin";
      }
   }   
   char* const argv[] = {"/usr/bin/setup_install_dirs", NULL};
   char* const env[] = {path, "IFS= \t\n", NULL};
   return execve(argv[0], argv, env);
}
