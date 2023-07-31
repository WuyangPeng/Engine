///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:24)

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
