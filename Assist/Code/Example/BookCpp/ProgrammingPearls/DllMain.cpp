///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/ProgrammingPearls/ProgrammingPearlsExport.h"

#include "ProgrammingPearlsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PROGRAMMING_PEARLS_STATIC

DLL_MAIN_FUNCTION(ProgrammingPearls);

#else  // BUILDING_PROGRAMMING_PEARLS_STATIC

CORE_TOOLS_MUTEX_INIT(ProgrammingPearls);

#endif  // !BUILDING_PROGRAMMING_PEARLS_STATIC
