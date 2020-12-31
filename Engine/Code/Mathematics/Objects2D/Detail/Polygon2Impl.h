///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/13 14:09)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_IMPL_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Polygon2Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Polygon2Impl<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using VerticesType = std::vector<Vector2D>;

    public:
        // ���÷�����ȷ������������ʱ�룬����һ���򵥵Ķ���Ρ�
        // ʹ�ù��������ָ��
        explicit Polygon2Impl(const VerticesType& vertices);

        CLASS_INVARIANT_DECLARE;

        // ֻ����Ա���ʡ�
        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const VerticesType& GetVertices() const noexcept;
        [[nodiscard]] const Vector2D& GetVertex(int index) const;

        // �������޸ġ������߱���ȷ���������Ȼ�Ǽ򵥶���Ρ�
        void SetVertex(int index, const Vector2D& vertex);

        // ���������������εĸ�����Ϣ��
        [[nodiscard]] const Vector2D ComputeVertexAverage() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] Real ComputePerimeterLength() const;
        [[nodiscard]] Real ComputeArea() const;

    private:
        static constexpr auto sm_MinSize = 4;

    private:
        VerticesType m_Vertices;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_POLYGON2_IMPL_H
