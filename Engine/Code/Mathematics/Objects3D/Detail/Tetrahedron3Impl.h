///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/18 13:30)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Plane3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Tetrahedron3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Tetrahedron3Impl<Real>;
        using Math = Math<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using ContainerType = std::vector<Vector3D>;
        using IndicesType = std::vector<int>;
        using PlaneContainerType = std::vector<Plane3>;

    public:
        // �������屻��ʾΪ�ĸ���������飺V0��V1��V2��V3��
        // ���㱻����ʹ������������Ĺ۲��߹۲�ʱ��
        // �����ε����Ǳ���ʱ������������Σ�
        //   �� 0 = <V[0],V[2],V[1]>
        //   �� 1 = <V[0],V[1],V[3]>
        //   �� 2 = <V[0],V[3],V[2]>
        //   �� 3 = <V[1],V[2],V[3]>

        Tetrahedron3Impl(const Vector3D& vertex0, const Vector3D& vertex1,
                         const Vector3D& vertex2, const Vector3D& vertex3) noexcept;

        explicit Tetrahedron3Impl(const ContainerType& vertex);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetVertex(int index) const;
        void SetVertex(int index, const Vector3D& vertex);

        // ��ȡ����������ָ�����档
        [[nodiscard]] static IndicesType GetFaceIndices(int face);

        // �������������ƽ�档
        // ����������ⲿָ��ķ�������
        // ƽ��������ͬǰ���GetFaceIndices���ص�������ͬ��
        [[nodiscard]] PlaneContainerType GetPlanes() const;

    private:
        constexpr static auto sm_VertexSize = 4;

        using ArrayType = std::array<Vector3D, sm_VertexSize>;

    private:
        ArrayType m_Vertex;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_IMPL_H
