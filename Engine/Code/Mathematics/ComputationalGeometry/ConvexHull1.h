///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/05 15:31)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_H

#include "Mathematics/MathematicsDll.h"

#include "ConvexHull.h"

namespace Mathematics
{
    template <typename Real>
    class ConvexHull1 : public ConvexHull<Real>
    {
    public:
        using ClassType = ConvexHull1<Real>;
        using ParentType = ConvexHull<Real>;
        using Vertices = std::vector<Real>;
        using String = System::String;

    public:
        ConvexHull1(const Vertices& vertices, Real epsilon, QueryType queryType);
        explicit ConvexHull1(const String& filename);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vertices GetVertices() const;

        void LoadFile(const String& filename);
        void SaveFile(const String& filename) const;

    private:
        Vertices vertices;

        class SortedVertex
        {
        public:
            Real value;
            int32_t index;

            NODISCARD bool operator<(const SortedVertex& rhs) const noexcept
            {
                return value < rhs.value;
            }
        };
    };

    using ConvexHull1F = ConvexHull1<float>;
    using ConvexHull1D = ConvexHull1<double>;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_CONVEX_HULL1_H
