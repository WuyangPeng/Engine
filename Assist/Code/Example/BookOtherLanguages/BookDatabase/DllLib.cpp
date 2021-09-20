// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.1.0.0 (2020/04/04 15:33)

#include "Example/BookOtherLanguages/BookDatabase/BookDatabaseExport.h"

#include "BookDatabase.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_BOOK_DATABASE_STATIC

	#include "DllLib.h"

#else // !BUILDING_BOOK_DATABASE_STATIC

	namespace BookDatabase
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_BOOK_DATABASE_STATIC
	
