// Compile with: clang -o load-csfle load-csfle.c
// Run with: ./load-csfle <path to csfle>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
   if (argc != 2)
   {
      fprintf(stderr, "Usage: ./load-csfle <path to csfle>");
      return 1;
   }
   const char *path = argv[1];
   void *handle = dlopen(path, RTLD_LAZY | RTLD_LOCAL);
   if (handle == NULL)
   {
      fprintf(stderr, "dlopen error: %s\n", dlerror());
      return EXIT_FAILURE;
   }
   dlerror(); /* clear error */
   const char *(*version_fn)(void) = dlsym(handle, "mongo_csfle_v1_get_version_str");
   if (version_fn == NULL)
   {
      char *errmsg = dlerror();
      if (errmsg != NULL)
      {
         fprintf(stderr, "dlsym error: %s\n", errmsg);
         return EXIT_FAILURE;
      }
   }

   printf("mongo_csfle_v1_get_version_str() returned %s\n", version_fn());
   dlclose(handle);
}