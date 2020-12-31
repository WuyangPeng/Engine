//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/09/28 11:52)

// 核心工具库（CoreTools）封装了引擎的核心工具。以实现 RAII（资源获取即初始化）和RRID（资源释放即析构）。
// 核心工具库位于引擎的第二层，只允许调用引擎中的System库，并使用boost和stlsoft工具库。
// 主要有类不变式、断言、单例基类、异常、文件管理、日志管理和单元测试框架等工具类。

#include "CoreToolsExport.h"

#include "CoreTools.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CORE_TOOLS_STATIC

namespace CoreTools
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // BUILDING_CORE_TOOLS_STATIC