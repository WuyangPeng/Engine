// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎游戏版本：0.0.0.1 (2019/10/05 23:02)

#include "Mail/MailExport.h"

#include "Mail/Mail.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_MAIL_STATIC

	#include "DllLib.h"

#else // !BUILDING_MAIL_STATIC

	namespace Mail
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_MAIL_STATIC
	
