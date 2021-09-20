// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/09 22:39)

#ifndef GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/GUIManagerInterface.h" 

namespace GameClientMiddleLayer
{
	class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
	{
	public:
		using ClassType = GUIManager;
		using ParentType = Framework::GUIManagerInterface;
		
	public:
		GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~GUIManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GAME_CLIENT_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
