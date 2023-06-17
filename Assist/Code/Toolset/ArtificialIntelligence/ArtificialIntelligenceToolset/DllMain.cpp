///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 19:36)

#include "Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset/ArtificialIntelligenceToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset/ArtificialIntelligenceToolsetFwd.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

DLL_MAIN_FUNCTION(ArtificialIntelligence);

#else  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

CORE_TOOLS_MUTEX_INIT(ArtificialIntelligence);

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC
