///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/04/29 22:10)

#include "Example/BookOperatingSystem/BookACE/BookACEExport.h"

#include "BookACE.h"

#ifndef BUILDING_BOOK_ACE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_ACE_STATIC

namespace BookACE
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_ACE_STATIC
