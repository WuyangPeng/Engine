///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/05 1:03)

#include "Example/BookOperatingSystem/BookACE/BookACEExport.h"

#include "BookACEFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOK_ACE_STATIC

DLL_MAIN_FUNCTION(BookACE);

#else  // !BUILDING_BOOK_ACE_STATIC

CORE_TOOLS_MUTEX_INIT(BookACE);

#endif  // BUILDING_BOOK_ACE_STATIC
