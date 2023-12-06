/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/20 16:36)

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

        // �������¡��Ժ���Ϊ��λ��Ӧ�ó���ʱ�䡣
        NODISCARD bool Update(double aApplicationTime) noexcept;

        // ��Ӧ�ó���λʱ��ת����������λʱ�䡣���������ʹ�ô˸��³���
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
        ControllerRepeatType repeat;  // Ĭ�� = ControllerRepeatType::Clamp
        double minTime;  // Ĭ�� = 0
        double maxTime;  // Ĭ�� = 0
        double phase;  // Ĭ�� = 0
        double frequency;  // Ĭ�� = 1
        bool active;  // Ĭ�� = true

        // Ӧ�ó����ʱ��,�Ժ���Ϊ��λ��
        double applicationTime;

        ControllerWeakPtr controller;
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
