/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#include "GameServer/GameServer/GameServerHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(GameServer,
                                       GameServerHelper,
                                       SYSTEM_TEXT("Millennium History GameServer"),
                                       SYSTEM_TEXT("DefaultEnvironment"),
                                       SYSTEM_TEXT(""),
                                       1024,
                                       768)
