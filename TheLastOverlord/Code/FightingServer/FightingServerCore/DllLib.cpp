// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:37)

#include "FightingServerCoreExport.h"

#include "FightingServerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_FIGHTING_SERVER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_FIGHTING_SERVER_CORE_STATIC

	namespace FightingServerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_FIGHTING_SERVER_CORE_STATIC
