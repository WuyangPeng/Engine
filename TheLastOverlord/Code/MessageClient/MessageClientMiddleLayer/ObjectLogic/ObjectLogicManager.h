// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:53)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerDll.h"

#include "MessageClient/MessageClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ObjectLogicInterface.h" 

namespace MessageClientMiddleLayer
{
	class MESSAGE_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE ObjectLogicManager : public Framework::ObjectLogicInterface
	{
	public:
		using ClassType = ObjectLogicManager;
		using ParentType = Framework::ObjectLogicInterface;
		
	public:
		explicit ObjectLogicManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ObjectLogicManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // MESSAGE_CLIENT_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
