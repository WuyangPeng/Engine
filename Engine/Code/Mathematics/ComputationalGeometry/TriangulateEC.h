///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:37)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Query/Query2.h"

#include <map>

namespace Mathematics
{
    template <typename Real>
    class TriangulateEC
    {
    public:
        using ClassType = TriangulateEC<Real>;
        using Vector2Type = Vector2<Real>;
        using Positions = std::vector<Vector2Type>;
        using Indices = std::vector<int>;
        using IndicesArray = std::vector<Indices>;
        using IndexMap = std::map<int, int>;

    public:
        TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, Indices& triangles);
        TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const Indices& polygon, Indices& triangles);
        TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const Indices& outer, const Indices& inner, Indices& triangles);
        TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const Indices& outer, const IndicesArray& inners, Indices& triangles);

        CLASS_INVARIANT_DECLARE;

        class Tree
        {
        public:
            using TreeSharedPtr = std::shared_ptr<Tree>;

        public:
            Indices polygon;
            std::vector<TreeSharedPtr> child;
        };

        using TreeSharedPtr = std::shared_ptr<Tree>;
        using ConstTreeSharedPtr = std::shared_ptr<const Tree>;

        TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const TreeSharedPtr& tree, Indices& triangles);

        static void Delete(TreeSharedPtr& root);

    private:
        void InitializePositions(const Positions& positions, QueryType queryType, Real epsilon, int extraElements);

        void InitializeVertices(int numVertices, const Indices& indices);

        void DoEarClipping(int numVertices, const Indices& indices, Indices& triangles);

        NODISCARD int TriangleQuery(const Vector2Type& position, QueryType queryType, Real epsilon, const std::array<Vector2Type, 3>& triangle) const;

        void CombinePolygons(QueryType queryType, Real epsilon, int nextElement, const Indices& outer, const Indices& inner, IndexMap& indexMap, Indices& combined);

        NODISCARD static int GetExtraElements(const TreeSharedPtr& tree);

        void ProcessOuterAndInners(QueryType queryType, Real epsilon, const Indices& outer, const IndicesArray& inners, int& nextElement, IndexMap& indexMap, Indices& combined);

        void RemapIndices(const IndexMap& indexMap, Indices& triangles) const;

        class Vertex
        {
        public:
            Vertex() noexcept;

            int index;
            bool isConvex;
            bool isEar;
            int vPrev;
            int vNext;
            int sPrev;
            int sNext;
            int ePrev;
            int eNext;
        };

        NODISCARD Vertex& Get(int i);
        NODISCARD bool IsConvex(int i);
        NODISCARD bool IsEar(int i);
        void InsertAfterC(int i);
        void InsertAfterR(int i);
        void InsertEndE(int i);
        void InsertAfterE(int i);
        void InsertBeforeE(int i);
        void RemoveV(int i);
        int RemoveE(int i);
        void RemoveR(int i);

    private:
        using Query2Type = Query2<Real>;
        using Query2SharedPtr = std::shared_ptr<Query2Type>;

    private:
        std::vector<Vertex> vertices;
        int cFirst;
        int cLast;
        int rFirst;
        int rLast;
        int eFirst;
        int eLast;

        Query2SharedPtr query;
        std::vector<Vector2Type> sPositions;
    };
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_H
