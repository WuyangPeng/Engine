///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 19:50)

#include "InputOutput/InputOutputExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "InputOutput/InputOutputFwd.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

DLL_MAIN_FUNCTION(InputOutput);

#else  // !BUILDING_INPUT_OUTPUT_STATIC

CORE_TOOLS_MUTEX_INIT(InputOutput);

#endif  // !BUILDING_INPUT_OUTPUT_STATIC