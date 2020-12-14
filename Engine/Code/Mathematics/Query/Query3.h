///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 16:09)

#ifndef MATHEMATICS_QUERY_QUERY3_H
#define MATHEMATICS_QUERY_QUERY3_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Query3 : public QueryBase
    {
    public:
        using ClassType = Query3<Real>;
        using ParentType = QueryBase;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using VerticesType = std::vector<Vector3D>;

    public:
        // 基类处理浮点查询。
        explicit Query3(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const Vector3D GetVertice(int index) const;

        // 关于一个点的各种几何对象之间的关系查询。

        // 返回:
        // PlaneQueryType::PositiveSide, 在平面的正面
        // PlaneQueryType::NegativeSide, 在平面的负面
        // PlaneQueryType::OnPlane, 在平面上
        [[nodiscard]] virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const;
        [[nodiscard]] virtual PlaneQueryType ToPlane(const Vector3D& testVector, int v0, int v1, int v2) const;

        // 返回:
        // TetrahedronQueryType::Outside, 四面体外
        // TetrahedronQueryType::Inside, 四面体内
        // TetrahedronQueryType::OnTetrahedron,在四面体上
        [[nodiscard]] virtual TetrahedronQueryType ToTetrahedron(int index, int v0, int v1, int v2, int v3) const;
        [[nodiscard]] virtual TetrahedronQueryType ToTetrahedron(const Vector3D& testVector, int v0, int v1, int v2, int v3) const;

        // 返回:
        // Returns:
        // CircumsphereQueryType::Outside, 在四面体的外切球外
        // CircumsphereQueryType::Inside,在四面体的外切球内
        // CircumsphereQueryType::OnCircumsphere, 在四面体的外切球上
        [[nodiscard]] virtual CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const;
        [[nodiscard]] virtual CircumsphereQueryType ToCircumsphere(const Vector3D& testVector, int v0, int v1, int v2, int v3) const;

    private:
        // 输入点
        VerticesType m_Vertices;
    };

    using FloatQuery3 = Query3<float>;
    using DoubleQuery3 = Query3<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_H
