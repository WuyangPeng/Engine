///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:08)

#ifndef SKILL_LIB_H
#define SKILL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SKILL_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SkillD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Skill.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SKILL_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SkillStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SkillStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SKILL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SKILL_LIB_H
