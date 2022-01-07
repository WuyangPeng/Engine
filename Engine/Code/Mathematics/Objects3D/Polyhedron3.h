///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 18:37)

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
        // 调用者负责确保网格代表一个简单的多面体
        // （二维流形与球体的拓扑，非自相交的拓扑结构）。
        // 三角形面，从网格外观察时必须逆时针顺序。
        //
        // Polyhedron3对象一般从其他来源共享数据。
        // 这个类使用智能指针（SmartPointer1DArray）共享输入数组。
        // 如果您不希望类删除数组，使用自己的智能指针的数组。
        Polyhedron3(const VerticesType& vertices, const IndicesType& indices);

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 只读成员访问。
        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const VerticesType GetVertices() const;
        [[nodiscard]] const Vector3D& GetVertex(int index) const;
        [[nodiscard]] int GetNumTriangles() const;
        [[nodiscard]] int GetNumIndices() const;  // = 3 * numTriangles
        [[nodiscard]] const IndicesType GetIndices() const;
        [[nodiscard]] const IndicesType GetTriangle(int index) const;

        // 允许顶点修改。调用者必须确保多面体仍然是简单多面体。
        virtual void SetVertex(int index, const Vector3D& vertex);

        // 计算关于所述多面体的各种信息。
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
