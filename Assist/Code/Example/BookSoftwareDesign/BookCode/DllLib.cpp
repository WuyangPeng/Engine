// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.3 (2020/04/27 23:58)

#include "Example/BookSoftwareDesign/BookCode/BookCodeExport.h"

#include "BookCode.h"

#ifndef BUILDING_BOOK_CODE_STATIC

	#include "DllLib.h"

#else // !BUILDING_BOOK_CODE_STATIC

	namespace BookCode
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_BOOK_CODE_STATIC
	
