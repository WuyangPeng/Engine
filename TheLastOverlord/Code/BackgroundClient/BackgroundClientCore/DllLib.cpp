// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 17:48)

#include "BackgroundClientCoreExport.h"

#include "BackgroundClientCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_BACKGROUND_CLIENT_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC

	namespace BackgroundClientCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC
