#include <errno.h>
#include <sys/unistd.h>
#include "usbd_cdc_if.h"

int _write(int file, char *data, int len){
  if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
   {
      errno = EBADF;
      return -1;
   }

   int status = CDC_Transmit_FS(data, len);

   // return # of bytes written - as best we can tell
   return (status == USBD_OK ? len : 0);
}
