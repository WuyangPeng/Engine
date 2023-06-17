///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/AVector.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PointControllerImpl
    {
    public:
        using ClassType = PointControllerImpl;
        using AVector = Mathematics::AVectorF;

    public:
        explicit PointControllerImpl(int numPoints);
        PointControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // ���˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
        // ���е����һ��������Ӧ�ó���
        // �����ѡ���ϵͳ��ԭ��Ϊ����������ĺ�
        // �������Ӧ�ڹ���������������
        NODISCARD int GetNumPoints() const noexcept;
        NODISCARD float GetPointLinearSpeed(int index) const;
        NODISCARD float GetPointAngularSpeed(int index) const;
        NODISCARD AVector GetPointLinearAxis(int index) const;
        NODISCARD AVector GetPointAngularAxis(int index) const;

        void SetPointLinearSpeed(int index, float pointLinearSpeed);
        void SetPointAngularSpeed(int index, float pointAngularSpeed);
        void SetPointLinearAxis(int index, const AVector& pointLinearAxis);
        void SetPointAngularAxis(int index, const AVector& pointAngularAxis);

        NODISCARD float GetSystemLinearSpeed() const noexcept;
        void SetSystemLinearSpeed(float aSystemLinearSpeed) noexcept;
        NODISCARD float GetSystemAngularSpeed() const noexcept;
        void SetSystemAngularSpeed(float aSystemAngularSpeed) noexcept;
        NODISCARD AVector GetSystemLinearAxis() const noexcept;
        void SetSystemLinearAxis(const AVector& aSystemLinearAxis) noexcept;
        NODISCARD AVector GetSystemAngularAxis() const noexcept;
        void SetSystemAngularAxis(const AVector& aSystemAngularAxis) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

    private:
        // ϵͳ���˶����ھֲ����ꡣ�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
        float systemLinearSpeed;
        float systemAngularSpeed;
        AVector systemLinearAxis;
        AVector systemAngularAxis;

        int numPoints;
        std::vector<float> pointLinearSpeeds;
        std::vector<float> pointAngularSpeeds;
        std::vector<AVector> pointLinearAxes;
        std::vector<AVector> pointAngularAxes;
    };
}

#endif  // RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H
