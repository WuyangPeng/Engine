///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/06 23:42)

#include "Example/BookCpp/BookTemplate/BookTemplateExport.h"

#include "BookTemplate.h"

#ifndef BUILDING_BOOK_TEMPLATE_STATIC

    #include "DllLib.h"

#else  // !BUILDING_BOOK_TEMPLATE_STATIC

namespace BookTemplate
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_BOOK_TEMPLATE_STATIC
