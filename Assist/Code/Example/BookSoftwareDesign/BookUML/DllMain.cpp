// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.1.0.1 (2020/04/05 17:50)

#include "Example/BookSoftwareDesign/BookUML/BookUMLExport.h"

#include "BookUMLFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_BOOK_UML_STATIC

	DLL_MAIN_FUNCTION(BookUML);

#else // !BUILDING_BOOK_UML_STATIC

	CORE_TOOLS_MUTEX_INIT(BookUML);

#endif // BUILDING_BOOK_UML_STATIC
