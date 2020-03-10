// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:37)

#ifndef FRAMEWORK_AUDIO_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_AUDIO_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class AudioMiddleLayer : uint32_t 
	{ 
		System,
		Resource,

		Count,
	};
	
} 	

#endif // FRAMEWORK_AUDIO_MANAGER_INTERFACE_FLAGS_H