#include <unistd.h>

int main()
{
  char* const argv[] = {"/sbin/ldconfig", "-v", NULL, NULL};
  char* const env[] = {NULL, NULL};
  return execve(argv[0], argv, env);
}
