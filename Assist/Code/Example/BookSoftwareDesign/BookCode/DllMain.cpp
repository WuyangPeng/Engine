// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.3 (2020/04/27 23:57)

#include "Example/BookSoftwareDesign/BookCode/BookCodeExport.h"

#include "BookCodeFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_BOOK_CODE_STATIC

	DLL_MAIN_FUNCTION(BookCode);

#else // !BUILDING_BOOK_CODE_STATIC

	CORE_TOOLS_MUTEX_INIT(BookCode);

#endif // BUILDING_BOOK_CODE_STATIC
