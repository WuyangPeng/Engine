///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:24)

#include "Skill/SkillExport.h"

#include "SkillFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SKILL_STATIC

DLL_MAIN_FUNCTION(Skill);

#else  // !BUILDING_SKILL_STATIC

CORE_TOOLS_MUTEX_INIT(Skill);

#endif  // BUILDING_SKILL_STATIC
