///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/06 20:45)

#include "Toolset/Example/BookStandardLibraryToolset/BookStandardLibraryToolsetExport.h"

#include "BookStandardLibraryToolsetFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_STANDARD_LIBRARY_TOOLSET_STATIC)

DLL_MAIN_FUNCTION(BookStandardLibraryToolset);

#else  // defined(BUILDING_BOOK_STANDARD_LIBRARY_TOOLSET_STATIC)

CORE_TOOLS_MUTEX_INIT(BookStandardLibraryToolset);

#endif  // !defined(BUILDING_BOOK_STANDARD_LIBRARY_TOOLSET_STATIC)