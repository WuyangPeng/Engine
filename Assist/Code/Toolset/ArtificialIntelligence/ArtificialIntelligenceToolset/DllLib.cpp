///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 10:40)

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
