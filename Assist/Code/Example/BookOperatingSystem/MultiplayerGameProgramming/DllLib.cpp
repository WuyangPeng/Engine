///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/18 18:43)

#include "Example/BookOperatingSystem/MultiplayerGameProgramming/MultiplayerGameProgrammingExport.h"

#include "MultiplayerGameProgramming.h"

#ifndef BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

    #include "DllLib.h"

#else  // !BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

namespace MultiplayerGameProgramming
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC
