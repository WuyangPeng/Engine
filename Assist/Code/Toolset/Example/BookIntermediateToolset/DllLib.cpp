///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/24 16:24)

#include "Toolset/Example/BookIntermediateToolset/BookIntermediateToolsetExport.h"

#include "BookIntermediateToolset.h"

#ifndef BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

namespace BookIntermediateToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC
