## 第一章

- 为什么不能进行`str=="abc"`这样的比较？

字符串其实就是char类型的数组，也就是说它不是标量，所以在C语言中不能使用"=="一下子对数组里的所有元素进行比较



- 所谓指针，不就是地址吗，无论是指向int的指针还是指向double的指针，有必要区分吗？

思考一下这段代码：

```c
void *hoge_p = &hoge;
printf("%d\n", *hoge_p);
```

当然会报错，因为你没有告知该起始地址上保存的是什么类型的数据，不知道应该在哪里停止读取。不同的数据类型的长度一般不同，如int可能占据4个字节，而double占据8个字节。



- 无论有没有[]，在表达式中，数组名会被解读成指向数组**初始**元素的**指针**。

例如array[i]会被解读成*(array+i)，array是起始元素地址。

例外情况：见第三章笔记。



- 为什么存在**指针运算**这种奇怪的功能？

原因之一是受到了其祖先B语言的影响。

B是没有类型的语言，可以使用的类型只有word类型(总之就是整数类型)，指针也被当成整数处理的，而B语言的地址也是以word为单位的，所以对指针(单纯表示地址的整数)加1，指针就会自动指向数组的下一个元素。为了继承这一点，C语言里引入了“对指针加1，则指针前进该指针所指向的类型的长度”这一规则。

另一个原因是，以前使用指针运算能写出更高效的程序，但现在随着编译器的不断优化，不论是使用数组还是指针运算，效率上都不会有什么明显的差异。大部分情况下，生成的机器码是完全相同的。

------



## 第二章

- 在朴素的实现方式中，可变参数**实参**的值是**从后往前**按顺序压栈的。

比较典型的`printf()`函数，例如`printf("%d, %s\n",100,str);`此时重要的是不论压进多少个参数，总能找到第一个参数的地址。所以应该先压进`str`和`100`，然后才是指向`"%d, %s\n"`的指针，再加上恢复信息、返回地址、局部变量等等。此时只要能够获取第一个参数，就能够通过解析字符串`"%d, %s\n"`知晓后面还有多少个什么样的参数，然后可以按顺序将它们依次取出。



- `malloc()`是系统调用吗？

先说说系统调用，系统调用是指要求操作系统帮我们去执行某些操作的特别的函数集。

在UNIX中，`printf()`最终会调用称为`write()`的系统调用。不只是`printf()`，`putchar()`和`puts()`最终调用的也是`write()`。

回到`malloc()`函数，实际上，它是标准库函数，不是系统调用。



- `sizeof(struct)`的大小**不是**简单地将结构体各个成员字节数目相加的结果。

根据硬件(CPU)的不同，对不同的数据类型能够配置的地址是有限制的。就算能够配置，某些CPU的效率也会变差。在这种情况下，编译器会进行适当的边界调整(对齐，**alignment**)，向结构体插入适当的填充(**padding**)。填充有时会被放在结构体的末尾。



- 结构体的成员名称在运行时也是**缺失**的。

对结构体成员的引用是通过距离结构体起始地址的偏移量(字节单位的距离)实现的。而并不是通过名称(如item)引用结构体成员的。因此，如果结构体的定义发生了变化，就必须将使用这个结构体的源文件全部重新编译一遍。

------

## 第三章

- 针对如下代码，

```c
int array[3];
int (*array_p)[3];
```

`array_p=&array`和`array_p=array`(后者等价于array_p=&array[0])是不同的，后者编译器会发出警报。一个是指向int的数组(元素个数为3)的指针，一个是执行int的指针，两者是完全不同的类型。

自加1后，前者指针前进12字节(假设int类型长度是4字节)，而后者只前进4字节，指向下一个元素。



- 传递二维数组作为函数参数时，`void func(int hoge[3][2])`和`void func(int hoge[][2])`其实都是`void func(int (*hoge)[2])`的语法糖，意思完全相同。



- “在表达式中，数组会被解读为指针的例外情况”：

1. 当作为sizeof运算符的操作数时。
2. 当作为&运算符的操作数时。如`int (*array_p)[3]=&array;`。
3. 初始化数组时的字符串字面量。如`char str[10]="ascendho;"`，由于字符串字面量是”char的数组“，所以在表达式中一般会解读为”指向char的指针“，但关于初始化char的数组时的字符串字面量，编译器通常会将其特别解释为花括号内字符分段书写的初始化列表的省略形式。请注意它与初始化char的指针时的字符串字面量的区别。

------

