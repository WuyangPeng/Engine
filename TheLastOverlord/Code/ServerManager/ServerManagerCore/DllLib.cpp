// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 16:39)

#include "ServerManagerCoreExport.h"

#include "ServerManagerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_SERVER_MANAGER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_SERVER_MANAGER_CORE_STATIC

	namespace ServerManagerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SERVER_MANAGER_CORE_STATIC
