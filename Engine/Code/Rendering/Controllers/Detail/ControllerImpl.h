///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/24 10:54)

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

        // �������¡��Ժ���Ϊ��λ��Ӧ�ó���ʱ�䡣
        NODISCARD bool Update(double applicationTime) noexcept;

        // ��Ӧ�ó���λʱ��ת����������λʱ�䡣���������ʹ�ô˸��³���
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
        ControllerRepeatType controllerRepeat;  // Ĭ�� = ControllerRepeatType::Clamp
        double controllerMinTime;  // Ĭ�� = 0
        double controllerMaxTime;  // Ĭ�� = 0
        double controllerPhase;  // Ĭ�� = 0
        double controllerFrequency;  // Ĭ�� = 1
        bool controllerActive;  // Ĭ�� = true

        // Ӧ�ó����ʱ��,�Ժ���Ϊ��λ��
        double controllerApplicationTime;

        ControllerInterfaceWeakPtr controllerInterface;
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
