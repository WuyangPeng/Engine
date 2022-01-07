///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/24 20:50)

#include "Toolset/Example/BookLinuxToolset/BookLinuxToolsetExport.h"

#include "BookLinuxToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_LINUX_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookLinuxToolset);

#else  // defined(BUILDING_BOOK_LINUX_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookLinuxToolset);

#endif  // !defined(BUILDING_BOOK_LINUX_TOOLSET_STATIC)