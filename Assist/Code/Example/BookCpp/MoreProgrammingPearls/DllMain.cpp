///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/MoreProgrammingPearls/MoreProgrammingPearlsExport.h"

#include "MoreProgrammingPearlsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MORE_PROGRAMMING_PEARLS_STATIC

DLL_MAIN_FUNCTION(MoreProgrammingPearls);

#else  // BUILDING_MORE_PROGRAMMING_PEARLS_STATIC

CORE_TOOLS_MUTEX_INIT(MoreProgrammingPearls);

#endif  // !BUILDING_MORE_PROGRAMMING_PEARLS_STATIC