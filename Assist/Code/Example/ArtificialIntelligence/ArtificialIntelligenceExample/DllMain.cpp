///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:01)

#include "Example/ArtificialIntelligence/ArtificialIntelligenceExample/ArtificialIntelligenceExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/ArtificialIntelligence/ArtificialIntelligenceExample/ArtificialIntelligenceExampleFwd.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ArtificialIntelligenceExample);

#else  // !BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ArtificialIntelligenceExample);

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC
