///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/06 21:46)

#include "Example/BookOperatingSystem/TheACEProgrammersGuide/TheACEProgrammersGuideExport.h"

#include "TheACEProgrammersGuideFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

DLL_MAIN_FUNCTION(TheACEProgrammersGuide);

#else  // !BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

CORE_TOOLS_MUTEX_INIT(TheACEProgrammersGuide);

#endif  // BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC
