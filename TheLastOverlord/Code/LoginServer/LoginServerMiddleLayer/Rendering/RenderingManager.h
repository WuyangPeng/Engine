// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 14:07)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
#define LOGIN_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerDll.h"

#include "LoginServer/LoginServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/RenderingManagerInterface.h" 

namespace LoginServerMiddleLayer
{
	class LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager : public Framework::RenderingManagerInterface
	{
	public:
		using ClassType = RenderingManager;
		using ParentType = Framework::RenderingManagerInterface;
		
	public:
		RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~RenderingManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // LOGIN_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
