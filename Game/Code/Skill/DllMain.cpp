// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:38)

#include "Skill/SkillExport.h"

#include "SkillFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_SKILL_STATIC

	DLL_MAIN_FUNCTION(Skill);

#else // !BUILDING_SKILL_STATIC

	CORE_TOOLS_MUTEX_INIT(Skill);

#endif // BUILDING_SKILL_STATIC
