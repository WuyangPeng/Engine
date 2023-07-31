///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:22)

#ifndef FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(ViewMiddleLayerImpl);
FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    // 渲染中间层接口类。
    class FRAMEWORK_DEFAULT_DECLARE RenderingManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using RenderingManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(RenderingManagerInterface);
        using ParentType = EngineMiddleLayerInterface;
        using MiddleLayerSharedPtr = std::shared_ptr<ClassType>;

        using Renderer = Rendering::BaseRenderer;
        using RendererSharedPtr = std::shared_ptr<Renderer>;
        using ConstRendererSharedPtr = std::shared_ptr<const Renderer>;

    public:
        RenderingManagerInterface(MiddleLayerPlatform modelViewController, const EnvironmentDirectory& environmentDirectory);

    public:
        RenderingManagerInterface(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        NODISCARD static MiddleLayerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        NODISCARD bool Paint() override;

        NODISCARD bool Destroy() override;

        // 渲染层不处理按键消息
        bool KeyUp(int key, const WindowPoint& point) final;
        bool KeyDown(int key, const WindowPoint& point) final;
        bool SpecialKeyUp(int key, const WindowPoint& point) final;
        bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // 渲染层不处理鼠标消息
        bool PassiveMotion(const WindowPoint& point) final;
        bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);

    protected:
        NODISCARD RendererSharedPtr GetRenderer();
        NODISCARD ConstRendererSharedPtr GetRenderer() const;

    private:
        using ViewMiddleLayerPackageType = CoreTools::NonCopyImpl<ViewMiddleLayerImpl>;

    private:
        PackageType impl;
        ViewMiddleLayerPackageType viewMiddleLayer;
    };

    using RenderingManagerInterfaceSharedPtr = std::shared_ptr<RenderingManagerInterface>;
    using ConstRenderingManagerInterfaceSharedPtr = std::shared_ptr<const RenderingManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H
