///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:21)

#include "Example/BookOperatingSystem/SafeCpp/SafeCppExport.h"

#include "SafeCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SAFE_CPP_STATIC

DLL_MAIN_FUNCTION(SafeCpp);

#else  // !BUILDING_SAFE_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(SafeCpp);

#endif  // BUILDING_SAFE_CPP_STATIC
