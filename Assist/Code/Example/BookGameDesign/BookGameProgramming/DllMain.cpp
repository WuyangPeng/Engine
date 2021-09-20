// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/06 09:43)

#include "Example/BookGameDesign/BookGameProgramming/BookGameProgrammingExport.h"

#include "BookGameProgrammingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_BOOK_GAME_PROGRAMMING_STATIC

	DLL_MAIN_FUNCTION(BookGameProgramming);

#else // !BUILDING_BOOK_GAME_PROGRAMMING_STATIC

	CORE_TOOLS_MUTEX_INIT(BookGameProgramming);

#endif // BUILDING_BOOK_GAME_PROGRAMMING_STATIC
