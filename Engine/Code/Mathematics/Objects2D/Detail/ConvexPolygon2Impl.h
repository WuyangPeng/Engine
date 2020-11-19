///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 10:05)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

#include <set>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE ConvexPolygon2Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ConvexPolygon2Impl<Real>;
        using Line2 = Line2<Real>;
        using LineType = std::vector<Line2>;
        using LineTypeConstIter = typename LineType::const_iterator;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // ���÷�����ȷ�����������ʾ͹����Σ�����ʱ��˳��
        explicit ConvexPolygon2Impl(const LineType& lines);

        CLASS_INVARIANT_DECLARE;

        // ֻ����Ա���ʡ�
        [[nodiscard]] const LineType GetLines() const;
        [[nodiscard]] const Line2& GetLine(int index) const;
        [[nodiscard]] int GetNumLine() const;

        void SetVertex(int index);
        [[nodiscard]] bool IsUpdateLines() const noexcept;
        void ClearSharingEdges() noexcept;
        void UpdateLine(int index, const Vector2D& origin, const Vector2D& direction);

        LineTypeConstIter begin() const noexcept;
        LineTypeConstIter end() const noexcept;

    private:
        using SharingType = std::set<int>;

    private:
        // �ߵ������Ƕ����������
        LineType m_Lines;

        // Ҫ��UpdateLine����Ĺ����
        SharingType m_SharingEdges;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_H
