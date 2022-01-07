///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/17 18:37)

#ifndef MATHEMATICS_OBJECTS3D_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS3D_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Polyhedron3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polyhedron3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polyhedron3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Polyhedron3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Polyhedron3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Polyhedron3Impl = Polyhedron3Impl<Real>;

    protected:
        virtual void Swap(Polyhedron3& rhs) noexcept;

    public:
        TYPE_DECLARE(Polyhedron3);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        virtual ~Polyhedron3() noexcept = default;
        Polyhedron3(const Polyhedron3& rhs);
        virtual Polyhedron3& operator=(const Polyhedron3& rhs);
        Polyhedron3(Polyhedron3&& rhs) noexcept;
        virtual Polyhedron3& operator=(Polyhedron3&& rhs) noexcept;

        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using VerticesType = std::vector<Vector3D>;
        using IndicesType = std::vector<int>;

    public:
        // �����߸���ȷ���������һ���򵥵Ķ�����
        // ����ά��������������ˣ������ཻ�����˽ṹ����
        // �������棬��������۲�ʱ������ʱ��˳��
        //
        // Polyhedron3����һ���������Դ�������ݡ�
        // �����ʹ������ָ�루SmartPointer1DArray�������������顣
        // �������ϣ����ɾ�����飬ʹ���Լ�������ָ������顣
        Polyhedron3(const VerticesType& vertices, const IndicesType& indices);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ֻ����Ա���ʡ�
        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const VerticesType GetVertices() const;
        [[nodiscard]] const Vector3D& GetVertex(int index) const;
        [[nodiscard]] int GetNumTriangles() const;
        [[nodiscard]] int GetNumIndices() const;  // = 3 * numTriangles
        [[nodiscard]] const IndicesType GetIndices() const;
        [[nodiscard]] const IndicesType GetTriangle(int index) const;

        // �������޸ġ������߱���ȷ����������Ȼ�Ǽ򵥶����塣
        virtual void SetVertex(int index, const Vector3D& vertex);

        // �����������������ĸ�����Ϣ��
        [[nodiscard]] const Vector3D ComputeVertexAverage() const;
        [[nodiscard]] Real ComputeSurfaceArea() const;
        [[nodiscard]] Real ComputeVolume() const;

    private:
        using Polyhedron3ImplPtr = std::shared_ptr<ImplType>;

    private:
        Polyhedron3ImplPtr impl;
    };

    using FloatPolyhedron3 = Polyhedron3<float>;
    using DoublePolyhedron3 = Polyhedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_POLYHEDRON3_H
