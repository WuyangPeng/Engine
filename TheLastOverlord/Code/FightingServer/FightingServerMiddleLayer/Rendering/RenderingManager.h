// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:50)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
#define FIGHTING_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerDll.h"

#include "FightingServer/FightingServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/RenderingManagerInterface.h" 

namespace FightingServerMiddleLayer
{
	class FIGHTING_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager : public Framework::RenderingManagerInterface
	{
	public:
		using ClassType = RenderingManager;
		using ParentType = Framework::RenderingManagerInterface;
		
	public:
		RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~RenderingManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // FIGHTING_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
