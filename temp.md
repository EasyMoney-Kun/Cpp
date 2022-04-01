# 这是一级标题
# [表情大全](https://blog.csdn.net/qq_40896997/article/details/106551767?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164864817516780269875672%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164864817516780269875672&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-3-106551767.142^v5^pc_search_result_cache,143^v6^control&utm_term=Markdown%E8%A1%A8%E6%83%85&spm=1018.2226.3001.4187)
# [Markdown语法](https://blog.csdn.net/afei__/article/details/80717153?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164829945416780264014551%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164829945416780264014551&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-80717153.142^v5^pc_search_quality_down,143^v6^control&utm_term=markdown%E8%AF%AD%E6%B3%95&spm=1018.2226.3001.4187)
# [视频链接](https://www.bilibili.com/video/BV1si4y1472o?spm_id_from=333.999.0.0)
## 这是二级标题
这是正文  
我要换行    
这还还是一段话  

换了一段话  **加粗** control i *斜体* control b
1. 这是列表1
2. 这是列表2
   1. 按tab键
      1. 再按一次tab键
9. 这是列表三
      
孤鸿寡鹄会更好
1.  这是列表四
* 但还是
* 电商
  * 电商
    * 地我觉得  

插入图片语法
![](2022-03-26-15-14-53.png)
![](view.jpg)  
*标题*
### 这是三级标题
$$
\lim_{x\to\infin}\frac{sin(x)}{x}=1
$$
在一段文字中插$\lim_{x\to\infin}f(x)$入公式
快捷键为 control m

## 表格
加冒号 **:** 为居中对齐 
| 小明  | 大明  | 姚明  |
| :---: | :---: | :---: |
|  1.4  |  1.5  |  1.6  |
|   2   |   1   |   2   |
快捷键 alt + shift +f 格式化代码表格
## 链接
这是一个[链接](https://blog.csdn.net/aasys848082/article/details/101713187?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1.pc_relevant_aa&utm_relevant_index=2)
## 添加代码块
```c++
#include <iostream>
using namespace std;
int main()
{
    int *Fibonacci = new int[20];
    Fibonacci[0] = 1;
    Fibonacci[1] = 1;
    for (int i = 2; i < 20; i++)
    {
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }
    for (int i = 0; i < 20; i++)
    {
        cout << Fibonacci[i] << " ";
    }
    system("pause");
    return 0;
}
```  
> 第一层
> >第二层
>detai 的
<details>


<summary>        
  
  ### Markdown
</summary>
Want to ruin the surprise?
Well, you asked for it!
\```{r}
plot(pressure)
\```
</details>