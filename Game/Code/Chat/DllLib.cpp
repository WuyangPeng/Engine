// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������Ϸ�汾��0.0.0.1 (2019/10/06 20:18)

#include "Chat/ChatExport.h"

#include "Chat/Chat.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_CHAT_STATIC

	#include "DllLib.h"

#else // !BUILDING_CHAT_STATIC

	namespace Chat
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_CHAT_STATIC
	
