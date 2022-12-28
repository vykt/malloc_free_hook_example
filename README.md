# malloc_free_hook_example

### ABOUT:

An example of hooking libc's ```malloc()``` and ```free()``` calls using 
Linux's ```LD_PRELOAD``` method. In this example global variables inside 
the shared object track each pointer and it's allocated size. The size can 
then be used to print out the contents of the buffer during a call to 
```free()```.
