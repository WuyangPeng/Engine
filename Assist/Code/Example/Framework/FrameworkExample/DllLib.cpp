// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.3 (2020/05/01 14:08)

#include "Example/Framework/FrameworkExample/FrameworkExampleExport.h"

#include "Example/Framework/FrameworkExample/FrameworkExample.h"

#ifndef BUILDING_FRAMEWORK_EXAMPLE_STATIC

	#include "DllLib.h"

#else // BUILDING_FRAMEWORK_EXAMPLE_STATIC

	namespace FrameworkExample
	{
		void StaticDllLib() noexcept
		{

		}
	}

#endif // !BUILDING_FRAMEWORK_EXAMPLE_STATIC
