///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/23 22:17)

#include "Toolset/Example/BookExperienceToolset/BookExperienceToolsetExport.h"

#include "BookExperienceToolset.h"

#ifndef BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC

namespace BookExperienceToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC
