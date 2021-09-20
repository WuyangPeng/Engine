// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.3.0 (2020/03/24 21:33)

#include "Example/BookSoftwareDesign/BookMode/BookModeExport.h"

#include "BookModeFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_BOOK_MODE_STATIC

	DLL_MAIN_FUNCTION(BookMode);

#else // !BUILDING_BOOK_MODE_STATIC

	CORE_TOOLS_MUTEX_INIT(BookMode);

#endif // BUILDING_BOOK_MODE_STATIC
