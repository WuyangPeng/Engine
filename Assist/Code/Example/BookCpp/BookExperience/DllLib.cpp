///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/15 23:51)

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
