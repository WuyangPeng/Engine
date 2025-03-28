///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:36)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_H

#include "Mathematics/MathematicsDll.h"

#include "ConvexHull.h"
#include "Mathematics/ComputationalGeometry/ComputationalGeometryFwd.h"
#include "Mathematics/Query/Query2.h"

#include <array>
#include <memory>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class ConvexHull2 : public ConvexHull<Real>
    {
    public:
        using ClassType = ConvexHull2<Real>;
        using ParentType = ConvexHull<Real>;
        using Vector2Type = Vector2<Real>;
        using Vertices = std::vector<Vector2Type>;
        using ConvexHull1Type = ConvexHull1<Real>;
        using String = System::String;
        using IndicesType = typename ParentType::IndicesType;
        using MathType = Math<Real>;

    public:
        ConvexHull2(const Vertices& vertices, Real epsilon, QueryType queryType);
        explicit ConvexHull2(const String& filename);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector2Type GetLineOrigin() const noexcept;
        NODISCARD Vector2Type GetLineDirection() const noexcept;
        NODISCARD ConvexHull1Type GetConvexHull1() const;

        void LoadFile(const String& filename);
        void SaveFile(const String& filename) const;

    private:
        class Edge;

        using Query2 = Query2<Real>;
        using Query2SharedPtr = std::shared_ptr<Query2>;
        using EdgeSharedPtr = std::shared_ptr<Edge>;
        using EdgeWeakPtr = std::weak_ptr<Edge>;

    private:
        class Edge : private std::enable_shared_from_this<Edge>
        {
        public:
            Edge(int32_t v0, int32_t v1);

            NODISCARD LineQueryType GetSign(int32_t i, const Query2& query);
            void Insert(const EdgeSharedPtr& adj0, const EdgeSharedPtr& adj1);
            void DeleteSelf();
            void DeleteAll();
            NODISCARD IndicesType GetIndices();

            std::array<int32_t, 2> v;
            std::array<EdgeWeakPtr, 2> e;
            LineQueryType sign;
            int time;
        };

    private:
        using Result = std::pair<EdgeSharedPtr, bool>;

        NODISCARD Result Update(int i, const EdgeSharedPtr& edge);
        void Init();

    private:
        Vertices vertices;

        Vertices sVertices;
        Query2SharedPtr query;

        Vector2Type lineOrigin;
        Vector2Type lineDirection;
    };

    using ConvexHull2F = ConvexHull2<float>;
    using ConvexHull2D = ConvexHull2<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL2_H
