// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2019/12/31 14:51)

// 系统库（System）封装了操作系统相关的特殊需求（包括Window，Linux，Macintosh和Android）。
// 系统库位于引擎的最底层，不允许关联引擎中的其他库，工具库只允许关联freeglut工具库，不关联其他工具库。
// 使用函数或类的静态成员函数来封装，且绝大部分函数被定义成noexcept。结果可能通过参数返回。
// 当各平台使用的函数差别较大时，可能会舍去返回值或部分参数强制使用默认值。部分平台可能没有正确的实现。

// 系统库包含以下模块：
// 1.	Helper（帮助）
// 2.   EnumOperator（枚举运算符）
// 3.	SystemOutput（系统输出）
// 4.	DynamicLink（动态链接）
// 5.	CharacterString（字符串）
// 6.	Console（控制台）
// 7.	MemoryTools（内存工具）
// 8.	Threading（线程）
// 9.	Time（时间）
// 10.	FileManager（文件管理）
// 11.	Security（安全性）
// 12.	Network（网络）
// 13.	Window（Window）
// 14.	UserInterface（界面）
// 15.	Com（Com）
// 16.	OpenGL（OpenGL）
// 17.	DirectX（DirectX）
// 18.	Linux（Linux）
// 19.	Macintosh（Macintosh）
// 20.	Android（Android）

#include "System/SystemExport.h"

#include "System/System.h"

#ifndef BUILDING_SYSTEM_STATIC

	#include "DllLib.h"

#else // BUILDING_SYSTEM_STATIC

	namespace System
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_SYSTEM_STATIC 