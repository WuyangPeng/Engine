///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:01)

#include "Example/ArtificialIntelligence/ArtificialIntelligenceExample/ArtificialIntelligenceExampleExport.h"

#include "Example/ArtificialIntelligence/ArtificialIntelligenceExample/ArtificialIntelligenceExample.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC

namespace ArtificialIntelligenceExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC
