///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/02/28 19:36)

#include "Example/BookCpp/ExtendedSTL/ExtendedSTLExport.h"

#include "ExtendedSTLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_EXTENDED_STL_STATIC

DLL_MAIN_FUNCTION(ExtendedSTL);

#else  // BUILDING_EXTENDED_STL_STATIC

CORE_TOOLS_MUTEX_INIT(ExtendedSTL);

#endif  // !BUILDING_EXTENDED_STL_STATIC
