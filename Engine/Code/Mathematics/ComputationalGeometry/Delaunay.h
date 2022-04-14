///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/07 15:52)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "Mathematics/Query/QueryBase.h"

namespace Mathematics
{
    template <typename Real>
    class Delaunay
    {
    public:
        using ClassType = Delaunay<Real>;
        using IndicesType = std::vector<int32_t>;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        virtual ~Delaunay() noexcept = default;
        Delaunay(const Delaunay& rhs) = default;
        Delaunay& operator=(const Delaunay& rhs) = default;
        Delaunay(Delaunay&& rhs) noexcept = default;
        Delaunay& operator=(Delaunay&& rhs) noexcept = default;

        NODISCARD QueryType GetQueryType() const noexcept;
        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD Real GetEpsilon() const noexcept;

        NODISCARD int GetDimension() const noexcept;

        NODISCARD int GetNumSimplices() const noexcept;
        NODISCARD IndicesType GetIndices() const;
        NODISCARD IndicesType GetAdjacencies() const;
        NODISCARD int32_t GetIndex(int index) const;
        NODISCARD int32_t GetAdjacency(int index) const;

    protected:
        Delaunay(int numVertices, Real epsilon, QueryType queryType);

        NODISCARD bool Load(CoreTools::ReadFileManager& inFile);
        NODISCARD bool Save(CoreTools::WriteFileManager& outFile) const;

        void SetDimension(int32_t newDimension) noexcept;
        void SetNumSimplices(int32_t newNumSimplices) noexcept;
        void AddIndex(int32_t index);
        void SetIndex(IndicesType indicesType);
        void SetAdjacencies(IndicesType indicesType);
        void AddAdjacency(int32_t index);

    private:
        QueryType queryType;
        int32_t numVertices;
        int32_t dimension;
        int32_t numSimplices;
        IndicesType indices;
        IndicesType adjacencies;
        Real epsilon;
    };

    using DelaunayF = Delaunay<float>;
    using DelaunayD = Delaunay<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY_H
