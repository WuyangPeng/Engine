// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:45)

#ifndef FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/MiddleLayerInterface.h" 

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

		MiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index);
		ConstMiddleLayerInterfaceSharedPtr GetMiddleLayerInterface(int index) const;

		void SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer);
		int GetSize() const;

	private:
		using WeakPointer = std::weak_ptr<MiddleLayerInterface>;
		using Container = std::vector<WeakPointer>;

	private:
		Container m_Container;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_ENGINE_MIDDLE_LAYER_INTERFACE_IMPL_H

