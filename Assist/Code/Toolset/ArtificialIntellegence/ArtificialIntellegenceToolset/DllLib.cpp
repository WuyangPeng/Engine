///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 15:36)

#include "Toolset/ArtificialIntellegence/ArtificialIntellegenceToolset/ArtificialIntellegenceToolsetExport.h"

#include "Toolset/ArtificialIntellegence/ArtificialIntellegenceToolset/ArtificialIntellegenceToolset.h"

#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

    #include "DllLib.h"

#else  // BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

namespace ArtificialIntellegenceToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC
