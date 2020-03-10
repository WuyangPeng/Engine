// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 14:51)

#ifndef SYSTEM_FILE_MANAGE_FILE_TIME_FLAGS_H
#define SYSTEM_FILE_MANAGE_FILE_TIME_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
	enum class ComparesFileTimeReturn 
	{	
		Earlier = -1,
		Equal = 0,                
		Later = 1,
	};		
}

#endif // SYSTEM_FILE_MANAGE_FILE_TIME_FLAGS_H
