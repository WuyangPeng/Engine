/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS_3D_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Polyhedron3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Polyhedron3<Real>;

        using MathType = Math<Real>;

        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using VerticesType = std::vector<Vector3Type>;
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

        virtual ~Polyhedron3() noexcept = default;
        Polyhedron3(const Polyhedron3& rhs) = default;
        Polyhedron3& operator=(const Polyhedron3& rhs) = default;
        Polyhedron3(Polyhedron3&& rhs) noexcept = default;
        Polyhedron3& operator=(Polyhedron3&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IndicesIsValid() const noexcept;

#endif  // OPEN_CLASS_INVARIANT

        // 只读成员访问。
        NODISCARD int GetNumVertices() const;
        NODISCARD VerticesType GetVertices() const;
        NODISCARD const Vector3Type& GetVertex(int index) const;
        NODISCARD int GetNumTriangles() const;
        NODISCARD int GetNumIndices() const;  // = 3 * numTriangles
        NODISCARD IndicesType GetIndices() const;
        NODISCARD IndicesType GetTriangle(int index) const;

        // 允许顶点修改。调用者必须确保多面体仍然是简单多面体。
        virtual void SetVertex(int index, const Vector3Type& vertex);

        // 计算关于所述多面体的各种信息。
        NODISCARD Vector3Type ComputeVertexAverage() const;
        NODISCARD Real ComputeSurfaceArea() const;
        NODISCARD Real ComputeVolume() const;

    private:
        constexpr static auto triangleVertexSize = 3;
        constexpr static auto minVerticesSize = 4;

    private:
        VerticesType vertices;
        IndicesType indices;
    };

    using Polyhedron3F = Polyhedron3<float>;
    using Polyhedron3D = Polyhedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_POLYHEDRON3_H
