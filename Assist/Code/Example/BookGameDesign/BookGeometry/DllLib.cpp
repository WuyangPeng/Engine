// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.1 (2020/04/06 14:18)

#include "Example/BookGameDesign/BookGeometry/BookGeometryExport.h"

#include "BookGeometry.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_BOOK_GEOMETRY_STATIC

	#include "DllLib.h"

#else // !BUILDING_BOOK_GEOMETRY_STATIC

	namespace BookGeometry
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_BOOK_GEOMETRY_STATIC
	
