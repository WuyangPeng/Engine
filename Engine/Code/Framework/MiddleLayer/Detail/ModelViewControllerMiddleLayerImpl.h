// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:45)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/MiddleLayerInterface.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ModelViewControllerMiddleLayerImpl
	{
	public:
		using ClassType = ModelViewControllerMiddleLayerImpl;
		using MiddleLayerWeakPtr = std::weak_ptr<MiddleLayerInterface>;
		using MiddleLayerSharedPtr = MiddleLayerInterfaceSharedPtr;
		using ConstMiddleLayerSharedPtr = ConstMiddleLayerInterfaceSharedPtr;

	public:
		ModelViewControllerMiddleLayerImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		void SetModelMiddleLayer(const MiddleLayerSharedPtr& modelMiddleLayer) noexcept;
		void SetViewMiddleLayer(const MiddleLayerSharedPtr& viewMiddleLayer) noexcept;
		void SetControllerMiddleLayer(const MiddleLayerSharedPtr& controllerMiddleLayer) noexcept;

		const MiddleLayerSharedPtr GetModelMiddleLayer() noexcept;
		const MiddleLayerSharedPtr GetViewMiddleLayer() noexcept;
		const MiddleLayerSharedPtr GetControllerMiddleLayer() noexcept;

		const ConstMiddleLayerSharedPtr GetConstModelMiddleLayer() const noexcept;
		const ConstMiddleLayerSharedPtr GetConstViewMiddleLayer() const noexcept;
		const ConstMiddleLayerSharedPtr GetConstControllerMiddleLayer() const noexcept;		

	private:
		MiddleLayerWeakPtr m_ModelMiddleLayer;
		MiddleLayerWeakPtr m_ViewMiddleLayer;
		MiddleLayerWeakPtr m_ControllerMiddleLayer;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H

