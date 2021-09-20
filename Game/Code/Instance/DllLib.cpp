// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/06 21:12)

#include "Instance/InstanceExport.h"

#include "Instance/Instance.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_INSTANCE_STATIC

	#include "DllLib.h"

#else // !BUILDING_INSTANCE_STATIC

	namespace Instance
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_INSTANCE_STATIC
	
