///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/12 0:06)

#include "Toolset/Example/BookACEToolset/BookACEToolsetExport.h"

#include "BookACEToolset.h"

#ifndef BUILDING_BOOK_ACE_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ACE_TOOLSET_STATIC

namespace BookACEToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ACE_TOOLSET_STATIC
