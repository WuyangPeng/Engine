///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/13 23:17)

#include "Example/BookCpp/CppCookbook/CppCookbookExport.h"

#include "CppCookbook.h"

#ifndef BUILDING_CPP_COOKBOOK_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_COOKBOOK_STATIC

namespace CppCookbook
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_COOKBOOK_STATIC
