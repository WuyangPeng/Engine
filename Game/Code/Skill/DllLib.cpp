///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:24)

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
