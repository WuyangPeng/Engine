// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/03 21:50)

#include "UserInfo/UserInfoExport.h"

#include "UserInfo/UserInfo.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_USER_INFO_STATIC

	#include "DllLib.h"

#else // !BUILDING_USER_INFO_STATIC

	namespace UserInfo
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_USER_INFO_STATIC
	
