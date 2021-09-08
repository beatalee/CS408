# 指令系统习题

## 指令格式

### 操作码

**例题** 一个计算机系统采用$32$位单字长指令，地址码为$12$位，若定义了$250$条二地址指令，则还可以有()条单地址指令。

$A.4K$

$B.8K$

$C.16K$

$D.24K$

解：$D$。地址码为$12$位，二地址指令的操作码长度为$32-12-12=8$位，已定义了$250$条二地址指令，$2^8-250=6$，所以上一层多出了六种地址给单地址指令，即可以设计出单地址指令$6×2^{12}=24K$条。

**例题** 设指令字长固定为$16$位，试设计一套指令系统满足：

1）有$15$条三地址指令

2）有$12$条二地址指令

3）有$62$条一地址指令

4）有$32$条零地址指令

解：若要$15$条三地址码，而一共要从零到三位的地址，指令字长为$16$位。

所以三地址指令的操作码长度为4位，这样一共能得到$0000\,A_1\,A_2\,A_3$到$1110\,A_1\,A_2\,A_3$一共$15$条三地址指令。$1111\,A_1\,A_2\,A_3$用于拓展。

而对于二地址指令，一定是以$1111$开始的，由于只需要$12$条二地址指令，拓展$A_1$作为操作码时，只用用到$0000$到$1011$就可以了，即而二地址指令从$1111\,0000\,A_2\,A_3$到$1111\,1011\,A_2\,A_3$。剩下的$1100$、$1101$、$1110$、$1111$都是以$11$开头，所以$1111\,11XX\,A_2\,A_3$用于拓展。

对于一地址指令，需要$62$条，而$2$的八次方减一为$63$，所以一地址指令的操作码至少还要拓展$8$位。最后的$1111$一定要留给下一位拓展，所以$1111\,1100$到$1111\,1110$的后面一个操作码$A_2$范围是$0000$到$1111$全部用到，这样一共满足了$3×16=48$个，还需要$14$个，所以$1111\,1111$只还要满足$14$个就可以了，即$1111\,1111\,0000$到$1111\,1111\,1101$，$1111\,1111\,1110$和$1111\,1111\,1111$留给零地址指令拓展。

而零地址指令必然以$1111\,1111\,111$开头，正好余下$1+4=5$位也就是$32$条零地址指令可以满足条件。

## 指令寻址方式

### 转移指令

**例题** 某机器有一个标志寄存器，其中有进位/借位标志$CF$、零标志$ZF$、符号标志$SF$和溢出标志$OF$，条件转移指令$bgt$（无符号整数比较大于时转移）的转移条件是()。

$A.CF+OF=1$

$B.\overline{SF}+ZF=1$

$C.\overline{CF+ZF}=1$

$D.\overline{CF+SF}=1$

解：$C$。首先问的是转移条件，无符号整数比较大于时转移，就是指两个无符号整数比较大小，假设两个无符号整数$A$和$B$，$bgt$指令会将$A$和$B$进行比较，也就是将$A$和$B$相减。若$A>B$则转移，则$A-B$肯定无进位/借位，也不为$0$（为$0$时表示两数相等），因此$CF$和$ZF$均为$0$，选$C$。其余选项中用到了符号标志$SF$和溢出标志$OF$，不是大于的条件，显然应当排除。

### 相对寻址

注意相对寻址时，在取指时$PC$会自动加一（指令长度或机器字长）。

**例题** 某机器指令字长为$16$位，主存按字节编址，取指令时，每取一个字节$PC$自动加$1$。当前指令地址为$2000H$，指令内容为相对寻址的无条件转移指令，指令中第一个字节为操作码，第二个字节为形式地址，当前形式地址为$40H$。

1）求取指令后及指令执行后$PC$内容。

2）若要求转移到$1F00H$，求形式地址的内容。

解：

1）$PC$指向当前指令地址$2000H$，因为第一个字节为操作码，所以$PC$指向$2001H$，第二个字节为形式地址，$PC$指向$2002H$。由于形式地址为$40H$，所以实际地址$EA=(PC)+A=2002H+40H=2042H$。

所以执行指令后跳转到所指向的地址$2042H$。

2）

即$(PC)+A=2002H+A=1F00H$。即$=1EFFH+1H-2002H=FEFDH+1H=FEFEH$。

### 堆栈寻址

**例题** 堆栈寻址方式中，设$A$为累加器，$SP$为堆栈指示器，$M_{SP}$为$SP$指示的栈顶单元。若进栈操作的动作是$(A)\rightarrow M_{SP}$，$(SP)-1\rightarrow SP$，则出栈操作的动作应为()。

$A.(M_{SP})\rightarrow A,(SP)+1\rightarrow SP$

$B.(SP)+1\rightarrow SP,(M_{SP})\rightarrow A$

$C.(SP)-1\rightarrow SP,(M_{SP})\rightarrow A$

$D.(M_{SP})\rightarrow A,(SP)-1\rightarrow SP$

解：$B$。进、出堆栈时对栈顶指针的操作顺序是不同的，进栈时是先压入数据$(A)\rightarrow M_{SP}$，后修改指针$(SP)-1\rightarrow SP$，说明栈指针是指向栈顶的空单元的，所以出栈时要先修改指针$(SP)+1\rightarrow SP$，然后才能弹出数据$(M_{SP})\rightarrow A$，否则弹出的是一个空元素。

## 指令集计算机

**例题** 下列指令系统的特点中，有利于实现指令流水线的是()。

Ⅰ.指令格式规整且长度一致

Ⅱ.指令和数据按边界对齐存放

Ⅲ.只有$Load/Store$指令才能对操作数进行存储访问

$A.$仅Ⅰ、Ⅱ

$B.$仅Ⅱ、Ⅲ

$C.$仅Ⅰ、Ⅲ

$D.$I、Ⅱ、Ⅲ

解：$D$。指令长度一致、按边界对齐存放、仅$Load/Store$指令访存，这些都是$RISC$的特征，它们使取指令、取操作数的操作简化且时间长度固定，能够有效地简化流水线的复杂度。