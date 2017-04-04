#ifdef __cplusplus
extern "C"
{
#endif
#include <stdint.h>
#include <stdlib.h>

void* allocate(size_t);
void deallocate(void*, size_t);
void memInit(void);



#ifdef __cplusplus
}
#endif
