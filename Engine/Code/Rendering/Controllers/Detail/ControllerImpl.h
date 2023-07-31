///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 10:54)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/ControllersFwd.h"
#include "Rendering/Controllers/Flags/ControllerFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ControllerImpl
    {
    public:
        using ClassType = ControllerImpl;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using Math = Mathematics::Math<double>;
        using ControllerInterfaceWeakPtr = std::weak_ptr<ControllerInterface>;
        using ControllerInterfaceSharedPtr = std::shared_ptr<ControllerInterface>;
        using ConstControllerInterfaceSharedPtr = std::shared_ptr<const ControllerInterface>;

    public:
        ControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetApplicationTime(double applicationTime) noexcept;
        NODISCARD double GetApplicationTime() const noexcept;

        // 动画更新。以毫秒为单位的应用程序时间。
        NODISCARD bool Update(double applicationTime) noexcept;

        // 从应用程序单位时间转换控制器单位时间。派生类可以使用此更新程序。
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

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SetObject(const ControllerInterfaceSharedPtr& object) noexcept;
        NODISCARD ConstControllerInterfaceSharedPtr GetControllerObject() const;
        NODISCARD ControllerInterfaceSharedPtr GetControllerObject();

    private:
        ControllerRepeatType controllerRepeat;  // 默认 = ControllerRepeatType::Clamp
        double controllerMinTime;  // 默认 = 0
        double controllerMaxTime;  // 默认 = 0
        double controllerPhase;  // 默认 = 0
        double controllerFrequency;  // 默认 = 1
        bool controllerActive;  // 默认 = true

        // 应用程序的时间,以毫秒为单位。
        double controllerApplicationTime;

        ControllerInterfaceWeakPtr controllerInterface;
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
