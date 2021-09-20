///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/30 11:03)

#ifndef MORE_PROGRAMMING_PEARLS_PLACEHOLDER_PLACEHOLDER_H
#define MORE_PROGRAMMING_PEARLS_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/MoreProgrammingPearls/MoreProgrammingPearlsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace MoreProgrammingPearls
{
    class MORE_PROGRAMMING_PEARLS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MORE_PROGRAMMING_PEARLS_PLACEHOLDER_PLACEHOLDER_H
