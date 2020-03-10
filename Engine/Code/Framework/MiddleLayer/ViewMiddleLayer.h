// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:54)

// 视图层类的声明
#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "ModelViewControllerMiddleLayer.h"
#include "Rendering/DataTypes/ColourDetail.h" 
#include "Rendering/Renderers/Renderer.h"

#include <boost/shared_ptr.hpp>

FRAMEWORK_EXPORT_SHARED_PTR(ViewMiddleLayerImpl);

namespace Framework
{
	class WindowPoint;

	class FRAMEWORK_DEFAULT_DECLARE ViewMiddleLayer : public ModelViewControllerMiddleLayer
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ViewMiddleLayer);
		using ParentType = ModelViewControllerMiddleLayer;
		using Colour = Rendering::Colour<float>;
		using Renderer = Rendering::Renderer;
		using RendererSmartPointer = Rendering::RendererSmartPointer;
		using ConstRendererSmartPointer = Rendering::ConstRendererSmartPointer;

	public:
		ViewMiddleLayer();
		virtual ~ViewMiddleLayer();
	
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool PreCreate();
		virtual bool Initialize();
		virtual void PreIdle();
		virtual void Terminate();
		virtual bool Paint();		
		virtual bool Create();
		virtual bool Destroy();
		virtual bool Idle(int64_t timeDelta);
		virtual bool Resize(WindowDisplayFlags type, const WindowSize& size);

		void DrawFrameRate (const WindowPoint& point,const Colour& color);

		const Colour GetClearColor() const;

	protected:
		const RendererSmartPointer GetRenderer();
		const ConstRendererSmartPointer GetConstRenderer() const;

	private:
		IMPL_TYPE_DECLARE(ViewMiddleLayer);
	};

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ViewMiddleLayer);
}

#endif // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H



	