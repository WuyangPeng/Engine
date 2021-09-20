// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:12)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerDll.h"

#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/SystemManagerInterface.h" 

namespace BackgroundServerMiddleLayer
{
	class BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager : public Framework::SystemManagerInterface
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

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
