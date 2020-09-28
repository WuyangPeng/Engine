//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/20 14:00)

// 系统库（System）封装了操作系统相关的特殊需求（包括Window，Linux，Macintosh和Android）。
// 系统库位于引擎的最底层，不允许关联引擎中的其他库，工具库只允许使用freeglut、gsl和boost::call_traits、boost::numeric_cast、BOOST_ASSERT工具库，不使用其他工具库。
// 使用函数或类的静态成员函数来封装，且绝大部分函数被定义成noexcept，结果可能通过参数返回。
// 当各平台使用的函数差别较大时，可能会舍去返回值或部分参数强制使用默认值，部分平台可能没有正确的实现。

// 系统库包含以下模块：
// 1.	Helper（帮助）
// 2.	SystemOutput（系统输出）
// 3.	DynamicLink（动态链接）
// 4.	CharacterString（字符串）
// 5.	Console（控制台）
// 6.	MemoryTools（内存工具）
// 7.	Threading（线程）
// 8.	Time（时间）
// 9.	FileManager（文件管理）
// 10.	Security（安全性）
// 11.	Network（网络）
// 12.	Window（Window）
// 13.	OpenGL（OpenGL）
// 14.	DirectX（DirectX）
// 15.	Linux（Linux）
// 16.	Macintosh（Macintosh）
// 17.	Android（Android）

#include "System/SystemExport.h"

#include "System/System.h"

#ifndef BUILDING_SYSTEM_STATIC

    #include "DllLib.h"

#else  // BUILDING_SYSTEM_STATIC

namespace System
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEM_STATIC 