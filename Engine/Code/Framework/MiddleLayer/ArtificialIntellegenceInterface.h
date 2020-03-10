// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:38)

#ifndef FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Macro/MiddleLayerMacro.h"

FRAMEWORK_EXPORT_SHARED_PTR(EngineMiddleLayerInterfaceImpl);

namespace Framework
{	
	class FRAMEWORK_DEFAULT_DECLARE ArtificialIntellegenceInterface : public EngineMiddleLayerInterface
	{	
	public:
		using ArtificialIntellegenceInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_CLASSES_TYPE_DECLARE(ArtificialIntellegenceInterface);
		using ParentType = EngineMiddleLayerInterface;

	public:
		ArtificialIntellegenceInterface();
		virtual ~ArtificialIntellegenceInterface();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	private:
		IMPL_TYPE_DECLARE(ArtificialIntellegenceInterface);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ArtificialIntellegenceInterface);
}

#endif // FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_INTERFACE_H

