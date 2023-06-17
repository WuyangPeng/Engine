///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:55)

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
#include "Mathematics/Algebra/Vector3.h"

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
        using Vector3D = Mathematics::Vector3<T>;
        using NumericalValueSymbol = Mathematics::NumericalValueSymbol;

        using PixelType = std::vector<char>;
        using PixelTypeConstIter = PixelType::const_iterator;
        using SpanConstIterator = CoreTools::SpanIterator<PixelTypeConstIter>;

        using APointContainer = std::vector<APoint>;
        using Vector3DContainer = std::vector<Vector3D>;

        using Float = Bound<float>;
        using Double = Bound<double>;

    public:
        // �߽�ָ��Ϊһ��ָ�����ĺͰ뾶�����塣
        Bound(const APoint& center, T radius);

        constexpr Bound() noexcept
            : center{}, radius{}
        {
        }

        CLASS_INVARIANT_DECLARE;

        // �κα߽���붨��һ�����ĺ�һ���뾶��
        void SetCenter(const APoint& newCenter) noexcept;
        void SetRadius(T mewRadius);
        NODISCARD const APoint& GetCenter() const noexcept;
        NODISCARD T GetRadius() const noexcept;

        NODISCARD int GetStreamingSize() const noexcept;

        // �߽��ϵĲ�����
        NODISCARD NumericalValueSymbol WhichSide(const Plane& plane) const noexcept;
        void GrowToContain(const Bound& bound);
        NODISCARD const Bound TransformBy(const Transform& transform) const;
        void ComputeFromData(int numElements, int stride, SpanConstIterator data);
        void ComputeFromData(const APointContainer& data);
        void ComputeFromData(const Vector3DContainer& data);

        // �������Է����ͱ߽��Ƿ��ཻ�������㽻ս�������Է���ͨ��P + t * D���в�������
        // ����P��һ�������ϵĵ㣨ԭ�㣩��D��һ����λ�������������[tmin,tmax]��
        // line: tmin = -Mathf::maxReal, tmax = Mathf::maxReal
        // ray: tmin = 0.0f, tmax = Mathf::maxReal
        // segment: tmin >= 0.0f, tmax > tmin
        NODISCARD bool TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

        void ReadAggregate(CoreTools::BufferSource& source);
        void WriteAggregate(CoreTools::BufferTarget& target) const;

    private:
        NODISCARD bool TestLineIntersection(const APoint& origin, const AVector& direction, T tMax) const noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD bool TestRayIntersection(const APoint& origin, const AVector& direction, T tMin) const noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD bool TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

    private:
        APoint center{};
        T radius{};
    };

    // ���������̶��ı߽��Ƿ��ཻ��
    template <typename T>
    NODISCARD bool TestIntersection(const Bound<T>& lhsBound, const Bound<T>& rhsBound) noexcept;

    // ���������˶��ı߽��Ƿ��ཻ�� lhsVelocity��lhsBound���ٶȣ���rhsVelocity��rhsBound���ٶȡ�
    template <typename T>
    NODISCARD bool TestIntersection(const Bound<T>& lhsBound, const Mathematics::AVector<T>& lhsVelocity, const Bound<T>& rhsBound, const Mathematics::AVector<T>& rhsVelocity, float tMax);

    template <typename T>
    NODISCARD bool Approximate(const Bound<T>& lhs, const Bound<T>& rhs, const float epsilon = Mathematics::Math<T>::GetZeroTolerance()) noexcept(gAssert < 3 || gMathematicsAssert < 3);

    using BoundF = Bound<float>;
    using BoundD = Bound<double>;
}

#endif  // RENDERING_DATA_TYPES_BOUND_H
