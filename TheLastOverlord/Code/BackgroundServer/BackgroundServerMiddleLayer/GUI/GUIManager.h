// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:09)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerDll.h"

#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/GUIManagerInterface.h" 

namespace BackgroundServerMiddleLayer
{
	class BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
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

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
