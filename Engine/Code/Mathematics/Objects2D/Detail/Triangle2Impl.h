///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 11:06)

#ifndef MATHEMATICS_OBJECTS2D_TRIANGLE2_IMPL_H
#define MATHEMATICS_OBJECTS2D_TRIANGLE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Triangle2Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Triangle2Impl<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using ContainerType = std::vector<Vector2D>;

    public:
        // �����α�ʾΪ�����������飺
        Triangle2Impl(const Vector2D& vector0, const Vector2D& vector1, const Vector2D& vector2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // �ӵ�point�������εľ��롣
        [[nodiscard]] Real DistanceTo(const Vector2D& point) const;

        [[nodiscard]] const ContainerType GetVertex() const;
        [[nodiscard]] const Vector2D GetVertex(int index) const;

    private:
        constexpr static auto sm_VertexSize = 3;

        using ArrayType = std::array<Vector2D, sm_VertexSize>;

    private:
        ArrayType m_Vertex;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_TRIANGLE2_IMPL_H
