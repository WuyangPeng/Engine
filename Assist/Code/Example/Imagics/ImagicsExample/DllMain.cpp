///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 13:41)

#include "Example/Imagics/ImagicsExample/ImagicsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Imagics/ImagicsExample/ImagicsExampleFwd.h"

#ifndef BUILDING_IMAGICS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(ImagicsExample);

#else  // !BUILDING_IMAGICS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(ImagicsExample);

#endif  // !BUILDING_IMAGICS_EXAMPLE_STATIC
