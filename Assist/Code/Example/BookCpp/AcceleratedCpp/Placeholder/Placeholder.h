///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:32)

#ifndef ACCELERATED_CPP_PLACEHOLDER_PLACEHOLDER_H
#define ACCELERATED_CPP_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/AcceleratedCpp/AcceleratedCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace AcceleratedCpp
{
    class ACCELERATED_CPP_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // ACCELERATED_CPP_PLACEHOLDER_PLACEHOLDER_H
