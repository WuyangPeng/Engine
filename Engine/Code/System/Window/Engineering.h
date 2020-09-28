//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 10:54)

#ifndef SYSTEM_WINDOW_ENGINEERING_H
#define SYSTEM_WINDOW_ENGINEERING_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace System
{
    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetEngineeringSuffix();
    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetEngineeringExeSuffix();
    [[nodiscard]] String SYSTEM_DEFAULT_DECLARE GetEngineeringDirectory();

    // 这个模板没有定义，用来让编译器打印某个型别的类型。
    template <typename T>
    class TypeDisplayer;
}

#endif  // SYSTEM_WINDOW_ENGINEERING_H
