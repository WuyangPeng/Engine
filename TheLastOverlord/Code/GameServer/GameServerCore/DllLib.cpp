// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 16:59)

#include "GameServerCoreExport.h"

#include "GameServerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_GAME_SERVER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_GAME_SERVER_CORE_STATIC

	namespace GameServerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_GAME_SERVER_CORE_STATIC
