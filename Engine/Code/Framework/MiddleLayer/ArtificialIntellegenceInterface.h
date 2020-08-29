// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:47)

#ifndef FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Framework/Helper/MiddleLayerMacro.h"

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
		explicit ArtificialIntellegenceInterface(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE; 

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Input);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(PhysicalModelling);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Message);
		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	private:
		IMPL_TYPE_DECLARE(ArtificialIntellegenceInterface);
	};

	using ArtificialIntellegenceInterfaceSharedPtr = std::shared_ptr<ArtificialIntellegenceInterface>;
	using ConstArtificialIntellegenceInterfaceSharedPtr = std::shared_ptr<const ArtificialIntellegenceInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_ARTIFICIAL_INTELLEGENCE_INTERFACE_H

