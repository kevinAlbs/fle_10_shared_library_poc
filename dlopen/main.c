#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
   const char *path = "/Users/kevin.albertson/code/fle_10_shared_library_poc/dlopen/cmake-build/libexample_library.dylib";
   void *handle = dlopen(path, RTLD_NOW);
   if (handle == NULL)
   {
      fprintf(stderr, "dlopen error: %s\n", dlerror());
      return EXIT_FAILURE;
   }
   dlerror(); /* clear error */
   int (*ptr)(int) = dlsym(handle, "example_function");
   if (ptr == NULL)
   {
      char *errmsg = dlerror();
      if (errmsg != NULL)
      {
         fprintf(stderr, "dlsym error: %s\n", errmsg);
         return EXIT_FAILURE;
      }
   }
   int retVal = ptr(0);
   printf("After calling ptr(0) got back %d\n", retVal);
   dlclose(handle);
}