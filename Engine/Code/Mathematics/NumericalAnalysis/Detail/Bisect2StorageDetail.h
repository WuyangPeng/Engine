///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:33)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H

#include "Bisect2Node.h"
#include "Bisect2Storage.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect2.h"

template <typename Real>
Mathematics::Bisect2Storage<Real>::Bisect2Storage(const Bisect2& bisect) noexcept
    : bisect{ bisect },
      beginPointX{},
      beginPointY{},
      endPointX{},
      endPointY{},
      midpointX{},
      midpointY{},
      beginXAndBeginY0{},
      endXAndBeginY0{},
      beginXAndEndY0{},
      endXAndEndY0{},
      beginXAndMidY0{},
      endXAndMidY0{},
      midXAndBeginY0{},
      midXAndEndY0{},
      midXAndMidY0{},
      beginXAndBeginY1{},
      endXAndBeginY1{},
      beginXAndEndY1{},
      endXAndEndY1{},
      beginXAndMidY1{},
      endXAndMidY1{},
      midXAndBeginY1{},
      midXAndEndY1{},
      midXAndMidY1{},
      bisect2Root{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect2Storage<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect2Storage<Real>::TestFourCornerValues(Real beginX, Real beginY, Real endX, Real endY)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (ZeroTest(beginX, beginY, Bisect2StorageType::BeginXAndBeginY) ||
        ZeroTest(endX, beginY, Bisect2StorageType::EndXAndBeginY) ||
        ZeroTest(beginX, endY, Bisect2StorageType::BeginXAndEndY) ||
        ZeroTest(endX, endY, Bisect2StorageType::EndXAndEndY))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
bool Mathematics::Bisect2Storage<Real>::ZeroTest(Real x, Real y, Bisect2StorageType type)
{
    const auto value0 = bisect.GetFunction0Value(x, y);
    const auto value1 = bisect.GetFunction1Value(x, y);

    SetStorageValue(value0, value1, type);

    if (Math::FAbs(value0) <= bisect.GetTolerance() && Math::FAbs(value1) <= bisect.GetTolerance())
    {
        bisect2Root = std::make_shared<Bisect2Root>(x, y, BisectRootType::HaveSolution);

        return true;
    }

    return false;
}

template <typename Real>
typename Mathematics::Bisect2Storage<Real>::Bisect2RootSharedPtr Mathematics::Bisect2Storage<Real>::GetBisect2Root() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bisect2Root;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginPointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginPointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endPointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endPointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidpointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midpointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidpointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midpointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndBeginYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXAndBeginY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndBeginYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXAndBeginY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndEndYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXAndEndY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndEndYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXAndEndY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndMidYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXAndMidY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndMidYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXAndMidY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndBeginYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXAndBeginY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndEndYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXAndEndY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndMidYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXAndMidY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndBeginYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXAndBeginY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndBeginYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXAndBeginY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndEndYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXAndEndY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndEndYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXAndEndY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndMidYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXAndMidY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndMidYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXAndMidY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndBeginYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXAndBeginY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndEndYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXAndEndY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndMidYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXAndMidY1;
}

template <typename Real>
void Mathematics::Bisect2Storage<Real>::SetStorageValue(Real value0, Real value1, Bisect2StorageType type) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (type)
    {
        case Bisect2StorageType::BeginXAndBeginY:
            beginXAndBeginY0 = value0;
            beginXAndBeginY1 = value1;
            break;

        case Bisect2StorageType::EndXAndBeginY:
            endXAndBeginY0 = value0;
            endXAndBeginY1 = value1;
            break;

        case Bisect2StorageType::BeginXAndEndY:
            beginXAndEndY0 = value0;
            beginXAndEndY1 = value1;
            break;

        case Bisect2StorageType::EndXAndEndY:
            endXAndEndY0 = value0;
            endXAndEndY1 = value1;
            break;

        case Bisect2StorageType::BeginXAndMidY:
            beginXAndMidY0 = value0;
            beginXAndMidY1 = value1;
            break;

        case Bisect2StorageType::EndXAndMidY:
            endXAndMidY0 = value0;
            endXAndMidY1 = value1;
            break;

        case Bisect2StorageType::MidXAndBeginY:
            midXAndBeginY0 = value0;
            midXAndBeginY1 = value1;
            break;

        case Bisect2StorageType::MidXAndEndY:
            midXAndEndY0 = value0;
            midXAndEndY1 = value1;
            break;

        case Bisect2StorageType::MidXAndMidY:
            midXAndMidY0 = value0;
            midXAndMidY1 = value1;
            break;

        default:
            break;
    }
}

template <typename Real>
void Mathematics::Bisect2Storage<Real>::SetStorageValue(const Bisect2NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (node == nullptr)
    {
        return;
    }

    auto xNext = node->GetXNext();
    auto yNext = node->GetYNext();

    // 二等分四边形。
    if (xNext != nullptr)
    {
        endPointX = xNext->GetX();
        beginPointX = yNext->GetX();
        midpointX = Math::GetRational(1, 2) * (beginPointX + endPointX);
    }

    if (yNext != nullptr)
    {
        beginPointY = xNext->GetY();
        endPointY = yNext->GetY();
        midpointY = Math::GetRational(1, 2) * (beginPointY + endPointY);
    }
}

template <typename Real>
bool Mathematics::Bisect2Storage<Real>::TestEdgeValues()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (ZeroTest(endPointX, midpointY, Bisect2StorageType::EndXAndMidY) ||
        ZeroTest(midpointX, endPointY, Bisect2StorageType::MidXAndEndY) ||
        ZeroTest(midpointX, beginPointY, Bisect2StorageType::MidXAndBeginY) ||
        ZeroTest(beginPointX, midpointY, Bisect2StorageType::BeginXAndMidY) ||
        ZeroTest(midpointX, midpointY, Bisect2StorageType::MidXAndMidY))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H
