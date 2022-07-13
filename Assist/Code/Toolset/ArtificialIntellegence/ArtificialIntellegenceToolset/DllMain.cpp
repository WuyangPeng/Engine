///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 15:36)

#include "Toolset/ArtificialIntellegence/ArtificialIntellegenceToolset/ArtificialIntellegenceToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/ArtificialIntellegence/ArtificialIntellegenceToolset/ArtificialIntellegenceToolsetFwd.h"

#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

DLL_MAIN_FUNCTION(ArtificialIntellegence);

#else  // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

CORE_TOOLS_MUTEX_INIT(ArtificialIntellegence);

#endif  // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC
