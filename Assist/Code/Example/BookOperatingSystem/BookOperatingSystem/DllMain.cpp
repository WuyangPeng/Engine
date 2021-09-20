///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/04/24 20:47)

#include "Example/BookOperatingSystem/BookOperatingSystem/BookOperatingSystemExport.h"

#include "BookOperatingSystemFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_OPERATING_SYSTEM_STATIC)

DLL_MAIN_FUNCTION(BookOperatingSystem);

#else  // defined(BUILDING_BOOK_OPERATING_SYSTEM_STATIC)

CORE_TOOLS_MUTEX_INIT(BookOperatingSystem);

#endif  // !defined(BUILDING_BOOK_OPERATING_SYSTEM_STATIC)