/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 17:02)

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
        explicit Controller(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Controller);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD ConstControllerSharedPtr GetController() const override;
        NODISCARD ControllerSharedPtr GetController() override;

        NODISCARD bool Update(double applicationTime) override;

        /// ControlledObject类需要在调用AttachController时设置对象。
        /// 管理一组控制器的派生类也需要在调用AttachController时设置对象。
        void SetController(const ControllerSharedPtr& controller) override;

        void SetApplicationTime(double applicationTime) noexcept;
        NODISCARD double GetApplicationTime() const noexcept;

        NODISCARD double GetControlTime(double applicationTime) const;

        NODISCARD ControllerRepeatType GetRepeat() const noexcept;
        NODISCARD double GetMinTime() const noexcept;
        NODISCARD double GetMaxTime() const noexcept;
        NODISCARD double GetPhase() const noexcept;
        NODISCARD double GetFrequency() const noexcept;
        NODISCARD bool IsActive() const noexcept;

        void SetRepeat(ControllerRepeatType repeat) noexcept;
        void SetTime(double minTime, double maxTime);
        void SetPhase(double phase) noexcept;
        void SetFrequency(double frequency) noexcept;
        void SetActive(bool active) noexcept;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Controller);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Controller);
}
#endif  // RENDERING_CONTROLLERS_CONTROLLER_H
