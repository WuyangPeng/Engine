///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/18 18:41)

#include "Example/BookOperatingSystem/MultiplayerGameProgramming/MultiplayerGameProgrammingExport.h"

#include "MultiplayerGameProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(MultiplayerGameProgramming);

#else  // !BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(MultiplayerGameProgramming);

#endif  // BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC
