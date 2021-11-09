///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/23 9:10)

#include "Toolset/Example/BookNetworkProgrammingToolset/BookNetworkProgrammingToolsetExport.h"

#include "BookNetworkProgrammingToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookNetworkProgrammingToolset);

#else  // defined(BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookNetworkProgrammingToolset);

#endif  // !defined(BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC)