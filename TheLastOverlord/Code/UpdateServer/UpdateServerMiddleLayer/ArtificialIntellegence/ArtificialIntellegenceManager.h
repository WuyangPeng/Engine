// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:58)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
#define UPDATE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerDll.h"

#include "UpdateServer/UpdateServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ArtificialIntellegenceInterface.h" 

namespace UpdateServerMiddleLayer
{
	class UPDATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ArtificialIntellegenceManager : public Framework::ArtificialIntellegenceInterface
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

#endif // UPDATE_SERVER_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_H
