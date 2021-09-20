///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:29)

#include "Example/BookCpp/BeginningCpp17/BeginningCpp17Export.h"

#include "BeginningCpp17Fwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BEGINNING_CPP_17_STATIC

DLL_MAIN_FUNCTION(BeginningCpp17);

#else  // BUILDING_BEGINNING_CPP_17_STATIC

CORE_TOOLS_MUTEX_INIT(BeginningCpp17);

#endif  // !BUILDING_BEGINNING_CPP_17_STATIC
