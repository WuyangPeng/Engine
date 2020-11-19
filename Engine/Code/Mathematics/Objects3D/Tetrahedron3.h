///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/17 16:03)

#ifndef MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H
#define MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Plane3.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Tetrahedron3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Tetrahedron3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Tetrahedron3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Tetrahedron3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Tetrahedron3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Tetrahedron3Impl = Tetrahedron3Impl<Real>;
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Tetrahedron3);

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

        Tetrahedron3(const Vector3D& vertex0, const Vector3D& vertex1,
                     const Vector3D& vertex2, const Vector3D& vertex3);

        explicit Tetrahedron3(const ContainerType& vertex);

        CLASS_INVARIANT_DECLARE;

        const Vector3D GetVertex(int index) const;
        void SetVertex(int index, const Vector3D& vertex);

        // ��ȡ����������ָ�����档
        static IndicesType GetFaceIndices(int face);

        // �������������ƽ�档
        // ����������ⲿָ��ķ�������
        // ƽ��������ͬǰ���GetFaceIndices���ص�������ͬ��
        const PlaneContainerType GetPlanes() const;

    private:
        IMPL_TYPE_DECLARE(Tetrahedron3);
    };

    using FloatTetrahedron3 = Tetrahedron3<float>;
    using DoubleTetrahedron3 = Tetrahedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_TETRAHEDRON3_H
