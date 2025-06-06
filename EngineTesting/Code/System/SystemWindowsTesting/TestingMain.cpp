/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 16:37)

#include "System/SystemWindowsTesting/TestingHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include "System/Helper/PragmaWarning/Vld.h"

WINDOWS_MAIN_FUNCTION_WITH_INFORMATION(System,
                                       TestingHelper,
                                       SYSTEM_TEXT("SystemWindowsTesting"),
                                       SYSTEM_TEXT("DefaultEnvironment"),
                                       SYSTEM_TEXT(""),
                                       1024,
                                       768)
