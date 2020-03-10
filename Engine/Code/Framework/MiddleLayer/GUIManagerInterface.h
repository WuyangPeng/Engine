// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:48)

#ifndef FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE GUIManagerInterface : public EngineMiddleLayerInterface
	{	
	public:
		using GUIManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(GUIManagerInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		GUIManagerInterface();
		virtual ~GUIManagerInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE; 

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Rendering);

	private:
		IMPL_TYPE_DECLARE(GUIManagerInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, GUIManagerInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_GUI_MANAGER_INTERFACE_H

