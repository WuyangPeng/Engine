// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.0 (2020/04/04 15:32)

#include "Example/BookOtherLanguages/BookDatabase/BookDatabaseExport.h"

#include "BookDatabaseFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_BOOK_DATABASE_STATIC

	DLL_MAIN_FUNCTION(BookDatabase);

#else // !BUILDING_BOOK_DATABASE_STATIC

	CORE_TOOLS_MUTEX_INIT(BookDatabase);

#endif // BUILDING_BOOK_DATABASE_STATIC
