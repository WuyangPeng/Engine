// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:29)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerDll.h"

#include "MessageClient/MessageClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h" 

namespace MessageClientMiddleLayer
{
	class MESSAGE_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntellegenceManager : public Framework::ArtificialIntellegenceInterface
	{
	public:
		using ClassType = ArtificialIntellegenceManager;
		using ParentType = Framework::ArtificialIntellegenceInterface;
		
	public:
		explicit ArtificialIntellegenceManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ArtificialIntellegenceManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // MESSAGE_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
