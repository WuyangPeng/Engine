// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:05)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define OFFLINE_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "OfflineServer/OfflineServerMiddleLayer/OfflineServerMiddleLayerDll.h"

#include "OfflineServer/OfflineServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/EventManagerInterface.h" 

namespace OfflineServerMiddleLayer
{
	class OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager : public Framework::EventManagerInterface
	{
	public:
		using ClassType = EventManager;
		using ParentType = Framework::EventManagerInterface;
		
	public:
		EventManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~EventManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // OFFLINE_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
