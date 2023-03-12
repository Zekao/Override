#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

unsigned int log_wrapper(FILE *logfile, const char *str, const char *filename)
{
  char dest[264];

  strcpy(dest, str);
  snprintf(&dest[strlen(dest)], 254 - strlen(dest), filename);
  dest[strcspn(dest, "\n")] = 0;
  fprintf(logfile, "LOG: %s\n", dest);
  return 0;
}

int main(int argc, const char **argv, const char **envp)
{
  FILE *logfile;
  FILE *stream;
  int fd;
  char buf;
  char dest[104];

  buf = -1;
  if ( argc != 2 )
    printf("Usage: %s filename\n", *argv);
  logfile = fopen("./backups/.log", "w");
  if ( !logfile )
  {
    printf("ERROR: Failed to open %s\n", "./backups/.log");
    exit(1);
  }
  log_wrapper(logfile, "Starting back up: ", argv[1]);
  stream = fopen(argv[1], "r");
  if ( !stream )
  {
    printf("ERROR: Failed to open %s\n", argv[1]);
    exit(1);
  }
  strcpy(dest, "./backups/");
  strncat(dest, argv[1], 99 - strlen(dest));
  fd = open(dest,  O_RDONLY | O_WRONLY | O_EXCL | O_CREAT );
  if ( fd < 0 )
  {
    printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
    exit(1);
  }
  while ( 1 )
  {
    buf = fgetc(stream);
    if ( buf == -1 )
      break;
    write(fd, &buf, 1uLL);
  }
  log_wrapper(logfile, "Finished back up ", argv[1]);
  fclose(stream);
  close(fd);
  return 0;
}
