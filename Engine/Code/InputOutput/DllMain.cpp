// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/16 14:38)

#include "InputOutput/InputOutputExport.h"

#include "InputOutput/InputOutputFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

	DLL_MAIN_FUNCTION(InputOutput);

#else // !BUILDING_INPUT_OUTPUT_STATIC

	CORE_TOOLS_MUTEX_INIT(InputOutput);

#endif // !BUILDING_INPUT_OUTPUT_STATIC