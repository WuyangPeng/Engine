// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/03 21:50)

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
	
