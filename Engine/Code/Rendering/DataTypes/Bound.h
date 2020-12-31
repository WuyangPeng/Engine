//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.1 (2020/08/30 14:22)

#ifndef RENDERING_DATA_TYPES_BOUND_H
#define RENDERING_DATA_TYPES_BOUND_H

#include "Rendering/RenderingDll.h"

#include "Transform.h"
#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>

namespace Rendering
{
    template <typename T>
    class RENDERING_TEMPLATE_DEFAULT_DECLARE Bound
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = Bound<T>;
        using Transform = Transform<T>;
        using Math = Mathematics::Math<T>;
        using Plane = Mathematics::Plane<T>;
        using APoint = Mathematics::APoint<T>;
        using AVector = Mathematics::AVector<T>;
        using Vector3D = Mathematics::Vector3D<T>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;

        using PixelType = std::vector<char>;
        using PixelTypeConstIter = PixelType::const_iterator;
        using SpanConstIterator = CoreTools::SpanIterator<PixelTypeConstIter>;

        using APointContainer = std::vector<APoint>;
        using Vector3DContainer = std::vector<Vector3D>;

    public:
        // �߽�ָ��Ϊһ��ָ�����ĺͰ뾶�����塣
        Bound(const APoint& center, T radius);

        constexpr Bound() noexcept
            : m_Center{}, m_Radius{}
        {
        }

        CLASS_INVARIANT_DECLARE;

        // �κα߽���붨��һ�����ĺ�һ���뾶��
        void SetCenter(const APoint& center) noexcept;
        void SetRadius(T radius);
        [[nodiscard]] const APoint& GetCenter() const noexcept;
        [[nodiscard]] T GetRadius() const noexcept;

        [[nodiscard]] int GetStreamingSize() const noexcept;

        // �߽��ϵĲ�����
        [[nodiscard]] NumericalValueSymbol WhichSide(const Plane& plane) const noexcept;
        void GrowToContain(const Bound& bound);
        [[nodiscard]] const Bound TransformBy(const Transform& transform) const;
        void ComputeFromData(int numElements, int stride, SpanConstIterator data);
        void ComputeFromData(const APointContainer& data);
        void ComputeFromData(const Vector3DContainer& data);

        // �������Է����ͱ߽��Ƿ��ཻ�������㽻ս�������Է���ͨ��P + t * D���в�������
        // ����P��һ�������ϵĵ㣨ԭ�㣩��D��һ����λ�������������[tmin,tmax]��
        // line: tmin = -Mathf::sm_MaxReal, tmax = Mathf::sm_MaxReal
        // ray: tmin = 0.0f, tmax = Mathf::sm_MaxReal
        // segment: tmin >= 0.0f, tmax > tmin
        [[nodiscard]] bool TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        [[nodiscard]] bool TestLineIntersection(const APoint& origin, const AVector& direction, T tMax) const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] bool TestRayIntersection(const APoint& origin, const AVector& direction, T tMin) const noexcept(g_Assert < 2 || g_RenderingAssert < 2);
        [[nodiscard]] bool TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

    private:
        APoint m_Center{};
        T m_Radius{};
    };

    // ���������̶��ı߽��Ƿ��ཻ��
    template <typename T>
    [[nodiscard]] bool TestIntersection(const Bound<T>& lhsBound, const Bound<T>& rhsBound) noexcept;

    // ���������˶��ı߽��Ƿ��ཻ�� lhsVelocity��lhsBound���ٶȣ���rhsVelocity��rhsBound���ٶȡ�
    template <typename T>
    [[nodiscard]] bool TestIntersection(const Bound<T>& lhsBound, const Mathematics::AVector<T>& lhsVelocity, const Bound<T>& rhsBound, const Mathematics::AVector<T>& rhsVelocity, float tMax);

    template <typename T>
    [[nodiscard]] bool Approximate(const Bound<T>& lhs, const Bound<T>& rhs, const float epsilon = Mathematics::Math<T>::GetZeroTolerance()) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    using FloatBound = Bound<float>;
    using DoubleBound = Bound<double>;
}

#endif  // RENDERING_DATA_TYPES_BOUND_H
