# List-Based-Sort
A sorting utility called "volsort" mimics the UNIX tool "sort" with a twist: the underlying container must be a linked list.

| Mode     | Size    | Elapsed Time   | Memory Consumption  |
|----------|---------|----------------|---------------------|
| STL      | 10      |                |                     |
| STL      | 100     |                |                     |
| STL      | 1k      |                |                     |
| STL      | 10k     |                |                     |
| STL      | 100k    |                |                     |
| STL      | 1M      |                |                     |
| STL      | 10M     |                |                     |
| QSORT    | 10      |                |                     |
| QSORT    | 100     |                |                     |
| QSORT    | 1k      |                |                     |
| QSORT    | 10k     |                |                     |
| QSORT    | 100k    |                |                     |
| QSORT    | 1M      |                |                     |
| QSORT    | 10M     |                |                     |
| MERGE    | 10      |    0:00.00     |      3272 kB        |
| MERGE    | 100     |    0:00.00     |      3300 kB        |
| MERGE    | 1k      |    0:00.00     |      3308 kB        |
| MERGE    | 10k     |    0:00.02     |      4120 kB        |
| MERGE    | 100k    |    0:00.20     |      9748 kB        |
| MERGE    | 1M      |    0:19.05     |     66000 kB        |
| MERGE    | 10M     |    3:11.14     |    628324 kB        |
| QUICK    | 10      |                |                     |
| QUICK    | 100     |                |                     |
| QUICK    | 1k      |                |                     |
| QUICK    | 10k     |                |                     |
| QUICK    | 100k    |                |                     |
| QUICK    | 1M      |                |                     |
| QUICK    | 10M     |                |                     |
