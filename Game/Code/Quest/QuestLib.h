///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:31)

#ifndef QUEST_LIB_H
#define QUEST_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_QUEST_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "QuestD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Quest.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_QUEST_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "QuestStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "QuestStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_QUEST_STATIC

#endif  // TCRE_USE_MSVC

#endif  // QUEST_LIB_H
