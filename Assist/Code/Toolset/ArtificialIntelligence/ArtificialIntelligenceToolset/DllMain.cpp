///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 19:36)

#include "Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset/ArtificialIntelligenceToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/ArtificialIntelligence/ArtificialIntelligenceToolset/ArtificialIntelligenceToolsetFwd.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

DLL_MAIN_FUNCTION(ArtificialIntelligence);

#else  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

CORE_TOOLS_MUTEX_INIT(ArtificialIntelligence);

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC
