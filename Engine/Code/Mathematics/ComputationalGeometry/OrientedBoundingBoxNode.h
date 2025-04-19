/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 19:52)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_NODE_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_NODE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Primitives/OrientedBox.h"

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class OrientedBoundingBoxNode
    {
    public:
        using ClassType = OrientedBoundingBoxNode<Real>;

        using OrientedBox3 = Algebra::OrientedBox3<Real>;

    public:
        OrientedBoundingBoxNode() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD OrientedBox3 GetBox() const noexcept;
        NODISCARD int GetMinIndex() const noexcept;
        NODISCARD int GetMaxIndex() const noexcept;
        NODISCARD int GetLeftChild() const noexcept;
        NODISCARD int GetRightChild() const noexcept;

        void SetBox(const OrientedBox3& aBox) noexcept;
        void SetMinIndex(int aMinIndex) noexcept;
        void SetMaxIndex(int aMaxIndex) noexcept;
        void SetLeftChild(int aLeftChild) noexcept;
        void SetRightChild(int aRightChild) noexcept;

    private:
        OrientedBox3 box;
        int minIndex;
        int maxIndex;
        int leftChild;
        int rightChild;
    };
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_NODE_H
