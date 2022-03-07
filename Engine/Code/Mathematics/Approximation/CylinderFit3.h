///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 14:56)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H

#include "Mathematics/MathematicsDll.h"

// ��С�����������(x,y,z)��һ������Բ���塣
// ��Բ�����������C����λ�����᷽��U���뾶r���߶�h��
// Բ����ĵ�����C + (h / 2) * U��C - (h / 2) * U��
// ���(X - C)^T * (I - U * U^T) * (X - C) = r^2,��X��Բ������ϵġ�
// ���Dot(U,X - C) = h / 2��(X - C)^T * (I - U * U^T) * (X - C) <= r^2��
// ��X�ڵ���C + (h / 2) * U�ϣ�
// ���Dot(U,X - C) = -h/2��(X - C)^T * (I - U * U^T) * (X - C) <= r^2��
// ��X�ڵ���C - (h / 2) * U �ϡ�

// �����ǵ�Vector3�����顣
// ���Ϊ����C����λ�����᷽��U���뾶Real�͸߶�H��
// �����ṩ��ʼ�²��C��U������������£�m_InputsAreInitialGuess������Ϊ���桱��
// �����䱻����Ϊ���١����������������ߵ���С���˷����������ѡ��C��U��
// �ú�������ֵ����С���������0 <= e��
// ������еĵ�׼ȷ������һ��Բ���壬��e = 0��

// ������ͨ��GetExactly���׼ȷ�Ⱥ��Լ��ظ����á�
// ���C��U��Real��H����Ϊ��ʼ�²ⷴ�����������á�

// CylinderFit3<Real> fit0{ points };
// Real exactly0 = fit0.GetExactly();
// Vector3<Real> center = fit0.GetCenter();
// Vector3<Real> axis = fit0.GetAxis();
// for (int i = 0; i <= max; ++i)
// {
//     CylinderFit3<Real> fit1{ points,center,axis };
//     Real exactly1 = fit1.GetExactly();
//     if(exactly1��exactly0û��̫��ı�ʱ)
//         break;
//     center = fit1.GetCenter();
//     axis = fit1.GetAxis();
//  }

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CylinderFit3 final
    {
    public:
        using ClassType = CylinderFit3<Real>;
        using Vector3 = Vector3<Real>;
        using Points = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        explicit CylinderFit3(const Points& points, const Real epsilon = Math::GetZeroTolerance());
        CylinderFit3(const Points& points, const Vector3& guessCenter, const Vector3& guessAxis, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        // ����׼ȷ��
        NODISCARD Real GetExactly() const noexcept;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Vector3 GetAxis() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetHeight() const noexcept;

    private:
        void Fit3(const Points& points);
        void InitialGuess(const Points& points);
        void Update(const Points& points);
        NODISCARD Real ComputeHeight(const Points& points);
        void ComputeCenter(Real average);

    private:
        Vector3 center;
        Vector3 axis;
        Real radius;
        Real height;
        Real exactly;
        bool inputsAreInitialGuess;
        Real epsilon;
    };

    using CylinderFit3F = CylinderFit3<float>;
    using CylinderFit3D = CylinderFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_H
