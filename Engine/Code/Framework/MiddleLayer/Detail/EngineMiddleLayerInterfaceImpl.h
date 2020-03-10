// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:36)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "CoreTools/MemoryTools/SubclassWeakPointer.h"

#include <vector>

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE EngineMiddleLayerInterfaceImpl
	{	
	public:
		using ClassType = EngineMiddleLayerInterfaceImpl;

	public:
		explicit EngineMiddleLayerInterfaceImpl(int containerSize);
	
		CLASS_INVARIANT_DECLARE;

		MiddleLayerInterfaceSmartPointer GetMiddleLayerInterface(int index);
		ConstMiddleLayerInterfaceSmartPointer GetConstMiddleLayerInterface(int index) const;

		void SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSmartPointer& middleLayer);
 
	private:
		using WeakPointer = CoreTools::SubclassWeakPointer<MiddleLayerInterfaceSmartPointer>;
		using Container = std::vector<WeakPointer>;

	private:
		Container m_Container;
	};	  
}

#endif // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H

