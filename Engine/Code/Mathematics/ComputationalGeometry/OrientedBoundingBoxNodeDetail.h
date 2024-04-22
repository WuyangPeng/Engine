/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 19:52)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_NODE_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_NODE_DETAIL_H

#include "OrientedBoundingBoxNode.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::OrientedBoundingBoxNode<Real>::OrientedBoundingBoxNode() noexcept
    : box{},
      minIndex{ std::numeric_limits<int>::max() },
      maxIndex{ std::numeric_limits<int>::max() },
      leftChild{ std::numeric_limits<int>::max() },
      rightChild{ std::numeric_limits<int>::max() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::OrientedBoundingBoxNode<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBoundingBoxNode<Real>::OrientedBox3 Mathematics::OrientedBoundingBoxNode<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::OrientedBoundingBoxNode<Real>::GetMinIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::OrientedBoundingBoxNode<Real>::GetMaxIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::OrientedBoundingBoxNode<Real>::GetLeftChild() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return leftChild;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::OrientedBoundingBoxNode<Real>::GetRightChild() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rightChild;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxNode<Real>::SetBox(const OrientedBox3& aBox) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    box = aBox;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxNode<Real>::SetMinIndex(int aMinIndex) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    minIndex = aMinIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxNode<Real>::SetMaxIndex(int aMaxIndex) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    maxIndex = aMaxIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxNode<Real>::SetLeftChild(int aLeftChild) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    leftChild = aLeftChild;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxNode<Real>::SetRightChild(int aRightChild) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    rightChild = aRightChild;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_NODE_DETAIL_H
