///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/CppMultithreadingCookbook/CppMultithreadingCookbookExport.h"

#include "CppMultithreadingCookbook.h"

#ifndef BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC

namespace CppMultithreadingCookbook
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC
