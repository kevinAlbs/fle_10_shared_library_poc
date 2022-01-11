#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdio.h>
#include <stdlib.h>

#include <libloaderapi.h>

#include <tchar.h>

#include <strsafe.h>

/* Modified from: https://docs.microsoft.com/en-us/windows/win32/debug/retrieving-the-last-error-code */
void error_print(LPTSTR prefix) 
{ 
    // Retrieve the system error message for the last-error code
    LPVOID lpMsgBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

   _tprintf (TEXT("Error: %s (%d): %s\n"), prefix, dw, (LPTSTR) lpMsgBuf);
   LocalFree(lpMsgBuf);
}

typedef int (*example_function_type) (int);

int main()
{
// TODO: I am not sure why specifying an absolute path results in: Error: LoadLibrary failed (126): The specified module could not be found. */
// #define PATH_TO_DLL "c:\\cygwin\\home\\Administrator\\code\\fle_10_shared_library_poc\\loadlibrary\\example_library.dll"
  
   // TODO: I am not sure why AddDllDirectory and using LOAD_LIBRARY_SEARCH_USER_DIRS is not working.
   // const wchar_t* dir = L"c:\\cygwin\\home\\Administrator\\code\\fle_10_shared_library_poc\\loadlibrary";
   // DLL_DIRECTORY_COOKIE cookie = AddDllDirectory (dir);
   // if (cookie == 0) {
   //    error_print ("AddDllDirectory failed");
   //    return EXIT_FAILURE;
   // }

   HMODULE mod = LoadLibrary(TEXT("example_library.dll"));
   if (mod == NULL) {
      error_print (TEXT("LoadLibrary failed"));
      return EXIT_FAILURE;
   }

   example_function_type fn = (example_function_type) GetProcAddress (mod, "example_function");
   if (fn == NULL) {
      error_print (TEXT ("GetProcAddress failed"));
      return EXIT_FAILURE;
   }

   printf ("example_function(1) = %d\n", fn(1));

   if (!FreeLibrary (mod)) {
      error_print (TEXT("FreeLibrary failed"));
      return EXIT_FAILURE;
   }
}