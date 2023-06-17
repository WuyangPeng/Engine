///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_H
#define RENDERING_CONTROLLERS_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "ControllerInterface.h"
#include "Flags/ControllerFlags.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Controller, ControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Controller : public ControllerInterface
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Controller);
        using ParentType = ControllerInterface;

    public:
        explicit Controller(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Controller);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD const ControllerInterface* GetControllerObject() const noexcept override;
        NODISCARD ControllerInterface* GetControllerObject() noexcept override;

        NODISCARD bool Update(double applicationTime) override;

        // 这个函数是公有的,因为类ControlledObject需要设置对象在调用AttachController。
        // 派生类管理一组控制器时还需要在调用AttachController设置对象。
        void SetObject(ControllerInterface* aObject) override;

        void SetApplicationTime(double applicationTime) noexcept;
        NODISCARD double GetApplicationTime() const noexcept;

        NODISCARD double GetControlTime(double applicationTime);

        NODISCARD ControllerRepeatType GetRepeat() const noexcept;
        NODISCARD double GetMinTime() const noexcept;
        NODISCARD double GetMaxTime() const noexcept;
        NODISCARD double GetPhase() const noexcept;
        NODISCARD double GetFrequency() const noexcept;
        NODISCARD bool IsActive() const noexcept;

        void SetRepeat(ControllerRepeatType repeat) noexcept;
        void SetTime(double minTime, double maxTime) noexcept;
        void SetPhase(double phase) noexcept;
        void SetFrequency(double frequency) noexcept;
        void SetActive(bool active) noexcept;

    private:
        PackageType impl;

        // 控制对象。这是一个常规的指针,而不是一个智能指针,
        // 以避免引用循环在m_Object和'this'之间。
        ControllerInterface* controllerInterface;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Controller);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Controller);
}
#endif  // RENDERING_CONTROLLERS_CONTROLLER_H
