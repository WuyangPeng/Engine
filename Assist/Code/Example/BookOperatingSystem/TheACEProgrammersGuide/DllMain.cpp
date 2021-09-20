///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/06 21:46)

#include "Example/BookOperatingSystem/TheACEProgrammersGuide/TheACEProgrammersGuideExport.h"

#include "TheACEProgrammersGuideFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

DLL_MAIN_FUNCTION(TheACEProgrammersGuide);

#else  // !BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

CORE_TOOLS_MUTEX_INIT(TheACEProgrammersGuide);

#endif  // BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC
