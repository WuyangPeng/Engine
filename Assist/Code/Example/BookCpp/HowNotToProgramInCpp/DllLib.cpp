///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/23 16:05)

#include "Example/BookCpp/HowNotToProgramInCpp/HowNotToProgramInCppExport.h"

#include "HowNotToProgramInCpp.h"

#ifndef BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

namespace HowNotToProgramInCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC
