///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/02 10:27)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligence/ArtificialIntelligence.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

    #include "DllLib.h"

#else  // BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

namespace ArtificialIntelligence
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC