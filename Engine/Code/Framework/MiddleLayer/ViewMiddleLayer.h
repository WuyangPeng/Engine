// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H
#define FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H

#include "Framework/FrameworkDll.h"

#include "ModelViewControllerMiddleLayer.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/DataTypes/ColourDetail.h" 
#include "Framework/WindowCreate/WindowCreateFwd.h"

FRAMEWORK_EXPORT_SHARED_PTR(ViewMiddleLayerImpl);

namespace Framework
{
	// 视图层类
	class FRAMEWORK_DEFAULT_DECLARE ViewMiddleLayer : public ModelViewControllerMiddleLayer
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ViewMiddleLayer);
		using ParentType = ModelViewControllerMiddleLayer;
		using Colour = Rendering::Colour<float>;
		using Renderer = Rendering::Renderer;
		using RendererSharedPtr = Rendering::RendererSharedPtr;
		using ConstRendererSharedPtr = Rendering::ConstRendererSharedPtr;

	public:
		explicit ViewMiddleLayer(MiddleLayerPlatform middleLayerPlatform);
		~ViewMiddleLayer() noexcept = default;
		ViewMiddleLayer(const ViewMiddleLayer& rhs) noexcept = delete;
		ViewMiddleLayer& operator=(const ViewMiddleLayer& rhs) noexcept = delete;
		ViewMiddleLayer(ViewMiddleLayer&& rhs) noexcept;
		ViewMiddleLayer& operator=(ViewMiddleLayer&& rhs) noexcept;

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool PreCreate(const EnvironmentDirectory& environmentDirectory) override;
		bool Initialize() override;
		bool Paint() override;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

		void DrawFrameRate(const WindowPoint& point, const Colour& color);

		const Colour GetClearColor() const;
		void SetClearColor(const Colour& colour);

		// 按键消息中间层处理
		bool KeyUp(int key, const WindowPoint& point) final;
		bool KeyDown(int key, const WindowPoint& point) final;
		bool SpecialKeyUp(int key, const WindowPoint& point) final;
		bool SpecialKeyDown(int key, const WindowPoint& point) final;

		// 鼠标消息中间层处理
		bool PassiveMotion(const WindowPoint& point) final;
		bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
		bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

	protected:
		const RendererSharedPtr GetRenderer() noexcept;
		const ConstRendererSharedPtr GetRenderer() const noexcept;

	private:
		IMPL_TYPE_DECLARE(ViewMiddleLayer);
	};

	using ViewMiddleLayerSharedPtr = std::shared_ptr<ViewMiddleLayer>;
	using ConstViewMiddleLayerSharedPtr = std::shared_ptr<const ViewMiddleLayer>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_VIEW_MIDDLE_LAYER_H



