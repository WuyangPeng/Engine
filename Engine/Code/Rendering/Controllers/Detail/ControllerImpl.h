/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 16:36)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/NameMacro.h"
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
        using ControllerWeakPtr = std::weak_ptr<ControllerInterface>;
        using ControllerSharedPtr = std::shared_ptr<ControllerInterface>;
        using ConstControllerSharedPtr = std::shared_ptr<const ControllerInterface>;

    public:
        ControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetApplicationTime(double aApplicationTime) noexcept;
        NODISCARD double GetApplicationTime() const noexcept;

        // 动画更新。以毫秒为单位的应用程序时间。
        NODISCARD bool Update(double aApplicationTime) noexcept;

        // 从应用程序单位时间转换控制器单位时间。派生类可以使用此更新程序。
        NODISCARD double GetControlTime(double aApplicationTime) const;

        NODISCARD ControllerRepeatType GetRepeat() const noexcept;
        NODISCARD double GetMinTime() const noexcept;
        NODISCARD double GetMaxTime() const noexcept;
        NODISCARD double GetPhase() const noexcept;
        NODISCARD double GetFrequency() const noexcept;
        NODISCARD bool IsActive() const noexcept;

        void SetRepeat(ControllerRepeatType aRepeat) noexcept;
        void SetTime(double aMinTime, double aMaxTime);
        void SetPhase(double aPhase) noexcept;
        void SetFrequency(double aFrequency) noexcept;
        void SetActive(bool aActive) noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SetController(const ControllerSharedPtr& aController) noexcept;
        NODISCARD ConstControllerSharedPtr GetControllerObject() const;
        NODISCARD ControllerSharedPtr GetControllerObject();

    private:
        ControllerRepeatType repeat;  // 默认 = ControllerRepeatType::Clamp
        double minTime;  // 默认 = 0
        double maxTime;  // 默认 = 0
        double phase;  // 默认 = 0
        double frequency;  // 默认 = 1
        bool active;  // 默认 = true

        // 应用程序的时间,以毫秒为单位。
        double applicationTime;

        ControllerWeakPtr controller;
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
