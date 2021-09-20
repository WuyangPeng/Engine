///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.1.0 (2021/01/21 23:03)

#include "Example/BookCpp/AdvancedCpp/AdvancedCppExport.h"

#include "AdvancedCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ADVANCED_CPP_STATIC

DLL_MAIN_FUNCTION(AdvancedCpp);

#else  // BUILDING_ADVANCED_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(AdvancedCpp);

#endif  // !BUILDING_ADVANCED_CPP_STATIC
