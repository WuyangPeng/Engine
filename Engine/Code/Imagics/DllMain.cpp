///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/02 11:19)

#include "Imagics/ImagicsExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Imagics/ImagicsFwd.h"

#ifndef BUILDING_IMAGICS_STATIC

DLL_MAIN_FUNCTION(Imagics);

#else  // BUILDING_IMAGICS_STATIC

CORE_TOOLS_MUTEX_INIT(Imagics);

#endif  // !BUILDING_IMAGICS_STATIC