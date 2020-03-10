音效库模块

1.	Macro（宏）

音效库模块系统宏。
 待实现功能：
（1）用户宏：用于是否使用静态库、是否使用OpenAL等用户设定。
（2）音效库宏：音效库模块所使用的宏，按需要添加。

2.	Configuration （配置）

封装了音效库的配置。
 待实现功能：
（1）配置策略：对音效库的相关策略进行封装，按需要后续添加。 
（2）配置解析：对音效库配置进行解析，返回配置的策略。

3.	Interface（接口）

封装了音效库的统一接口。 处理模式使用策略类，分别代表使用哪种音效库。 
 待实现功能：
（1）调用：实现各音效库的统一调用接口。

4.	CsynUtil（CsynUtil） 

封装了调用CsynUtil代码的实现。
待实现功能：
（1）调用：实现CsynUtil的调用接口。

5.	DirectSound（DirectSound）

封装了调用DirectSound代码的实现。
待实现功能：
（1）调用：实现DirectSound的调用接口。
 
6.	ogg（ogg）

封装了调用ogg代码的实现。
待实现功能：
（1）调用：实现ogg的调用接口。
 
7.	OpenAL（OpenAL） 

封装了调用OpenAL代码的实现。
待实现功能：
（1）调用：实现OpenAL的调用接口。

8.	vorbis（vorbis）

封装了调用vorbis代码的实现。
待实现功能：
（1）调用：实现vorbis的调用接口。

9.	FreeAlut（FreeAlut）

封装了调用FreeAlut代码的实现。
待实现功能：
（1）调用：实现FreeAlut的调用接口。

