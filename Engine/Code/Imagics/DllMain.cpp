// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/30 11:17)

#include "Imagics/ImagicsExport.h"

#include "Imagics/ImagicsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_IMAGICS_STATIC

	DLL_MAIN_FUNCTION(Imagics);

#else // !BUILDING_IMAGICS_STATIC

	CORE_TOOLS_MUTEX_INIT(Imagics);

#endif // !BUILDING_IMAGICS_STATIC