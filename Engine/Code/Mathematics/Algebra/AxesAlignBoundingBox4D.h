///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 10:38)

// ������Χ��4D�������
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H

#include "Mathematics/MathematicsDll.h"

#include "Vector4D.h"

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox4D final
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = AxesAlignBoundingBox4D<T>;
        using Vector4D = Vector4D<T>;

    public:
        explicit AxesAlignBoundingBox4D(const Vector4D& minPoint, const Vector4D& maxPoint);

        template <typename RhsType>
        AxesAlignBoundingBox4D(const AxesAlignBoundingBox4D<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector4D GetMinPoint() const noexcept;
        [[nodiscard]] const Vector4D GetMaxPoint() const noexcept;

    private:
        void Recalculate();

    private:
        Vector4D m_MinPoint;
        Vector4D m_MaxPoint;
    };

    using FloatAxesAlignBoundingBox4D = AxesAlignBoundingBox4D<float>;
    using DoubleAxesAlignBoundingBox4D = AxesAlignBoundingBox4D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_H