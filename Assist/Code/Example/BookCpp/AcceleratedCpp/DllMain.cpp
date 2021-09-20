///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/29 22:06)

#include "Example/BookCpp/AcceleratedCpp/AcceleratedCppExport.h"

#include "AcceleratedCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ACCELERATED_CPP_STATIC

DLL_MAIN_FUNCTION(AcceleratedCpp);

#else  // BUILDING_ACCELERATED_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(AcceleratedCpp);

#endif  // !BUILDING_ACCELERATED_CPP_STATIC
