///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/04/24 20:47)

#include "Example/BookOperatingSystem/BookOperatingSystem/BookOperatingSystemExport.h"

#include "BookOperatingSystemFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#if !defined(BUILDING_BOOK_OPERATING_SYSTEM_STATIC)

DLL_MAIN_FUNCTION(BookOperatingSystem);

#else  // defined(BUILDING_BOOK_OPERATING_SYSTEM_STATIC)

CORE_TOOLS_MUTEX_INIT(BookOperatingSystem);

#endif  // !defined(BUILDING_BOOK_OPERATING_SYSTEM_STATIC)