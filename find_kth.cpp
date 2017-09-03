/*
    题目：两个有序数组的第K大数。
*/

/*
    思路：
    传统解法，最直观的解法是O(m+n)。直接merge两个数组，然后求第K大的数字。

    如果想要时间复杂度将为O(log(m+n))。我们可以考虑从K入手。如果我们每次
    能够删除一个一定在第K个元素之前的元素，那么我们需要进行K次，但是如果
    每次我们都删除一半呢？由于两个数组都是有序的，我们应该充分利用这个信息。

    假设A B 两数组的元素都大于K/2，我们将A B两数组的第K/2个元素进行比较。比较的结果有三种情况。
    A[K/2] == B[K/2]
    A[K/2] > B[K/2]
    A[K/2] <= B[K/2]
    如果 A[K/2] < B[K/2] 意味着 A[0] 到 A[K/2] 肯定在A∪B的前k个元素中。因此我们可以放心删除A数组的这个k/2个元素。同理A[K/2] > B[K/2]。
    如果 A[K/2] == B[K/2] 说明已经找到了第K个元素，直接返回A[K/2]或者B[K/2]。

    因此可以写一个递归实现，递归终止条件是什么呢？
- A或B为空时，直接返回A[k-1] 或 B[k-1]
- 当k = 1时，返回min(A[0], B[0]) //第1小表示第一个元素
- 当A[k/2 - 1] == B[k/2 - 1] 时，返回A[k/2 - 1] 或B[k/2 - 1]
*/

int find_kth(int A[],int m, int B[], int n, int k){
    if(m > n )
        return find_kth(B, n, A, m, k);   //将元素个数较小的数组放在第一个，即数组A元素个数小于数组B
    if( m == 0)
        return B[k-1];
    if( k == 1)
        return min(A[0], B[0]);

    int ia = min(k /2, m);
    int ib = k -ia;
    if( A[ia-1] < B[ib -1])   //删除A的前k/2个数
    {
        return find_kth(A +ia, m -ia, B, n, k -ia);
    }
    else if( A[ia-1] > B[ib-1])   //删除B的前k/2个数
    {
        return find_kth(A, m, B +ib, n -ib, k -ib);
    }
    else
        return A[ia-1];
}
