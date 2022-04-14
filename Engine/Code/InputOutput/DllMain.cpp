///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/25 16:37)

#include "InputOutput/InputOutputExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "InputOutput/InputOutputFwd.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

DLL_MAIN_FUNCTION(InputOutput);

#else  // !BUILDING_INPUT_OUTPUT_STATIC

CORE_TOOLS_MUTEX_INIT(InputOutput);

#endif  // !BUILDING_INPUT_OUTPUT_STATIC