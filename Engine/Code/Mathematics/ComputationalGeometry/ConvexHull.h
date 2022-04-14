///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/05 14:31)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "Mathematics/Query/QueryBase.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class ConvexHull
    {
    public:
        using ClassType = ConvexHull<Real>;
        using IndicesType = std::vector<int32_t>;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        virtual ~ConvexHull() noexcept = default;
        ConvexHull(const ConvexHull& rhs) = default;
        ConvexHull& operator=(const ConvexHull& rhs) = default;
        ConvexHull(ConvexHull&& rhs) noexcept = default;
        ConvexHull& operator=(ConvexHull&& rhs) noexcept = default;

        NODISCARD QueryType GetQueryType() const noexcept;
        NODISCARD int32_t GetNumVertices() const noexcept;
        NODISCARD Real GetEpsilon() const noexcept;

        NODISCARD int32_t GetDimension() const noexcept;

        NODISCARD int32_t GetNumSimplices() const noexcept;
        NODISCARD IndicesType GetIndices() const;

    protected:
        ConvexHull(int numVertices, Real epsilon, QueryType queryType);

        NODISCARD bool Load(CoreTools::ReadFileManager& inFile);
        NODISCARD bool Save(CoreTools::WriteFileManager& outFile) const;

        void SetDimension(int32_t newDimension) noexcept;
        void SetNumSimplices(int32_t newNumSimplices) noexcept;
        void AddIndex(int32_t index);
        void SetIndex(IndicesType indicesType);

    private:
        QueryType queryType;
        int32_t numVertices;
        int32_t dimension;
        int32_t numSimplices;
        IndicesType indices;
        Real epsilon;
    };

    using ConvexHullF = ConvexHull<float>;
    using ConvexHullD = ConvexHull<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL_H
