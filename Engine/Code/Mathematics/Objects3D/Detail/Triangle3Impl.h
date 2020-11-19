///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 16:39)

#ifndef MATHEMATICS_OBJECTS3D_TRIANGLE3_IMPL_H
#define MATHEMATICS_OBJECTS3D_TRIANGLE3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Triangle3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Triangle3Impl<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // �����α�ʾΪ�����������飺
        Triangle3Impl(const Vector3D& vector0, const Vector3D& vector1, const Vector3D& vector2) noexcept;

        CLASS_INVARIANT_DECLARE;

        // �ӵ�point�������εľ��롣
        [[nodiscard]] Real DistanceTo(const Vector3D& point) const;

        [[nodiscard]] const ContainerType GetVertex() const;
        [[nodiscard]] const Vector3D GetVertex(int index) const;
        [[nodiscard]] const ContainerType GetEdgeVectors() const;

        [[nodiscard]] const Vector3D GetNormal() const;

    private:
        constexpr static auto sm_VertexSize = 3;

        using ArrayType = std::array<Vector3D, sm_VertexSize>;

    private:
        ArrayType m_Vertex;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_TRIANGLE3_IMPL_H
