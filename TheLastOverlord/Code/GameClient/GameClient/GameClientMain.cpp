/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:26)

#include "GameClient/GameClient/GameClientHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(GameClient,
                                       GameClientHelper,
                                       SYSTEM_TEXT("The Last Overlord GameClient"),
                                       SYSTEM_TEXT("DefaultEnvironment"),
                                       SYSTEM_TEXT(""),
                                       1024,
                                       768)
