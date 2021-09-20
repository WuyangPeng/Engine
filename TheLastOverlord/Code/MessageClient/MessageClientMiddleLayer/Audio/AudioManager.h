// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:29)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerDll.h"

#include "MessageClient/MessageClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/AudioManagerInterface.h" 

namespace MessageClientMiddleLayer
{
	class MESSAGE_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager : public Framework::AudioManagerInterface
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

#endif // MESSAGE_CLIENT_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
