///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

#ifndef MATHEMATICS_MESHES_UNIQUE_VERTICES_TRIANGLES_H
#define MATHEMATICS_MESHES_UNIQUE_VERTICES_TRIANGLES_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/Tuple.h"

#include <vector>

namespace Mathematics
{
    template <int N, typename Real>
    class UniqueVerticesTriangles
    {
    public:
        using ClassType = UniqueVerticesTriangles<N, Real>;

    public:
        UniqueVerticesTriangles(int numTriangles, const std::vector<CoreTools::Tuple<N, Real>>& inVertices);
        UniqueVerticesTriangles(int numInVertices, const std::vector<CoreTools::Tuple<N, Real>>& inVertices, int numTriangles, const std::vector<int>& inIndices);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetOutputIndexFor(int inputIndex) const;
        NODISCARD std::vector<CoreTools::Tuple<N, Real>> GetOutVertices() const;
        NODISCARD std::vector<int> GetOutIndices() const;

    private:
        void ConstructUniqueVertices(const std::vector<CoreTools::Tuple<N, Real>>& inVertices);

    private:
        int numInVertices;
        int numOutVertices;
        std::vector<int> inToOutMapping;

        std::vector<CoreTools::Tuple<N, Real>> outVertices;
        std::vector<int> outIndices;
    };
}

#endif  // MATHEMATICS_MESHES_UNIQUE_VERTICES_TRIANGLES_H
