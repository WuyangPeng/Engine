///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 17:05)

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Imagics/ImagicsToolset/ImagicsToolsetFwd.h"

#ifndef BUILDING_IMAGICS_STATIC

DLL_MAIN_FUNCTION(Imagics);

#else  // !BUILDING_IMAGICS_STATIC

CORE_TOOLS_MUTEX_INIT(Imagics);

#endif  // !BUILDING_IMAGICS_STATIC