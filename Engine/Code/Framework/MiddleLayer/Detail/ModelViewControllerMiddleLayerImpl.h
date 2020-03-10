// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:36)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "CoreTools/MemoryTools/SubclassWeakPointer.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE ModelViewControllerMiddleLayerImpl
	{
	public:
		using ClassType = ModelViewControllerMiddleLayerImpl;
		using WeakPointer = CoreTools::SubclassWeakPointer<MiddleLayerInterfaceSmartPointer>;

	public:
		ModelViewControllerMiddleLayerImpl(); 
	
		CLASS_INVARIANT_DECLARE; 
		
		void SetModelMiddleLayer(const MiddleLayerInterfaceSmartPointer& modelMiddleLayer);
		void SetViewMiddleLayer(const MiddleLayerInterfaceSmartPointer& viewMiddleLayer);
		void SetControllerMiddleLayer(const MiddleLayerInterfaceSmartPointer& controllerMiddleLayer);
 
		const MiddleLayerInterfaceSmartPointer GetModelMiddleLayer();
		const MiddleLayerInterfaceSmartPointer GetViewMiddleLayer();
		const MiddleLayerInterfaceSmartPointer GetControllerMiddleLayer();

		const ConstMiddleLayerInterfaceSmartPointer GetConstModelMiddleLayer() const;
		const ConstMiddleLayerInterfaceSmartPointer GetConstViewMiddleLayer() const;
		const ConstMiddleLayerInterfaceSmartPointer GetConstControllerMiddleLayer() const;

	private:		
		WeakPointer m_ModelMiddleLayer;
		WeakPointer m_ViewMiddleLayer;
		WeakPointer m_ControllerMiddleLayer;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_IMPL_H

