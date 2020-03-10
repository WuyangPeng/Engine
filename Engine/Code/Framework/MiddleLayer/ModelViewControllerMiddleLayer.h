// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "MiddleLayerInterface.h"

FRAMEWORK_EXPORT_SHARED_PTR(ModelViewControllerMiddleLayerImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE ModelViewControllerMiddleLayer : public MiddleLayerInterface
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ModelViewControllerMiddleLayer);
		using ParentType = MiddleLayerInterface;

	public:
		ModelViewControllerMiddleLayer();
		virtual ~ModelViewControllerMiddleLayer();
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;
		
		void SetModelMiddleLayer(const MiddleLayerInterfaceSmartPointer& modelMiddleLayer);
		void SetViewMiddleLayer(const MiddleLayerInterfaceSmartPointer& viewMiddleLayer);
		void SetControllerMiddleLayer(const MiddleLayerInterfaceSmartPointer& controllerMiddleLayer);

	protected:
		const MiddleLayerInterfaceSmartPointer GetModelMiddleLayer();
		const MiddleLayerInterfaceSmartPointer GetViewMiddleLayer();
		const MiddleLayerInterfaceSmartPointer GetControllerMiddleLayer();

		const ConstMiddleLayerInterfaceSmartPointer GetConstModelMiddleLayer() const;
		const ConstMiddleLayerInterfaceSmartPointer GetConstViewMiddleLayer() const;
		const ConstMiddleLayerInterfaceSmartPointer GetConstControllerMiddleLayer() const;

	private:		
		IMPL_TYPE_DECLARE(ModelViewControllerMiddleLayer);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Second,ModelViewControllerMiddleLayer);
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_H

