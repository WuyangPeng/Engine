///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/23 9:11)

#ifndef BOOK_NETWORK_PROGRAMMING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
#define BOOK_NETWORK_PROGRAMMING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H

#include "Toolset/Example/BookNetworkProgrammingToolset/BookNetworkProgrammingToolsetDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookNetworkProgrammingToolset
{
    class BOOK_NETWORK_PROGRAMMING_TOOLSET_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // BOOK_NETWORK_PROGRAMMING_TOOLSET_PLACEHOLDER_PLACEHOLDER_H
