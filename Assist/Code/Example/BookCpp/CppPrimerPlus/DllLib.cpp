///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/28 20:44)

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
