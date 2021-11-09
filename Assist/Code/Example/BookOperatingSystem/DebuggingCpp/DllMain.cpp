///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:21)

#include "Example/BookOperatingSystem/DebuggingCpp/DebuggingCppExport.h"

#include "DebuggingCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DEBUGGING_CPP_STATIC

DLL_MAIN_FUNCTION(DebuggingCpp);

#else  // !BUILDING_DEBUGGING_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(DebuggingCpp);

#endif  // BUILDING_DEBUGGING_CPP_STATIC
