/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:26)

#ifndef MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_H
#define MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Plane3.h"
#include "Polyhedron3.h"
#include "Mathematics/Base/MathDetail.h"

#include <set>

namespace Mathematics
{
    template <typename Real>
    class ConvexPolyhedron3 final : public Polyhedron3<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ConvexPolyhedron3<Real>;
        using ParentType = Polyhedron3<Real>;

        using Math = Math<Real>;
        using Plane3 = Plane3<Real>;

        // 该Plane表示Dot(N,X) = c。
        // N表示单位法线在这个平面。
        // c表示平面的常量。
        // X是平面上的任意点。
        using PlaneContainerType = std::vector<Plane3>;
        using TrianglesType = std::set<int>;

        using Vector3 = typename ParentType::Vector3;
        using Vector3Tools = typename ParentType::Vector3Tools;
        using VerticesType = typename ParentType::VerticesType;
        using IndicesType = typename ParentType::IndicesType;

    public:
        // 调用者负责确保网格代表一个凸多面体。
        // 从网格外面观察时，三角形的面必须保持逆时针顺序。
        //
        // Polyhedron3对象一般从其他来源共享数据。
        // 这个类使用智能指针（SmartPointer1DArray）共享输入数组。
        // 如果您不希望类删除数组，使用自己的智能指针的数组。
        //
        // ConvexPolyhedron3存储与所述面相关联的平面。平面法线内指示。
        // 该平面可以被构造函数提供，如果他们不通过参数传递（“planes”为空），类自动生成它们。
        ConvexPolyhedron3(const VerticesType& vertices, const IndicesType& indices, const PlaneContainerType& planes);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 只读成员访问。
        NODISCARD PlaneContainerType GetPlanes() const;
        NODISCARD const Plane3& GetPlane(int index) const;

        // 允许顶点修改。调用者必须确保多面体仍是凸多面体。
        // 只要你修改尽可能多的顶点后，调用UpdatePlanes()。
        // 所有经由SetVertex的修改，
        // UpdatePlanes中面的更新，只在修改的共享的顶点的三角形进行。
        void SetVertex(int index, const Vector3& vertex) override;
        void UpdatePlanes();
        NODISCARD bool IsUpdatePlanes() const noexcept;

        // 测试凸性。
        // 这个函数将遍历该多面体的面和验证每个面的多面体的顶点都在平面的非负侧。
        // 符号距离测试时，这样一个顶点是一条平面（用于凸）的反面时，
        // 其有符号的距离满足d < 0，数值舍入误差会产生不正确凸性测试，
        // 所以一个小的负阈值t可能通过该函数，
        // 在这种情况下，距离测试会变成d < t < 0。
        NODISCARD bool IsConvex(Real threshold = -Math::GetZeroTolerance()) const;

        // 点在多面体的测试，在点和平面的面，在n个顶点之间查询执行，为O(n)算法。
        // 这不是最优算法。可将基本BSP算法用于这个类。这是一个O(log n)的算法。
        NODISCARD bool Contains(const Vector3& point, Real threshold = -Math::GetZeroTolerance()) const;

    private:
        void InitPlanes();

        // 支持的平面的高效更新。
        // set存储那些修改共享顶点三角形的索引。
        void UpdatePlane(int index, const Vector3& average);

    private:
        // 	面的数量是三角形的数量。
        PlaneContainerType planes;

        // 要在UpdatePlane处理的共享三角形
        TrianglesType sharingTriangles;
    };

    using ConvexPolyhedron3F = ConvexPolyhedron3<float>;
    using ConvexPolyhedron3D = ConvexPolyhedron3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_CONVEX_POLYHEDRON3_H
