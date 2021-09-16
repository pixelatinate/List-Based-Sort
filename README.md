# List-Based-Sort
A sorting utility called "volsort" mimics the UNIX tool "sort" with a twist: the underlying container must be a linked list.
Written by Carter Earheart-Brown (@cearhear), Stephanie Hill (@stephhill77), Swasti Mishra (@pixelatinate), and Katie Nuchols (@knuchols).

You can read more about this project here: 
https://web.eecs.utk.edu/~semrich/cs302-21/assignments/proj02.html

You can compile using "make test". 

Below is a table including the time it takes to run each sort and how much memory they use. 

| Mode     | Size    | Elapsed Time   | Memory Consumption  |
|:--------:|:-------:|:--------------:|:-------------------:|
| STL      | 10      |  0:00.00              |        3232 kB             |
| STL      | 100     |  0:00.00              |       3244 kB              |
| STL      | 1k      |  0:00.00              |      3484 kB               |
| STL      | 10k     |  0:00.01              |      4232 kB               |
| STL      | 100k    |  0:01.15              |  10324 kB                 |
| STL      | 1M      |  0:13.59             |   17713 kB                  |
| STL      | 10M     |  2:39.32              |   760420 kB                  |
| QSORT    | 10      |  0:00.00              |  3488 kB                  |
| QSORT    | 100     |  0:00.00              |  3408 kB                  |
| QSORT    | 1k      |  0:00.00             |  3488 kB                   |
| QSORT    | 10k     |  0:00.01              | 4316 kB                    |
| QSORT    | 100k    |  0:01.09              | 11268 kB                   |
| QSORT    | 1M      |  0:13.79              | 81748 kB                    |
| QSORT    | 10M     |  2:28.96              | 785080 kB                    |
| MERGE    | 10      |    0:00.00     |      3272 kB        |
| MERGE    | 100     |    0:00.00     |      3300 kB        |
| MERGE    | 1k      |    0:00.00     |      3308 kB        |
| MERGE    | 10k     |    0:00.02     |      4120 kB        |
| MERGE    | 100k    |    0:00.20     |      9748 kB        |
| MERGE    | 1M      |    0:19.05     |     66000 kB        |
| MERGE    | 10M     |    3:11.14     |    628324 kB        |
| QUICK    | 10      |    0:00.00            |  3488 kB                   |
| QUICK    | 100     |    0:00.00            |  3252 kB                   |
| QUICK    | 1k      |    0:00.00            |  3400 kB                   |
| QUICK    | 10k     |    0:00.01            |  3888 kB                   |
| QUICK    | 100k    |    0:01.16             |  9544 kB                   |
| QUICK    | 1M      |    0:18.60            |   65904 kB                  |
| QUICK    | 10M     |    17:35.57            |          628980 kB           |


**Discuss the relative performance of each sorting method and explain the differences.**
Each sorting method approaches elements in a different way. STL Sort should technically be better in every single way than Qsort. STL Sort is safer, easier to implement, and intuitive. The only time we think you should use Qsort is when you're working in a C-only project. Merge Sort, however, is great for lists. Merge Sort is particularly useful because along with all the benefits of STL Sort, Merge Sort is stable and uses divide and conquer, meaning it can handle basically any amount of data. Quick Sort is the array-optimized counterpart of Merge Sort, and while effecient, requires a lot of memory. The best kind of sorting really depends on the project and what you're trying to achieve. 

**What do these results reveal about the relationship between theoretical complexity discussed in class and actual performance?**
In our experience, the sorting method we will use the least actually handled 10M the best. Qsort is not often a suggested method but was the fastest. It did use up the most memory, which is consistent with what we learned in class. That may have also been because we implememnted it with a vector instead of an array, however. 

**In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode.**
What we found is that the STL Sort is the perfect jack-of-all-trades. On average, it seems to do everything well and is easy to implement, but with more elements and in more complex situations, other methods (namely Merge and Quick Sort) handle sorting more effectively. Merge, for example, is more cognizant of lists. But choosing the right sorting algorithm comes down to evaluating what you want to do (General applications? Lists? Arrays?), and what you need to prioritize (Easiness to implement? Memory? Speed?).