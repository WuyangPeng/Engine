// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.3.0.1 (2020/05/20 21:08)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "Toolset/Framework/FrameworkToolset/FrameworkToolset.h"

#ifndef BUILDING_FRAMEWORK_STATIC

	#include "DllLib.h"

#else // BUILDING_FRAMEWORK_STATIC

	namespace FrameworkToolset
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_FRAMEWORK_STATIC
