///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/07 18:48)

#include "Example/BookCpp/CppTemplates/CppTemplatesExport.h"

#include "CppTemplates.h"

#ifndef BUILDING_CPP_TEMPLATES_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_TEMPLATES_STATIC

namespace CppTemplates
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_TEMPLATES_STATIC
