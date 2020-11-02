#include "pthread_impl.h"

static int __mythos_get_pthread_tid(pthread_t pthread)
{
  return pthread->tid;
}

weak_alias(__mythos_get_pthread_tid, mythos_get_pthread_tid);
