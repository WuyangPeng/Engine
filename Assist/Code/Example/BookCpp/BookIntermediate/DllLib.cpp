///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/05 0:33)

#include "Example/BookCpp/BookIntermediate/BookIntermediateExport.h"

#include "BookIntermediate.h"

#ifndef BUILDING_BOOK_INTERMEDIATE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_INTERMEDIATE_STATIC

namespace BookIntermediate
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_INTERMEDIATE_STATIC
