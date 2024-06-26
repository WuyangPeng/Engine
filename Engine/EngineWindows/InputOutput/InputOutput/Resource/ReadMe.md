@ingroup group_InputOutput_Documentation

----------------------------
输入输出库模块

输入输出库（InputOutput）封装了引擎的输入和输出调用。主要对输入和输出的调用接口进行封装。
输入和输出库位于引擎的第三层，只允许调用引擎中的System、CoreTools库，并使用boost和其他输入和输出相关的工具库。 

----------------------------

1.	Helper（帮助）

输入输出库模块帮助模块。
 
（1）用户宏：用于是否使用静态库及其他用户设定。
（2）输入输出库宏：输入输出库模块所使用的宏，按需要添加。

----------------------------
2.	Configuration （配置）

封装了输入输出库的配置。

（1）配置策略：对输入输出库的相关策略进行封装，按需要后续添加。 
（2）配置解析：对输入输出库配置进行解析，返回配置的策略。

----------------------------
3.	InputInterface（输入接口）

封装了输入库的统一接口。 处理模式使用策略类，分别代表使用哪种输入库。 

（1）调用：实现各输入库的统一调用接口。

----------------------------
4.	OutputInterface（输出接口）

封装了输出库的统一接口。 处理模式使用策略类，分别代表使用哪种输出库。 

（1）调用：实现各输出库的统一调用接口。

----------------------------