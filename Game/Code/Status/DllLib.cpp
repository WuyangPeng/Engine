// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/05 21:45)

#include "Status/StatusExport.h"

#include "Status/Status.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_STATUSSTATIC

	#include "DllLib.h"

#else // !BUILDING_STATUSSTATIC

	namespace Status
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_STATUSSTATIC
	
