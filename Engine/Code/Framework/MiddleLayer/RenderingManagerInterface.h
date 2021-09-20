// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:50)

#ifndef FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h" 
#include "EngineMiddleLayerInterface.h"  
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/Helper/MiddleLayerMacro.h"

 
EXPORT_SHARED_PTR(Framework, ViewMiddleLayerImpl, FRAMEWORK_DEFAULT_DECLARE);
FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE RenderingManagerInterface : public EngineMiddleLayerInterface
	{
	public:
		using RenderingManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
		NON_COPY_TYPE_DECLARE(RenderingManagerInterface);
		using ParentType = EngineMiddleLayerInterface;
		using Renderer = Rendering::Renderer;
		using RendererSharedPtr = Rendering::RendererSharedPtr;
		using ConstRendererSharedPtr = Rendering::ConstRendererSharedPtr;

	public:
		explicit RenderingManagerInterface(MiddleLayerPlatform middleLayerPlatform);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		bool PreCreate(const EnvironmentDirectory& environmentDirectory) override;
		bool Initialize() override;
		bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

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

		ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

	protected:
		const RendererSharedPtr GetRenderer() noexcept;
		const ConstRendererSharedPtr GetRenderer() const noexcept;

	private:
		using ViewMiddleLayerImplPtr = std::shared_ptr<ViewMiddleLayerImpl>;

	private:
                PackageType impl;
		ViewMiddleLayerImplPtr m_ViewMiddleLayer;
	};

	using RenderingManagerInterfaceSharedPtr = std::shared_ptr<RenderingManagerInterface>;
	using ConstRenderingManagerInterfaceSharedPtr = std::shared_ptr<const RenderingManagerInterface>;
}

#endif // FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H

