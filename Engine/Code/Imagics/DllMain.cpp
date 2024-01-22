/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:34)

#include "Imagics/ImagicsExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Imagics/ImagicsFwd.h"

#ifndef BUILDING_IMAGICS_STATIC

DLL_MAIN_FUNCTION(Imagics);

#else  // BUILDING_IMAGICS_STATIC

CORE_TOOLS_MUTEX_INIT(Imagics);

#endif  // !BUILDING_IMAGICS_STATIC