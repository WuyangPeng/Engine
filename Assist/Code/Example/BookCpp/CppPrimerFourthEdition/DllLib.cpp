///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/24 21:59)

#include "Example/BookCpp/CppPrimerFourthEdition/CppPrimerFourthEditionExport.h"

#include "CppPrimerFourthEdition.h"

#ifndef BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC

    #include "DllLib.h"

#else  // BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC

namespace CppPrimerFourthEdition
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC
