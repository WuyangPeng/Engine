///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/10 14:05) 

#ifndef FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H
#define FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H

#include "Framework/FrameworkDll.h"

#include "MiddleLayerFwd.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperFwd.h"
#include "Framework/WindowCreate/WindowCreateFwd.h"
#include "Framework/WindowProcess/WindowProcessFwd.h"

template class FRAMEWORK_DEFAULT_DECLARE std::weak_ptr<Framework::MiddleLayerInterface>;
template class FRAMEWORK_DEFAULT_DECLARE std::enable_shared_from_this<Framework::MiddleLayerInterface>;

namespace Framework
{
    // �м��ӿ��࣬�����ṩ�麯����Ĭ��ʵ�֡�
    class FRAMEWORK_DEFAULT_DECLARE MiddleLayerInterface : public std::enable_shared_from_this<MiddleLayerInterface>
    {
    public:
        using ClassType = MiddleLayerInterface;
        using MiddleLayerSharedPtr = std::shared_ptr<ClassType>;

        using WindowDisplay = System::WindowsDisplay;
        using EnvironmentParameter = Rendering::EnvironmentParameter;

    protected:
        enum class MiddleLayerInterfaceCreate
        {
            Init,
        };

        MiddleLayerInterface(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept;

    public:
        MiddleLayerInterface(MiddleLayerInterfaceCreate middleLayerInterfaceCreate, MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory) noexcept;
        virtual ~MiddleLayerInterface() noexcept = default;

        MiddleLayerInterface(const MiddleLayerInterface& rhs) noexcept = delete;
        MiddleLayerInterface& operator=(const MiddleLayerInterface& rhs) noexcept = delete;
        MiddleLayerInterface(MiddleLayerInterface&& rhs) noexcept;
        MiddleLayerInterface& operator=(MiddleLayerInterface&& rhs) noexcept;

        NODISCARD static MiddleLayerSharedPtr CreateMiddleLayer(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ���������м�㴦��
        virtual bool PreCreate();
        virtual bool Create(const EnvironmentParameter& environmentParameter);
        virtual bool Initialize();

        // ���ٴ����м�㴦��
        virtual bool Destroy();
        virtual void Terminate();

        // ����ʱ���м�㴦��
        virtual void PreIdle();
        virtual bool Idle(int64_t timeDelta);

        // ��Ⱦ�м�㴦��
        virtual bool Paint();
        virtual bool Move(const WindowPoint& point);
        virtual bool Resize(WindowDisplay windowDisplay, const WindowSize& size);

        // ������Ϣ�м�㴦��
        virtual bool KeyUp(int key, const WindowPoint& point);
        virtual bool KeyDown(int key, const WindowPoint& point);
        virtual bool SpecialKeyUp(int key, const WindowPoint& point);
        virtual bool SpecialKeyDown(int key, const WindowPoint& point);

        // �����Ϣ�м�㴦��
        virtual bool PassiveMotion(const WindowPoint& point);
        virtual bool Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys);
        virtual bool MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys);
        virtual bool MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys);

        NODISCARD MiddleLayerPlatform GetMiddleLayerPlatform() const noexcept;
        NODISCARD EnvironmentDirectory GetEnvironmentDirectory() const noexcept;

    private:
        MiddleLayerPlatform middleLayerPlatform;
        EnvironmentDirectory environmentDirectory;
    };

    using MiddleLayerInterfaceSharedPtr = std::shared_ptr<MiddleLayerInterface>;
    using ConstMiddleLayerInterfaceSharedPtr = std::shared_ptr<const MiddleLayerInterface>;
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_H
