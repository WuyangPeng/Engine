///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:21)

#include "Example/BookOperatingSystem/TheDevelopersGuideToDebugging/TheDevelopersGuideToDebuggingExport.h"

#include "TheDevelopersGuideToDebuggingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_STATIC

DLL_MAIN_FUNCTION(TheDevelopersGuideToDebugging);

#else  // !BUILDING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_STATIC

CORE_TOOLS_MUTEX_INIT(TheDevelopersGuideToDebugging);

#endif  // BUILDING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_STATIC
