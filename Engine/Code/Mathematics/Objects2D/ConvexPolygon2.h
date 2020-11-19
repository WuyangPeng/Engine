///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/13 17:27)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Line2.h"
#include "Polygon2.h"
#include "Mathematics/Algebra/Vector2D.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class ConvexPolygon2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<ConvexPolygon2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<ConvexPolygon2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<ConvexPolygon2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE ConvexPolygon2 final : public Polygon2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ConvexPolygon2Impl = ConvexPolygon2Impl<Real>;
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ConvexPolygon2, DESTRUCTOR_DEFAULT);

        using ParentType = Polygon2<Real>;
        using Line2 = Line2<Real>;
        using LineType = std::vector<Line2>;
        using Math = ParentType::Math;
        using Vector2D = ParentType::Vector2D;
        using VerticesType = ParentType::VerticesType;
        using Vector2DTools = ParentType::Vector2DTools;

    public:
        // ���÷�����ȷ�����������ʾ͹����Σ�����ʱ��˳��
        ConvexPolygon2(const VerticesType& vertices, const LineType& lines);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ֻ����Ա���ʡ�
        [[nodiscard]] const LineType GetLines() const;
        [[nodiscard]] const Line2& GetLine(int index) const;

        // �������޸ġ������߱���ȷ�����������͹����Ρ�
        // ֻҪ���޸ľ����ܶ�Ķ���󣬵���UpdateLines()��
        // ���о���SetVertex���޸ģ�UpdateLines���ߵĸ��£�ֻ���޸ĵĹ���Ķ���ı߽��С�
        void SetVertex(int index, const Vector2D& vertex) override;
        void UpdateLines();
        [[nodiscard]] bool IsUpdateLines() const noexcept;

        // �����Ƿ���͹����Ρ�
        // ��������������ö���εıߺ���֤ÿ���ߵĶ���εĶ��㶼�ڱ�Ե�ߵķǸ��ࡣ
        // ���ž������ʱ������һ��������һ���ߣ�����͹���ķ���ʱ��
        // ���з��ŵľ�������d < 0����ֵ���������������ȷ͹�Բ��ԣ�
        // ����һ��С�ĸ���ֵt����ͨ���ú�����
        // ����������£�������Ի���d < t < 0��
        [[nodiscard]] bool IsConvex(Real threshold = -Math::GetZeroTolerance()) const;

        // ���ڶ���εĲ��ԣ��ڵ�ͱ�Ե���ߣ���n������֮��ߵĲ�ѯִ�У�ΪO(n)�㷨��
        // �ⲻ�������㷨��TODO�������������㷨��������ࡣ����һ��O(log n)���㷨��
        [[nodiscard]] bool Contains(const Vector2D& point, Real threshold = -Math::GetZeroTolerance()) const;

    private:
        // ֧�ֵı�Ե�ߵĸ�Ч���¡�
        // set�洢��Щ�޸Ĺ�����ߵ�������
        void UpdateLine(int index, const Vector2D& average);

    private:
        IMPL_TYPE_DECLARE(ConvexPolygon2);
    };

    using FloatConvexPolygon2 = ConvexPolygon2<float>;
    using DoubleConvexPolygon2 = ConvexPolygon2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H
