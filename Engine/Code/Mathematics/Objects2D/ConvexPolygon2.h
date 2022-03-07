///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 11:07)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Line2.h"
#include "Polygon2.h"
#include "Mathematics/Algebra/Vector2.h"

#include <set>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class ConvexPolygon2 final : public Polygon2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ConvexPolygon2<Real>;
        using ParentType = Polygon2<Real>;
        using Line2 = Line2<Real>;
        using LineType = std::vector<Line2>;
        using Math = ParentType::Math;
        using Vector2 = ParentType::Vector2;
        using VerticesType = ParentType::VerticesType;
        using Vector2Tools = ParentType::Vector2Tools;

    public:
        // ���÷�����ȷ�����������ʾ͹����Σ�����ʱ��˳��
        ConvexPolygon2(const VerticesType& vertices, const LineType& lines);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ֻ����Ա���ʡ�
        NODISCARD LineType GetLines() const;
        NODISCARD const Line2& GetLine(int index) const;

        // �������޸ġ������߱���ȷ�����������͹����Ρ�
        // ֻҪ���޸ľ����ܶ�Ķ���󣬵���UpdateLines()��
        // ���о���SetVertex���޸ģ�UpdateLines���ߵĸ��£�ֻ���޸ĵĹ���Ķ���ı߽��С�
        void SetVertex(int index, const Vector2& vertex) override;
        void UpdateLines();
        NODISCARD bool IsUpdateLines() const noexcept;

        // �����Ƿ���͹����Ρ�
        // ��������������ö���εıߺ���֤ÿ���ߵĶ���εĶ��㶼�ڱ�Ե�ߵķǸ��ࡣ
        // ���ž������ʱ������һ��������һ���ߣ�����͹���ķ���ʱ��
        // ���з��ŵľ�������d < 0����ֵ���������������ȷ͹�Բ��ԣ�
        // ����һ��С�ĸ���ֵt����ͨ���ú�����
        // ����������£�������Ի���d < t < 0��
        NODISCARD bool IsConvex(Real threshold = -Math::GetZeroTolerance()) const;

        // ���ڶ���εĲ��ԣ��ڵ�ͱ�Ե���ߣ���n������֮��ߵĲ�ѯִ�У�ΪO(n)�㷨��
        // �ⲻ�������㷨��TODO�������������㷨��������ࡣ����һ��O(log n)���㷨��
        NODISCARD bool Contains(const Vector2& point, Real threshold = -Math::GetZeroTolerance()) const;

    private:
        // ֧�ֵı�Ե�ߵĸ�Ч���¡�
        // set�洢��Щ�޸Ĺ�����ߵ�������
        void UpdateLine(int index, const Vector2& average);

    private:
        using SharingType = std::set<int>;

    private:
        // �ߵ������Ƕ����������
        LineType lines;

        // Ҫ��UpdateLine����Ĺ����
        SharingType sharingEdges;
    };

    using ConvexPolygon2F = ConvexPolygon2<float>;
    using ConvexPolygon2D = ConvexPolygon2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H
