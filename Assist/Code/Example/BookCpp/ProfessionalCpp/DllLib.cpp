///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/23 16:05)

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
