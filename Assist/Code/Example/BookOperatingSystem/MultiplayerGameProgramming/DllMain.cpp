///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.0 (2021/07/18 18:41)

#include "Example/BookOperatingSystem/MultiplayerGameProgramming/MultiplayerGameProgrammingExport.h"

#include "MultiplayerGameProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(MultiplayerGameProgramming);

#else  // !BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(MultiplayerGameProgramming);

#endif  // BUILDING_MULTIPLAYER_GAME_PROGRAMMING_STATIC
