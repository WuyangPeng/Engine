///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/23 16:05)

#include "Example/BookCpp/HowNotToProgramInCpp/HowNotToProgramInCppExport.h"

#include "HowNotToProgramInCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

DLL_MAIN_FUNCTION(HowNotToProgramInCpp);

#else  // BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(HowNotToProgramInCpp);

#endif  // !BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC
