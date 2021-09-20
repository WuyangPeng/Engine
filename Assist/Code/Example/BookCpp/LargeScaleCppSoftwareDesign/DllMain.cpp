///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/LargeScaleCppSoftwareDesign/LargeScaleCppSoftwareDesignExport.h"

#include "LargeScaleCppSoftwareDesignFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LARGE_SCALE_CPP_SOFTWARE_DESIGN_STATIC

DLL_MAIN_FUNCTION(LargeScaleCppSoftwareDesign);

#else  // BUILDING_LARGE_SCALE_CPP_SOFTWARE_DESIGN_STATIC

CORE_TOOLS_MUTEX_INIT(LargeScaleCppSoftwareDesign);

#endif  // !BUILDING_LARGE_SCALE_CPP_SOFTWARE_DESIGN_STATIC
