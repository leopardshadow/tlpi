

/*
    Notes. 
    * initialized data segments
        * global initialized data ... Case 1 below
        * static initialized data ... Case 4 below
        * read from executables and load into the memory
    * "un"initialized data segments (bss)
        * global "un"initialized data ... Case 2 below
        * static "un"initialized data ... Case 3 below
        * no need to allocate space when store on the disk
        * memory are allocared when executing and initialize to 0
    * stack:
        * local variables
        * arguments
        * return value
    * heap
        * dynamically allocate memory    
*/


/*
    Case 1
    global initialized data
    396K for a.out
*/
// int global_init_data[100000] = {0, 1, 2};


/*
    Case 2
    global uninitialized data
    4.2K for a.out
*/
// int global_uninit_data[100000];


int main(int argc, char const *argv[])
{
    /*
        Case 3
        uninitialized data are allocated and set to 0 during execution time
        4.2K for a.out
    */
    // static int static_uninit_data[100000];

    /*
        Case 4
        initialized data
        396K for a.out
    */
    // static int static_init_data[100000] = {0, 1, 2};


    return 0;
}
