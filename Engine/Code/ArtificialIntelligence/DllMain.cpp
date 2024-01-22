/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 19:49)

#include "ArtificialIntelligence/ArtificialIntelligenceExport.h"

#include "ArtificialIntelligence/ArtificialIntelligenceFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

DLL_MAIN_FUNCTION(ArtificialIntelligence);

#else  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

CORE_TOOLS_MUTEX_INIT(ArtificialIntelligence);

#endif  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC