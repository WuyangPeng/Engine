// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:05)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
#define OFFLINE_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H

#include "OfflineServer/OfflineServerMiddleLayer/OfflineServerMiddleLayerDll.h"

#include "OfflineServer/OfflineServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/AudioManagerInterface.h" 

namespace OfflineServerMiddleLayer
{
	class OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE AudioManager : public Framework::AudioManagerInterface
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

#endif // OFFLINE_SERVER_MIDDLE_LAYER_AUDIO_MIDDLE_LAYER_AUDIO_H
