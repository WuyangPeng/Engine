///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2020/12/31 23:05)

#include "Example/BookCpp/CppDistilled/CppDistilledExport.h"

#include "CppDistilledFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_DISTILLED_STATIC

DLL_MAIN_FUNCTION(CppDistilled);

#else  // BUILDING_CPP_DISTILLED_STATIC

CORE_TOOLS_MUTEX_INIT(CppDistilled);

#endif  // !BUILDING_CPP_DISTILLED_STATIC
