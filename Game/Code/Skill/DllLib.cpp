///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 11:39)

#include "Skill/SkillExport.h"

#include "Skill/Skill.h"

#ifndef BUILDING_SKILL_STATIC

    #include "DllLib.h"

#else  // !BUILDING_SKILL_STATIC

namespace Skill
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SKILL_STATIC
