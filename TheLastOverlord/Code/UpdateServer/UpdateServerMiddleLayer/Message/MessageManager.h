// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 19:00)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
#define UPDATE_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerDll.h"

#include "UpdateServer/UpdateServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/MessageManagerInterface.h" 

namespace UpdateServerMiddleLayer
{
	class UPDATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE MessageManager : public Framework::MessageManagerInterface
	{
	public:
		using ClassType = MessageManager;
		using ParentType = Framework::MessageManagerInterface;
		
	public:
		MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~MessageManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // UPDATE_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
