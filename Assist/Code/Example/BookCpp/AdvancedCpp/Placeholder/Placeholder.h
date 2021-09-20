///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.1.0 (2021/01/21 23:03)

#ifndef ADVANCED_CPP_PLACEHOLDER_PLACEHOLDER_H
#define ADVANCED_CPP_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/AdvancedCpp/AdvancedCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AdvancedCpp
{
    class ADVANCED_CPP_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ADVANCED_CPP_PLACEHOLDER_PLACEHOLDER_H
