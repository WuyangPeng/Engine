// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.0 (2020/01/07 22:44)

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolsetExport.h"

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_IMAGICS_STATIC

	DLL_MAIN_FUNCTION(Imagics);

#else // !BUILDING_IMAGICS_STATIC

	CORE_TOOLS_MUTEX_INIT(Imagics);

#endif // !BUILDING_IMAGICS_STATIC