///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.6 (2021/07/10 13:13)

#include "Example/BookOperatingSystem/BookNetworkProgramming/BookNetworkProgrammingExport.h"

#include "BookNetworkProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(BookNetworkProgramming);

#else  // !BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(BookNetworkProgramming);

#endif  // BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC
