/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/12/05 10:27)

#ifndef MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_H
#define MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Base/SpanIterator.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Plane.h"
#include "Mathematics/Algebra/Transform.h"
#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename T>
    requires std::is_floating_point_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BoundingSphere
    {
    public:
        using ClassType = BoundingSphere<T>;

        using Transform = Transform<T>;
        using Math = Math<T>;
        using Plane = Plane<T>;
        using APoint = APoint<T>;
        using AVector = AVector<T>;
        using Vector3 = Vector3<T>;

        using PixelType = std::vector<char>;
        using PixelTypeConstIter = PixelType::const_iterator;
        using SpanConstIterator = CoreTools::SpanIterator<PixelTypeConstIter>;

        using APointContainer = std::vector<APoint>;
        using Vector3Container = std::vector<Vector3>;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        // Ĭ�Ϲ��캯������������Ϊԭ��(0,0,0)�����뾶����Ϊ0���뾶Ϊ0��ʾ�߽���Ч��
        constexpr BoundingSphere() noexcept
            : center{}, radius{}
        {
        }

        // �߽�ָ��Ϊһ��ָ�����ĺͰ뾶�����塣
        BoundingSphere(const APoint& center, T radius);

        CLASS_INVARIANT_DECLARE;

        // �κα߽���붨��һ�����ĺ�һ���뾶���뾶�����ǷǸ��ġ�
        void SetCenter(const APoint& aCenter) noexcept;
        void SetRadius(T aRadius);
        NODISCARD APoint GetCenter() const noexcept;
        NODISCARD T GetRadius() const noexcept;

        /// �߽��ϵĲ�����

        /// ƽ��ġ����桱��ƽ�淨��ָ��İ�ռ䡣�����桱����һ��ռ䡣
        /// ��������ȫλ������ʱ����������NumericalValueSymbol::Positive��
        /// ��������ȫ���ڸ���ʱ����NumericalValueSymbol::Negative��
        /// �����屻ƽ������и�ʱ����NumericalValueSymbol::Zero��ƽ����������������Ϊ������
        /// epsilonΪƫ����ȫ�и�������Ҫƫ�������棬epsilon���븺����
        NODISCARD NumericalValueSymbol WhichSide(const Plane& plane, T epsilon = Math::GetZeroTolerance()) const noexcept;

        /// ���� 'this' �԰����������塣
        void GrowToContain(const BoundingSphere& bound, T epsilon = Math::GetZeroTolerance());

        /// �任���塣����任���в��������ţ������ɵĶ���Ϊ�����塣������һ����������������塣
        NODISCARD BoundingSphere TransformBy(const Transform& transform) const;

        /// �˺�����������3ͨ���� (x,y,z)��4ͨ��ʸ�� (x,y,z,0)��4ͨ����(x,y,z,1)��
        /// ����������£�������ֻ����(x,y,z) ��ֵ��stride���������붥�㻺�������ݡ�
        /// �������ڴ�������ʱ����stride����Ϊ�㡣��data��ָ�����ָ���һ���㣨ƫ����0����
        void ComputeFromData(int numElements, int stride, SpanConstIterator data);
        void ComputeFromData(const APointContainer& data);
        void ComputeFromData(const Vector3Container& data);

        // �������Է����ͱ߽��Ƿ��ཻ�������㽻ս�������Է���ͨ��P + t * D���в�������
        // ����P��һ�������ϵĵ㣨ԭ�㣩��D��һ����λ�������������[tMin,tMax]��
        // line: tMin = -MathF::maxReal, tMax = MathF::maxReal
        // ray: tMin = 0.0f, tMax = MathF::maxReal
        // segment: tMin >= 0.0f, tMax > tMin
        NODISCARD bool TestIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

        NODISCARD int GetStreamingSize() const noexcept;
        void ReadAggregate(BufferSource& source);
        void WriteAggregate(BufferTarget& target) const;

    private:
        NODISCARD bool TestLineIntersection(const APoint& origin, const AVector& direction, T tMax) const noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD bool TestRayIntersection(const APoint& origin, const AVector& direction, T tMin) const noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD bool TestSegmentIntersection(const APoint& origin, const AVector& direction, T tMin, T tMax) const;

    private:
        APoint center{};
        T radius{};
    };

    /// ���������̶��ı߽��Ƿ��ཻ��
    /// epsilonΪ�ཻ�������Ҫƫ���ཻ��epsilon���븺����
    template <typename T>
    NODISCARD bool TestIntersection(const BoundingSphere<T>& lhsBound, const BoundingSphere<T>& rhsBound, T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    // ���������˶��ı߽��Ƿ��ཻ�� lhsVelocity��lhsBound���ٶȣ���rhsVelocity��rhsBound���ٶȡ�
    template <typename T>
    NODISCARD bool TestIntersection(const BoundingSphere<T>& lhsBound, const AVector<T>& lhsVelocity, const BoundingSphere<T>& rhsBound, const AVector<T>& rhsVelocity, T tMax);

    template <typename T>
    NODISCARD bool Approximate(const BoundingSphere<T>& lhs, const BoundingSphere<T>& rhs, T epsilon = Math<T>::GetZeroTolerance());

    using BoundingSphereF = BoundingSphere<float>;
    using BoundingSphereD = BoundingSphere<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BOUNDING_SPHERE_H
