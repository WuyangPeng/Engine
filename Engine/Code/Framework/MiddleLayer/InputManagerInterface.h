///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 17:03)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "EngineMiddleLayerInterface.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Framework/Helper/MiddleLayerMacro.h"

FRAMEWORK_NON_COPY_EXPORT_IMPL(EngineMiddleLayerInterfaceImpl);

namespace Framework
{
    // ��ҿ��ƣ���������Ӳ������ת��Ϊ��Ϸ���
    class FRAMEWORK_DEFAULT_DECLARE InputManagerInterface : public EngineMiddleLayerInterface
    {
    public:
        using InputManagerInterfaceImpl = EngineMiddleLayerInterfaceImpl;
        NON_COPY_TYPE_DECLARE(InputManagerInterface);
        using ParentType = EngineMiddleLayerInterface;

    public:
        explicit InputManagerInterface(MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��Ⱦ�м�㴦��
        NODISCARD bool Paint() final;
        NODISCARD bool Move(const WindowPoint& point) final;
        NODISCARD bool Resize(WindowDisplay windowDisplay, const WindowSize& size) final;

        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(Network);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(ObjectLogic);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(System);
        ENGINE_MIDDLE_LAYER_MANAGER_DECLARE(CameraSystems);

    private:
        PackageType impl;
    };

    using InputManagerInterfaceSharedPtr = std::shared_ptr<InputManagerInterface>;
    using ConstInputManagerInterfaceSharedPtr = std::shared_ptr<const InputManagerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_INTERFACE_H
