///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:20)

#ifndef CPP_MULTITHREADING_COOKBOOK_PLACEHOLDER_H
#define CPP_MULTITHREADING_COOKBOOK_PLACEHOLDER_H

#include "Example/BookOperatingSystem/CppMultithreadingCookbook/CppMultithreadingCookbookDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CppMultithreadingCookbook
{
    class CPP_MULTITHREADING_COOKBOOK_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CPP_MULTITHREADING_COOKBOOK_PLACEHOLDER_H
