/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:38)

#include "InputOutput/InputOutputExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "InputOutput/InputOutputFwd.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

DLL_MAIN_FUNCTION(InputOutput);

#else  // !BUILDING_INPUT_OUTPUT_STATIC

CORE_TOOLS_MUTEX_INIT(InputOutput);

#endif  // !BUILDING_INPUT_OUTPUT_STATIC