// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.1.0.1 (2020/04/06 14:18)

#include "Example/BookGameDesign/BookGeometry/BookGeometryExport.h"

#include "BookGeometryFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
 
#ifndef BUILDING_BOOK_GEOMETRY_STATIC

//DLL_MAIN_FUNCTION(BookGeometry);

#else  // !BUILDING_BOOK_GEOMETRY_STATIC 

CORE_TOOLS_MUTEX_INIT(BookGeometry);

#endif  // BUILDING_BOOK_GEOMETRY_STATIC
