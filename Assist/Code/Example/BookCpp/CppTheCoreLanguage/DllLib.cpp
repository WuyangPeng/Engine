///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:26)

#include "Example/BookCpp/CppTheCoreLanguage/CppTheCoreLanguageExport.h"

#include "CppTheCoreLanguage.h"

#ifndef BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

namespace CppTheCoreLanguage
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_THE_CORE_LANGUAGE_STATIC
