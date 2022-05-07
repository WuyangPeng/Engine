@ingroup group_AssistTools_Documentation

----------------------------
辅助工具库模块

辅助工具库（AssistTools）封装了引擎的辅助工具库层调用。 
辅助工具库位于引擎的第六层，可以调用引擎中除了System、Framework的其他库，并使用boost工具库。

----------------------------
1.	Helper（帮助）

辅助工具模块帮助模块。

（1）用户宏：用于是否使用静态库及其他用户设定。
（2）辅助工具库宏：辅助工具库模块所使用的宏，按需要添加。

----------------------------
2.  GenerateProjects（生成项目）

生成各编译器引擎项目文件。

 （1）引擎项目文件：实现生成引擎项目文件的辅助类。

 ----------------------------
3.  FeaturesImporter（特征导入）

对象和材质文件导入类。用于加载.obj、.mtl等的实现文件。现在，将这些文件包含在需要加载.obj和.mtl的应用程序中，顶层的调用是：
#include "ObjLoader.h"
std::string path = <包含.obj文件的文件夹的路径>;
std::string filename = <.obj文件的名字>;
ObjLoader loader{ path, filename };
ObjLoader类的接口允许你从指定的.obj文件和.mtl文件访问这些信息。
 
 （1）obj加载：实现obj文件的加载。
 （2）mtl加载：实现mtl文件的加载。

 ----------------------------
4.  BmpColorToGray（灰态Bmp颜色）

包含灰态Bmp颜色。

（1）灰态Bmp颜色：封装灰态Bmp颜色。

----------------------------
5.  BmpToTf（Bmp转换tf）

包含Bmp转换tf。
 
（1）Bmp转换tf：封装Bmp转换tf。

----------------------------
6.  FxCompiler（Fx编译器）

包含Fx编译器。

（1）Fx编译器：封装Fx编译器。

----------------------------
 