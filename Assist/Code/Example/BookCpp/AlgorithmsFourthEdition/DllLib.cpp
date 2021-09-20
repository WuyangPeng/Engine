///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/07 0:26)

#include "Example/BookCpp/AlgorithmsFourthEdition/AlgorithmsFourthEditionExport.h"

#include "AlgorithmsFourthEdition.h"

#ifndef BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

    #include "DllLib.h"

#else  // BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

namespace AlgorithmsFourthEdition
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC
