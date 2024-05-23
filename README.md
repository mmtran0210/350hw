Skip to content
Navigation Menu
mmtran0210
/
350hw

Type / to search

Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
Breadcrumbs350hw
/project1/
Directory actions
Go to file
t
Add file
More options
Latest commit
mmtran0210
mmtran0210
push now
9e282b2
 · 
5 months ago
History
Breadcrumbs350hw
/project1/
Folders and files
Name	Last commit message	Last commit date
parent directory
..
output_keep
push now
5 months ago
CSCE350Project_Tran_My.zip
push now
5 months ago
InputFileGenerator.cpp
push now
5 months ago
Makefile
push now
5 months ago
README
push now
5 months ago
Tran_My_QuickSort.cpp
push now
5 months ago
Tran_My_averageExecutionTime.txt
push now
5 months ago
Tran_My_executionTime.txt
push now
5 months ago
Tran_My_plotAverageExecutionTime.png
push now
5 months ago
input1000_20.txt
push now
5 months ago
input100_9.txt
push now
5 months ago
input10_5.txt
push now
5 months ago
output1000_20.txt.txt
push now
5 months ago
output100_9.txt.txt
push now
5 months ago
output10_5.txt.txt
push now
5 months ago
README
QuickSort Performance Analysis

This project includes a C++ implementation of the QuickSort algorithm and additional functions to measure and analyze its performance. The QuickSort algorithm is a fast, recursive, non-stable sort algorithm that works by selecting a ‘pivot’ element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

Features:

-   QuickSort Algorithm: Implements the QuickSort algorithm using a median-of-three method for pivot selection.

-   Performance Measurement: Records the execution time for sorting arrays of various sizes.

-   Data Aggregation: Groups execution times by input size and calculates the average execution time for each group.

-   Formatted Output: Writes execution times and average times to text files in a human-readable tabular format.

Pseudocode

```
Function QuickSort(Array, Low, High)
    If Low < High Then
        PivotIndex = Partition(Array, Low, High)
        
        QuickSort(Array, Low, PivotIndex - 1)
        
        QuickSort(Array, PivotIndex + 1, High)
    End If
End Function

Function Partition(Array, Low, High)
    Pivot = MedianOfThree(Array[Low], Array[High], Array[(Low + High) / 2])
    
    Swap Pivot with Array[High]
    
    Index = Low - 1
    
    For J from Low to High - 1
        If Array[J] < Pivot Then
            Increment Index
            Swap Array[Index] with Array[J]
        End If
    End For
    
    Swap Array[Index + 1] with Array[High]
    
    Return Index + 1
End Function

Function MedianOfThree(A, B, C)
    If A is between B and C Then Return A
    
    If B is between A and C Then Return B
    
    Return C
End Function

Function DoQuickSort(InputFile, OutputFile, TimeFile)
    Read numbers from InputFile into Array
    
    StartTimer
    
    QuickSort(Array, 0, ArraySize - 1)
    
    StopTimer
    
    Write ArraySize and ExecutionTime to TimeFile
    
    Write sorted Array to OutputFile
End Function

Function WriteAverageTimesFile(TimeFile, AvgTimeFile)
    Read ExecutionTimes from TimeFile
    
    Group ExecutionTimes by InputSize
    
    For Each InputSize Group
        Calculate AverageTime
        Write InputSize and AverageTime to AvgTimeFile
    End For
End Function

Function WriteExecutionFile(UnformattedTimeFile, FormattedTimeFile)
    Read ExecutionTimes from UnformattedTimeFile
    
    Write Headers to FormattedTimeFile
    
    For Each ExecutionTime
        Write InputSize and ExecutionTime in Table Format to FormattedTimeFile
    End For
End Function

```

Complilation Instructions: 

1> First, you will need to compile the InputFileGenerator.cpp file. This file generates the 75 input files in total with the input size of 10, 100 and 1000 (25 each) for the QuickSort algorithm. To compile this file, run the following command in the terminal:

```g++ -o InputFileGenerator InputFileGenerator.cpp```

then run the executable with the following command:

```./InputFileGenerator```

2> Next, you will

``` make all ```

This will run the Makefile which would compile the QuickSort.cpp file with 25 input files of size 10, 100 and 1000 each in the same directory.

Sample Output:

root@tramtrukemtrinh:/mnt/c/Users/mimin/Desktop/350hw/project1# make
g++ -Wall -std=c++11 -o Tran_My_QuickSort Tran_My_QuickSort.cpp
./Tran_My_QuickSort input10_0.txt input10_0.out ExecutionTime_Data.txt
./Tran_My_QuickSort input10_1.txt input10_1.out ExecutionTime_Data.txt
./Tran_My_QuickSort input10_10.txt input10_10.out ExecutionTime_Data.txt
./Tran_My_QuickSort input10_11.txt input10_11.out ExecutionTime_Data.txt
./Tran_My_QuickSort input10_12.txt input10_12.out ExecutionTime_Data.txt

QuickSort will be executed on 25 input files with each input size, and will keep appending data on the ExecutionData.txt file.

ExecutionData.txt then will be used to generate the ExecutionTime.txt file in the table format, and calculate the average execution time for each input size output to averageExecutionTime.txt

Check Tran_My_averageExecutionTime.txt and Tran_My_ExecutionTime.txt for the sample output.

3> After you done, run 

``` make clean ```

And Boom! Everything is gone! Run again if needed.
350hw/project1 at main · mmtran0210/350hw
