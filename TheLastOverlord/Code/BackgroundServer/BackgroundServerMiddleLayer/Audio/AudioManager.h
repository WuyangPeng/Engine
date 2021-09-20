// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:09)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerDll.h"

#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/AudioManagerInterface.h" 

namespace BackgroundServerMiddleLayer
{
	class BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager : public Framework::AudioManagerInterface
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

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
