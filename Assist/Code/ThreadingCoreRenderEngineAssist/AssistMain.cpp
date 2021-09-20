///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/10 20:27)

#include "AssistHelper.h"
#include "Framework/Helper/MainFunctionMacro.h"

#include <vld.h>

WINDOWS_MAIN_FUNCTION_USE_PARAMETER(ThreadingCoreRenderEngineAssist,
                                    AssistHelper,
                                    SYSTEM_TEXT("DefaultEnvironment"),
                                    SYSTEM_TEXT("EngineDirectory"),
                                    SYSTEM_TEXT("ThreadingCoreRenderEngineAssist.json"))