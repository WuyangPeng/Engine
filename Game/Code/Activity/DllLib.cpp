// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/06 21:38)

#include "Activity/ActivityExport.h"

#include "Activity/Activity.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_ACTIVITY_STATIC

	#include "DllLib.h"

#else // !BUILDING_ACTIVITY_STATIC

	namespace Activity
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_ACTIVITY_STATIC
	
