///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/28 20:44)

#include "Example/BookCpp/CppPrimerPlus/CppPrimerPlusExport.h"

#include "CppPrimerPlus.h"

#ifndef BUILDING_CPP_PRIMER_PLUS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_CPP_PRIMER_PLUS_STATIC

namespace CppPrimerPlus
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_PRIMER_PLUS_STATIC
