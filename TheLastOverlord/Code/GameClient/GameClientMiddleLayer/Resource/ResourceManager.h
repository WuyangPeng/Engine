// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.2.0 (2020/01/09 22:44)

#ifndef GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ResourceManagerInterface.h" 

namespace GameClientMiddleLayer
{
	class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
	{
	public:
		using ClassType = ResourceManager;
		using ParentType = Framework::ResourceManagerInterface;
		
	public:
		ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ResourceManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GAME_CLIENT_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
