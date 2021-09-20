// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/12 22:59)

#ifndef LOG_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define LOG_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerDll.h"

#include "LogServer/LogServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/GUIManagerInterface.h" 

namespace LogServerMiddleLayer
{
	class LOG_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
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

#endif // LOG_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
