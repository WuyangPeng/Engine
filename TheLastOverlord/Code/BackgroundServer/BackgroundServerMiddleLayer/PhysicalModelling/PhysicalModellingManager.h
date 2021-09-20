// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 18:11)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerDll.h"

#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h" 

namespace BackgroundServerMiddleLayer
{
	class BACKGROUND_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE PhysicalModellingManager : public Framework::PhysicalModellingManagerInterface
	{
	public:
		using ClassType = PhysicalModellingManager;
		using ParentType = Framework::PhysicalModellingManagerInterface;
		
	public:
		PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~PhysicalModellingManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
