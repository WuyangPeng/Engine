/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/20 15:09)

#include "ServerManager/ServerManager/ServerManagerHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(ServerManager,
                                       ServerManagerHelper,
                                       SYSTEM_TEXT("Rise Of History ServerManager"),
                                       SYSTEM_TEXT("DefaultEnvironment"),
                                       SYSTEM_TEXT(""),
                                       1024,
                                       768)
