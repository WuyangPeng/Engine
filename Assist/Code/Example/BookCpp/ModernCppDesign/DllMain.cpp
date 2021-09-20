///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/ModernCppDesign/ModernCppDesignExport.h"

#include "ModernCppDesignFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MODERN_CPP_DESIGN_STATIC

DLL_MAIN_FUNCTION(ModernCppDesign);

#else  // BUILDING_MODERN_CPP_DESIGN_STATIC

CORE_TOOLS_MUTEX_INIT(ModernCppDesign);

#endif  // !BUILDING_MODERN_CPP_DESIGN_STATIC
