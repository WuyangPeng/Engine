/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/16 20:45)

#include "AssistHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_USE_PARAMETER(ThreadingCoreRenderEngineAssist,
                                    AssistHelper,
                                    SYSTEM_TEXT("DefaultEnvironment"),
                                    SYSTEM_TEXT("EngineDirectory"),
                                    SYSTEM_TEXT("ThreadingCoreRenderEngineAssist.json"))