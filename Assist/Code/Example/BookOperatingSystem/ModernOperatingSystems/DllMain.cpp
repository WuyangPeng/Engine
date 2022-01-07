///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:21)

#include "Example/BookOperatingSystem/ModernOperatingSystems/ModernOperatingSystemsExport.h"

#include "ModernOperatingSystemsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

DLL_MAIN_FUNCTION(ModernOperatingSystems);

#else  // !BUILDING_MODERN_OPERATING_SYSTEMS_STATIC

CORE_TOOLS_MUTEX_INIT(ModernOperatingSystems);

#endif  // BUILDING_MODERN_OPERATING_SYSTEMS_STATIC
