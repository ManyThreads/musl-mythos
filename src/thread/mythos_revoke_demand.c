#include "pthread_impl.h"

static int __mythos_revoke_demand_hook(pthread_t pthread)
{
  return -1;
}

weak_alias(__mythos_revoke_demand_hook, mythos_revoke_demand_hook);

int mythos_revoke_demand(pthread_t pthread)
{
  int res = mythos_revoke_demand_hook(pthread);
  if(res == 0){
    munmap(pthread->map_base, pthread->map_size);
  }
  return res;
}

