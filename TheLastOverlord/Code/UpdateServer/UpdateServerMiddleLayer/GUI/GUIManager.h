// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:59)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
#define UPDATE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerDll.h"

#include "UpdateServer/UpdateServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/GUIManagerInterface.h" 

namespace UpdateServerMiddleLayer
{
	class UPDATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE GUIManager : public Framework::GUIManagerInterface
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

#endif // UPDATE_SERVER_MIDDLE_LAYER_GUI_MIDDLE_LAYER_GUI_H
