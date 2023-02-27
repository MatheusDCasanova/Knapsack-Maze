Rachel is a young inspector who is also an environmentalist and actively participates in environmental awareness campaigns. After much effort and dedication, Rachel achieved her dream of joining UNICamp, the National Union of Field Inspectors.

UNICamp deals with various issues related to product quality control in different areas. One of the issues that remains unresolved is the suspicion of the misuse of pesticides in an orchard of fruit trees on a certain farm, potentially causing serious risks to the environment. Rachel promptly volunteered to help with the investigation and was responsible for collecting fruit samples from some of the trees in this orchard to be analyzed in the laboratory.

The orchard has the shape of a square grid of size N × N, where exactly one tree is present at each position (i,j) for 1 ≤ i,j ≤ N, as shown in the figure below.

The orchard is surrounded by a wall and has only two entrances, one in the upper left corner (1, 1) and another in the lower right corner (N, N). Rachel decided to enter from the upper left corner and exit from the lower right corner. Due to the internal structure of the orchard, it is not possible to walk diagonally. In addition, as the orchard is very large, Rachel wants to walk the minimum possible distance to reach the exit. Therefore, throughout the journey, she always walks either to the right or down, walking from tree to tree.

Furthermore, Rachel carries a backpack that has a limited capacity C for storing the samples. The samples must be collected in full and cannot be fractionated. Based on aerial images of the orchard, the toxicity level tij present in each tree (i,j) was estimated, as well as the weight pij that a sample would have for analysis.

From this information, Rachel needs to decide which path to follow and which samples to collect on the way so that the total toxicity collected is as high as possible, respecting the capacity of her backpack. Rachel learned that you are part of the Computer Science Institute of UNICAMP and asked for your help in writing a program to solve the problem.

Input:
The first line contains two integers N and C. Two blocks of N lines follow, where each line contains N integers. The j-th number of the i-th line of the first block represents the toxicity value tij of the tree at position (i,j), and similarly for the second block represents the weight pij of the sample.

Output:
The output consists of two lines. The first line should contain the value of the highest possible total toxicity. The second line should contain a string that represents the steps that must be taken to obtain such a value, starting from position (1, 1) until reaching position (N, N). The string is composed of the characters D, B, and C, where D means walking to the right, B means walking down, and C means collecting a sample.

Tiebreakers:
Note that there may be several different paths that result in an optimal solution. Let P and Q be two such paths (such as the blue and red paths in Figure 1a). Observing the paths from the end to the beginning (i.e., from (N, N) to (1, 1)), let c be the last cell in which P and Q differ. The optimal path should choose P or Q according to which of them maximizes the sum of the toxicities of the cells from (1, 1) to c.
