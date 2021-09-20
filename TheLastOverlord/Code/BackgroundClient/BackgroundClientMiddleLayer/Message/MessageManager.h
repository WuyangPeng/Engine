// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 17:57)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H

#include "BackgroundClient/BackgroundClientMiddleLayer/BackgroundClientMiddleLayerDll.h"

#include "BackgroundClient/BackgroundClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/MessageManagerInterface.h" 

namespace BackgroundClientMiddleLayer
{
	class BACKGROUND_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE MessageManager : public Framework::MessageManagerInterface
	{
	public:
		using ClassType = MessageManager;
		using ParentType = Framework::MessageManagerInterface;
		
	public:
		explicit MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~MessageManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // BACKGROUND_CLIENT_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
