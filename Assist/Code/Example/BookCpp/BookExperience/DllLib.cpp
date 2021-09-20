///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/15 23:51)

#include "Example/BookCpp/BookExperience/BookExperienceExport.h"

#include "BookExperience.h"

#ifndef BUILDING_BOOK_EXPERIENCE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_EXPERIENCE_STATIC

namespace BookExperience
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_EXPERIENCE_STATIC
