///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/09 22:11)

#include "Example/BookCpp/BookAdvanced/BookAdvancedExport.h"

#include "BookAdvanced.h"

#ifndef BUILDING_BOOK_ADVANCED_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ADVANCED_STATIC

namespace BookAdvanced
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ADVANCED_STATIC
