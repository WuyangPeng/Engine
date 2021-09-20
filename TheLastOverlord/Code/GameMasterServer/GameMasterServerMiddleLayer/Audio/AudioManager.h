// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:47)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerDll.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/AudioManagerInterface.h" 

namespace GameMasterServerMiddleLayer
{
	class GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager : public Framework::AudioManagerInterface
	{
	public:
		using ClassType = AudioManager;
		using ParentType = Framework::AudioManagerInterface;
		
	public:
		explicit AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~AudioManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GAME_MASTER_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
