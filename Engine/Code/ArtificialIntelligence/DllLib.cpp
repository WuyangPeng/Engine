///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 19:28)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligence/ArtificialIntelligence.h"

#include "CoreTools/CoreToolsLib.h"
#include "Mathematics/MathematicsLib.h"
#include "Physics/PhysicsLib.h"
#include "Imagics/ImagicsLib.h"

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