///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/04 23:11)

#include "Toolset/Example/BookPrimaryToolset/BookPrimaryToolsetExport.h"

#include "BookPrimaryToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_PRIMARY_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookPrimaryToolset);

#else  // defined(BUILDING_BOOK_PRIMARY_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookPrimaryToolset);

#endif  // !defined(BUILDING_BOOK_PRIMARY_TOOLSET_STATIC)