// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.3.0 (2020/03/24 21:33)

#include "Example/BookSoftwareDesign/BookMode/BookModeExport.h"

#include "BookMode.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_BOOK_MODE_STATIC

	#include "DllLib.h"

#else // !BUILDING_BOOK_MODE_STATIC

	namespace BookMode
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_BOOK_MODE_STATIC
	
