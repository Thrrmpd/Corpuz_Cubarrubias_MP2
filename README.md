# Car Acceleration Programming Project

**Course**: LBYARCH

**Section**: S18-A

**Group Members**:

- Corpuz, Thara Mae P.
- Cubarrubias, Dion Mel F.

---

## Execution Time and Performance Analysis
**1. Manual Input Analysis (Correctness Test)**

When we tested the program using manual input, it helped us confirm that the assembly function was actually computing the right acceleration values. By entering our own Vi, Vf, and T values, we could see the results clearly and compare them with what we expected based on the formula. The outputs matched every time, including cases with negative acceleration, which gave us confidence that the logic was correct before moving on to larger tests. Overall, the manual mode showed that the assembly code was accurate and reliable with real user-provided data.

**2. Benchmarch Input Analysis**

The program was tested using four required input sizes:
- Input Size 10
- Input Size 100
- Input Size 1000
- Input Size 10000

Each dataset was processed 30 times, and the average execution time was recorded.

**Execution Time Results**

| Input Size    | Average Time (Seconds)                                                     | 
| ------------- | --------------------------------------------------------------- |
| 10      | 0.000000                                         | 
| 100   | 0.000000                          | 
| 1000  | 0.000004                                 | 
| 10000          | 0.000032 |

**Performance Analysis**

As the input size got bigger, the runtime increased in a steady and predictable way, which means the performance scales linearly. There were no sudden jumps or slowdowns, and the program stayed fast even with the biggest dataset. This shows that the assembly loop is well-optimized with no major bottlenecks. It's also worth noting that the correctness check passed for all input sizes, indicating that the program was not only quick, but also accurate throughout.

**3.**

**Conclusion**

Overall, the project showed that the assembly version of the acceleration calculation is both correct and very efficient. It handles small and large inputs seamlessly, and even the largest dataset completes almost rapidly. The performance increases in a linear and predictable manner, making the application appropriate for bigger workloads if required. In short, the assembly solution satisfies the criteria by being quick, scalable, and precise.



## Output and Correctness Check 
![image alt](https://github.com/Thrrmpd/Corpuz_Cubarrubias_MP2/blob/a2fc3bdec8f8082b76c0e58722788f2ff73131f1/Output%20and%20Correctness%20check.jpg)


## Video Presentation
[video link](https://drive.google.com/file/d/1H2fP1Ws2pNA6W264nc3CKpcx0utWVBlH/view?usp=sharing)
