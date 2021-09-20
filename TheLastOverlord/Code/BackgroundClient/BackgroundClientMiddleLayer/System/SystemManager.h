// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 18:01)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H

#include "BackgroundClient/BackgroundClientMiddleLayer/BackgroundClientMiddleLayerDll.h"

#include "BackgroundClient/BackgroundClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/SystemManagerInterface.h" 

namespace BackgroundClientMiddleLayer
{
	class BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager : public Framework::SystemManagerInterface
	{
	public:
		using ClassType = SystemManager;
		using ParentType = Framework::SystemManagerInterface;
		
	public:
		SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~SystemManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // BACKGROUND_CLIENT_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
