///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/08 14:03)

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

// ��Ⱦ�м��ӿ��ࡣ
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE RenderingManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using RenderingManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(RenderingManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

        using BaseRenderer = Rendering::BaseRenderer;
        using RendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using ConstRendererSharedPtr = std::shared_ptr<const BaseRenderer>;

    public:
        RenderingManagerInterface(MiddleLayerPlatform modelViewController, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Create(const EnvironmentParameter& environmentParameter) override;
        NODISCARD bool Initialize() override;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) override;

        NODISCARD bool Paint() override;
        NODISCARD bool Destroy() override;

        // ��Ⱦ�㲻��������Ϣ
        bool KeyUp(int key, const WindowPoint& point) final;
        bool KeyDown(int key, const WindowPoint& point) final;
        bool SpecialKeyUp(int key, const WindowPoint& point) final;
        bool SpecialKeyDown(int key, const WindowPoint& point) final;

        // ��Ⱦ�㲻���������Ϣ
        bool PassiveMotion(const WindowPoint& point) final;
        bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;
        bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys) final;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System)

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
