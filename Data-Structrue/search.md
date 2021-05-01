# 查找

## 基本概念

+ 查找：在数据集合中寻找满足某种条件的数据元素的过程。
+ 查找表（查找结构）：用于查找的数据集合，由同一类型的数据元素或记录组成。
+ 关键字：数据元素中唯一标识该元素的某个数据项的值，使用基于关键字的查找，查找结果应该唯一。
+ 静态查找表：只查找符合条件的数据元素。
+ 动态查找表：出来要查找，还要进行删除或插入，除了查找速度还要考虑插入删除操作是否方便。
+ 查找长度：查找运算中，需要对比关键字的次数。
+ 平均查找长度ASL：所有查找过程中进行关键字比较次数的平均值。$ASL=\sum_{i=1}^nP_iC_i$。其中$P_i$表示查找第i个元素的概率，$C_i$表示查找第i个元素的查找长度。

## 静态查找

### 顺序查找

又称为线性查找，常用于线性表，从头到尾逐个查找。

ASL查找成功为$\dfrac{1+2+3+\cdots+n}{n}=\dfrac{n+1}{2}$，ASL查找失败为$n+1$，时间复杂度为$O(n)$。

#### 顺序表

可以让数据集变为有序的，这样对比数据大小也可以知道是否还需要遍历从而减少查找时间。这样顺序结构从逻辑上就变成了一个二叉树结构，左子树代表小于，右子树代表大于，所有数据结点挂在右子树上。

查找情况还要比普通乱序查找加上一个大于最大值的情况。

ASL查找失败为$\dfrac{1+2+3+\cdots+n+n}{n+1}=\dfrac{n}{2}+\dfrac{n}{n+1}$。成功结点的查找长度等于自身所在层数，失败结点的查找长度等于其父结点所在层数。

#### 查找概率不等

当数据元素查找概率不等时，可以将查找概率更大的元素放在靠前的位置，以减少大概率元素被遍历的时间。

但是此时数据是乱序的，所以查找失败的时间复杂度与没有优化的是一样的。

### 折半查找

也称为二分查找，只适用于有序的顺序表，链表无法适用。

定义三个指针，low指向查找范围的最小值，high指向查找范围的最大值，mid指向查找范围的中间值，$mid=\lfloor(low+high)/2\rfloor$。（也可以向上取整，过程会有所不同）

查找时，首先计算出mid判断是否相等，若查找值小于mid的值，则将high赋值为mid的值，若查找值大于mid，则将low赋值为mid的值，重新计算mid。这样就可以不断二分区间来查找，从而加快迭代。当查找最后low>high则查找失败。

ASL查找成功为$\dfrac{1+2+3+\cdots+n}{n}=\dfrac{n+1}{2}$，ASL查找失败为$n+1$，时间复杂度为$O(n)$。

#### 折半查找判定树

若当前low和high有奇数个元素，则mid分割后左右两部分元素个数相等。

若当前low和high有奇数个元素，则mid分割后左部分元素个数小于右部分一个。

折半查找判定树一定是一个平衡二叉树。只有最下面一层不满，元素个数为n时树高与完全二叉树相等$h=\lceil\log_2(n+1)\rceil$。

且折半查找判定树也是一个二叉排序树，失败结点=n+1（成功结点的空链域节点数）。

ASL查找成功查找失败都一定小于折半查找树的树高，时间复杂度为$O(\log_2n)$。

## 动态查找
