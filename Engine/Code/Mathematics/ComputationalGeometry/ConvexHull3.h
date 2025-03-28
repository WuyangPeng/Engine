///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:36)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_H

#include "Mathematics/MathematicsDll.h"

#include "ConvexHull1.h"
#include "ConvexHull2.h"
#include "Mathematics/Query/Query3.h"

#include <set>

namespace Mathematics
{
    template <typename Real>
    class ConvexHull3 : public ConvexHull<Real>
    {
    public:
        using ClassType = ConvexHull3<Real>;
        using ParentType = ConvexHull<Real>;
        using Vector3Type = Vector3<Real>;
        using Vertices = std::vector<Vector3Type>;
        using ConvexHull1Type = ConvexHull1<Real>;
        using ConvexHull2Type = ConvexHull2<Real>;
        using String = System::String;
        using IndicesType = ParentType::IndicesType;
        using MathType = Math<Real>;

    public:
        ConvexHull3(const Vertices& vertices, Real epsilon, QueryType queryType);
        explicit ConvexHull3(const String& filename);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3Type GetLineOrigin() const noexcept;
        NODISCARD Vector3Type GetLineDirection() const noexcept;
        NODISCARD ConvexHull1Type GetConvexHull1() const;

        NODISCARD Vector3Type GetPlaneOrigin() const noexcept;
        NODISCARD Vector3Type GetPlaneDirection(int i) const;
        NODISCARD ConvexHull2Type GetConvexHull2() const;

        void LoadFile(const String& filename);
        void SaveFile(const String& filename) const;

    private:
        class Triangle;

        using Query3 = Query3<Real>;
        using Query3SharedPtr = std::shared_ptr<Query3>;
        using TriangleSharedPtr = std::shared_ptr<Triangle>;
        using TriangleWeakPtr = std::weak_ptr<Triangle>;

    private:
        class Triangle : private std::enable_shared_from_this<Triangle>
        {
        public:
            Triangle(int32_t v0, int32_t v1, int32_t v2);

            NODISCARD PlaneQueryType GetSign(int32_t i, const Query3& query);
            void AttachTo(const TriangleSharedPtr& adj0, const TriangleSharedPtr& adj1, const TriangleSharedPtr& adj2);
            NODISCARD int32_t DetachFrom(int32_t adjIndex, const TriangleSharedPtr& adj);

            std::array<int32_t, 3> v;
            std::array<TriangleWeakPtr, 3> triangle;
            PlaneQueryType sign;
            int time;
            bool onStack;
        };

        NODISCARD bool Update(int32_t i);
        void ExtractIndices();
        void DeleteHull() noexcept;
        void Init();

    private:
        Vertices vertices;

        Vertices sVertices;
        Query3SharedPtr query;

        Vector3Type lineOrigin;
        Vector3Type lineDirection;

        Vector3Type planeOrigin;
        std::array<Vector3Type, 2> planeDirection;

        std::set<TriangleSharedPtr> hull;

        class TerminatorData
        {
        public:
            TerminatorData() noexcept;
            TerminatorData(int32_t v0, int32_t v1, int32_t nullIndex, const TriangleWeakPtr& tri) noexcept;

            std::array<int32_t, 2> v;
            int32_t nullIndex;
            TriangleWeakPtr t;
        };
    };

    using ConvexHull3F = ConvexHull3<float>;
    using ConvexHull3D = ConvexHull3<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL3_H
