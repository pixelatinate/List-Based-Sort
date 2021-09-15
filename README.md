# List-Based-Sort
A sorting utility called "volsort" mimics the UNIX tool "sort" with a twist: the underlying container must be a linked list.

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
| QUICK    | 10M     |                |                     |
