///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/08 21:29)

#ifndef RUMINATIONS_ON_CPP_PLACEHOLDER_PLACEHOLDER_H
#define RUMINATIONS_ON_CPP_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/RuminationsOnCpp/RuminationsOnCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace RuminationsOnCpp
{
    class RUMINATIONS_ON_CPP_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // RUMINATIONS_ON_CPP_PLACEHOLDER_PLACEHOLDER_H
