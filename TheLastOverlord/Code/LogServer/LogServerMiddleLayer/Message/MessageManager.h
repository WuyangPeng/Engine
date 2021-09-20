// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/12 23:00)

#ifndef LOG_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
#define LOG_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerDll.h"

#include "LogServer/LogServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/MessageManagerInterface.h" 

namespace LogServerMiddleLayer
{
	class LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE MessageManager : public Framework::MessageManagerInterface
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

#endif // LOG_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
