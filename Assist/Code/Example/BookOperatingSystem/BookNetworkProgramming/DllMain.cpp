///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.6 (2021/07/10 13:13)

#include "Example/BookOperatingSystem/BookNetworkProgramming/BookNetworkProgrammingExport.h"

#include "BookNetworkProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC

DLL_MAIN_FUNCTION(BookNetworkProgramming);

#else  // !BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC

CORE_TOOLS_MUTEX_INIT(BookNetworkProgramming);

#endif  // BUILDING_BOOK_NETWORK_PROGRAMMING_STATIC
