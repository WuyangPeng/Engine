// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:37)

#ifndef FRAMEWORK_CAMERA_SYSTEMS_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_CAMERA_SYSTEMS_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class  CameraSystemsMiddleLayer  : uint32_t 
	{ 
		System,
		Rendering,
		GUI,

		Count,
	};
	
} 	

#endif // FRAMEWORK_CAMERA_SYSTEMS_MANAGER_INTERFACE_FLAGS_H