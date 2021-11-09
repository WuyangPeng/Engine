///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 8:44)

#include "Example/BookOperatingSystem/DesignImplementationAndInternals/DesignImplementationAndInternalsExport.h"

#include "DesignImplementationAndInternalsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DESIGN_IMPLEMENTATION_AND_INTERNALS_STATIC

DLL_MAIN_FUNCTION(DesignImplementationAndInternals);

#else  // !BUILDING_DESIGN_IMPLEMENTATION_AND_INTERNALS_STATIC

CORE_TOOLS_MUTEX_INIT(DesignImplementationAndInternals);

#endif  // BUILDING_DESIGN_IMPLEMENTATION_AND_INTERNALS_STATIC
