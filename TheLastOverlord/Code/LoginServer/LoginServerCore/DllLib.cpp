// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:02)

#include "LoginServerCoreExport.h"

#include "LoginServerCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_LOGIN_SERVER_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_LOGIN_SERVER_CORE_STATIC

	namespace LoginServerCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_LOGIN_SERVER_CORE_STATIC
