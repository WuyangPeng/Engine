///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 16:37)

#ifndef MATHEMATICS_QUERY_QUERY3_H
#define MATHEMATICS_QUERY_QUERY3_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector3.h"

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
        using Vector3 = Vector3<Real>;
        using VerticesType = std::vector<Vector3>;

    public:
        // 基类处理浮点查询。
        explicit Query3(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        NODISCARD int GetNumVertices() const;
        NODISCARD const Vector3 GetVertice(int index) const;

        // 关于一个点的各种几何对象之间的关系查询。

        // 返回:
        // PlaneQueryType::PositiveSide, 在平面的正面
        // PlaneQueryType::NegativeSide, 在平面的负面
        // PlaneQueryType::OnPlane, 在平面上
        NODISCARD virtual PlaneQueryType ToPlane(int index, int v0, int v1, int v2) const;
        NODISCARD virtual PlaneQueryType ToPlane(const Vector3& testVector, int v0, int v1, int v2) const;

        // 返回:
        // TetrahedronQueryType::Outside, 四面体外
        // TetrahedronQueryType::Inside, 四面体内
        // TetrahedronQueryType::OnTetrahedron,在四面体上
        NODISCARD virtual TetrahedronQueryType ToTetrahedron(int index, int v0, int v1, int v2, int v3) const;
        NODISCARD virtual TetrahedronQueryType ToTetrahedron(const Vector3& testVector, int v0, int v1, int v2, int v3) const;

        // 返回:
        // Returns:
        // CircumsphereQueryType::Outside, 在四面体的外切球外
        // CircumsphereQueryType::Inside,在四面体的外切球内
        // CircumsphereQueryType::OnCircumsphere, 在四面体的外切球上
        NODISCARD virtual CircumsphereQueryType ToCircumsphere(int index, int v0, int v1, int v2, int v3) const;
        NODISCARD virtual CircumsphereQueryType ToCircumsphere(const Vector3& testVector, int v0, int v1, int v2, int v3) const;

    private:
        // 输入点
        VerticesType vertices;
    };

    using Query3F = Query3<float>;
    using Query3D = Query3<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY3_H
