///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 16:04)

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
