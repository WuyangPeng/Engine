///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 19:38)

#include "Example/ArtificialIntelligence/ArtificialIntelligenceExample/ArtificialIntelligenceExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/ArtificialIntelligence/ArtificialIntelligenceExample/ArtificialIntelligenceExampleFwd.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ArtificialIntelligenceExample);

#else  // !BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ArtificialIntelligenceExample);

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_EXAMPLE_STATIC
