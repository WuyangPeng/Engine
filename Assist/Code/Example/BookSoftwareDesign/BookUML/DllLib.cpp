// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.1 (2020/04/05 17:50)

#include "Example/BookSoftwareDesign/BookUML/BookUMLExport.h"

#include "BookUML.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_BOOK_UML_STATIC

	#include "DllLib.h"

#else // !BUILDING_BOOK_UML_STATIC

	namespace BookUML
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_BOOK_UML_STATIC
	
