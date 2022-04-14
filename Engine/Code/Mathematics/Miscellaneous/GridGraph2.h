///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 18:16)

#ifndef MATHEMATICS_MISCELLANEOUS_GRID_GRAPH2_H
#define MATHEMATICS_MISCELLANEOUS_GRID_GRAPH2_H

#include "Mathematics/MathematicsDll.h"

#include <array>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class GridGraph2
    {
    public:
        using ClassType = GridGraph2<Real>;
        using RelaxationCallbackFunction = void (*)();

    public:
        GridGraph2(int xSize, int ySize);
        virtual ~GridGraph2() noexcept = default;
        GridGraph2(const GridGraph2& rhs) = default;
        GridGraph2& operator=(const GridGraph2& rhs) = default;
        GridGraph2(GridGraph2&& rhs) noexcept = default;
        GridGraph2& operator=(GridGraph2&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD int GetXSize() const noexcept;
        NODISCARD int GetYSize() const noexcept;
        NODISCARD int GetVertexQuantity() const noexcept;

        void SetWeight(int x, int y, int dx, int dy, Real weight);
        NODISCARD Real GetWeight(int x, int y, int dx, int dy) const;

        void ComputeMinimumWeightPath(int x0, int y0, int x1, int y1);

        NODISCARD int GetPathQuantity() const noexcept;
        void GetPathPoint(int i, int& x, int& y) const;

        NODISCARD int GetNumProcessed() const noexcept;

    protected:
        class Vertex
        {
        public:
            Vertex() noexcept;

            void SetWeight(int dx, int dy, Real newWeight);
            NODISCARD Real GetWeight(int dx, int dy) const;

            NODISCARD Real GetEstimate() const noexcept;
            void SetEstimate(Real val) noexcept;

            NODISCARD int GetPredecessor() const noexcept;
            void SetPredecessor(int val) noexcept;

        private:
            Real estimate;
            int predecessor;

            std::array<Real, 8> weight;
        };

        NODISCARD int GetIndex(int x, int y) const noexcept;
        NODISCARD int GetX(int newIndex) const noexcept;
        NODISCARD int GetY(int newIndex) const noexcept;

    private:
        RelaxationCallbackFunction relaxationCallback;

        int xSize;
        int ySize;
        int numVertices;
        std::vector<Vertex> vertices;

        int pathQuantity;
        std::vector<int> path;
        std::vector<int> pending;
        int numProcessed;

        static const std::array<std::array<int, 3>, 3> index;
    };
}

#endif  // MATHEMATICS_MISCELLANEOUS_GRID_GRAPH2_H
