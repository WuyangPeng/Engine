// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 09:42)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
#define FIGHTING_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerDll.h"

#include "FightingServer/FightingServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h" 

namespace FightingServerMiddleLayer
{
	class FIGHTING_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntellegenceManager : public Framework::ArtificialIntellegenceInterface
	{
	public:
		using ClassType = ArtificialIntellegenceManager;
		using ParentType = Framework::ArtificialIntellegenceInterface;
		
	public:
		ArtificialIntellegenceManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ArtificialIntellegenceManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // FIGHTING_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
