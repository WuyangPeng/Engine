///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/05 0:33)

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
