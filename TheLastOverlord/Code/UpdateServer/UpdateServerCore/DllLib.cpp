// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:56)

#include "UpdateServerCoreExport.h"

#include "UpdateServerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_UPDATE_SERVER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_UPDATE_SERVER_CORE_STATIC

	namespace UpdateServerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_UPDATE_SERVER_CORE_STATIC
