///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/23 16:05)

#include "Example/BookCpp/ProfessionalCpp/ProfessionalCppExport.h"

#include "ProfessionalCpp.h"

#ifndef BUILDING_PROFESSIONAL_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_PROFESSIONAL_CPP_STATIC

namespace ProfessionalCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_PROFESSIONAL_CPP_STATIC
