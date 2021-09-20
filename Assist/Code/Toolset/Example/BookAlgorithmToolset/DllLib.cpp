///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/15 1:02)

#include "Toolset/Example/BookAlgorithmToolset/BookAlgorithmToolsetExport.h"

#include "BookAlgorithmToolset.h"

#ifndef BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

namespace BookAlgorithmToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC
