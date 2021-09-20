///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/27 12:45)

#ifndef CPP_STL_PLACEHOLDER_PLACEHOLDER_H
#define CPP_STL_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/CppSTL/CppSTLDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CppSTL
{
    class CPP_STL_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CPP_STL_PLACEHOLDER_PLACEHOLDER_H
