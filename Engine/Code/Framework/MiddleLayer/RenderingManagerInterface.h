/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/13 14:29)

#ifndef FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SharedPtrMacro.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(RenderingManagerImpl);
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

        NODISCARD bool Destroy() override;

        void PreIdle() override;
        NODISCARD bool Idle(int64_t timeDelta) override;

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
        using RenderingPackageType = CoreTools::NonCopyImpl<RenderingManagerImpl>;

    private:
        PackageType impl;
        RenderingPackageType rendering;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(RenderingManagerInterface);
}

#endif  // FRAMEWORK_MIDDLE_LAYER_RENDERING_MANAGER_INTERFACE_H
