// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/09 22:37)

#ifndef GAME_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
#define GAME_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h" 

namespace GameClientMiddleLayer
{
	class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntellegenceManager : public Framework::ArtificialIntellegenceInterface
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

#endif // GAME_CLIENT_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
