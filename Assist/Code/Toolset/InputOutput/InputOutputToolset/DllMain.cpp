///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:44)

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetFwd.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

DLL_MAIN_FUNCTION(InputOutput);

#else  // !BUILDING_INPUT_OUTPUT_STATIC

CORE_TOOLS_MUTEX_INIT(InputOutput);

#endif  // !BUILDING_INPUT_OUTPUT_STATIC
