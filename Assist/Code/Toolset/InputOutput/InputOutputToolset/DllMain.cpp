///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:43)

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetFwd.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

DLL_MAIN_FUNCTION(InputOutput);

#else  // !BUILDING_INPUT_OUTPUT_STATIC

CORE_TOOLS_MUTEX_INIT(InputOutput);

#endif  // !BUILDING_INPUT_OUTPUT_STATIC
