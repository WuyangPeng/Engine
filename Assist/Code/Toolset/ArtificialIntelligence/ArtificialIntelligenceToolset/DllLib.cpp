///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:40)

#include "Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset/ArtificialIntelligenceToolsetExport.h"

#include "Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset/ArtificialIntelligenceToolset.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

    #include "DllLib.h"

#else  // BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

namespace ArtificialIntelligenceToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC
