///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#include "Example/BookOperatingSystem/CppConcurrencyInAction/CppConcurrencyInActionExport.h"

#include "CppConcurrencyInActionFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_CONCURRENCY_IN_ACTION_STATIC

DLL_MAIN_FUNCTION(CppConcurrencyInAction);

#else  // !BUILDING_CPP_CONCURRENCY_IN_ACTION_STATIC

CORE_TOOLS_MUTEX_INIT(CppConcurrencyInAction);

#endif  // BUILDING_CPP_CONCURRENCY_IN_ACTION_STATIC
