///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/HackersDelight/HackersDelightExport.h"

#include "HackersDelightFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_HACKERS_DELIGHT_STATIC

DLL_MAIN_FUNCTION(HackersDelight);

#else  // BUILDING_HACKERS_DELIGHT_STATIC

CORE_TOOLS_MUTEX_INIT(HackersDelight);

#endif  // !BUILDING_HACKERS_DELIGHT_STATIC
