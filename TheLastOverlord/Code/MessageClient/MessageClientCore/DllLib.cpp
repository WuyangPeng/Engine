// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 16:28)

#include "MessageClientCoreExport.h"

#include "MessageClientCore.h"

#include "CoreTools/CoreToolsLib.h"
#include "Framework/FrameworkLib.h"

#ifndef BUILDING_MESSAGE_CLIENT_CORE_STATIC

	#include "DllLib.h"

#else // !BUILDING_MESSAGE_CLIENT_CORE_STATIC

	namespace MessageClientCore
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_MESSAGE_CLIENT_CORE_STATIC
