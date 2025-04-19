///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:36)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H

#include "Bisect3Storage.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect3.h"
#include "Mathematics/NumericalAnalysis/Bisect3Root.h"

template <typename Real>
Mathematics::Bisect3Storage<Real>::Bisect3Storage(const Bisect3Type& bisect) noexcept
    : bisect{ bisect },
      beginPointX{},
      endPointX{},
      midpointX{},

      beginPointY{},
      endPointY{},
      midpointY{},

      beginPointZ{},
      endPointZ{},
      midpointZ{},

      beginXBeginYBeginZ0{},
      endXBeginYBeginZ0{},
      beginXEndYBeginZ0{},
      endXEndYBeginZ0{},
      beginXBeginYEndZ0{},
      endXBeginYEndZ0{},
      beginXEndYEndZ0{},
      endXEndYEndZ0{},
      beginXBeginYBeginZ1{},
      endXBeginYBeginZ1{},
      beginXEndYBeginZ1{},
      endXEndYBeginZ1{},
      beginXBeginYEndZ1{},
      endXBeginYEndZ1{},
      beginXEndYEndZ1{},
      endXEndYEndZ1{},
      beginXBeginYBeginZ2{},
      endXBeginYBeginZ2{},
      beginXEndYBeginZ2{},
      endXEndYBeginZ2{},
      beginXBeginYEndZ2{},
      endXBeginYEndZ2{},
      beginXEndYEndZ2{},
      endXEndYEndZ2{},
      beginXBeginYMidZ0{},
      endXBeginYMidZ0{},
      beginXEndYMidZ0{},
      endXEndYMidZ0{},
      beginXMidYBeginZ0{},
      endXMidYBeginZ0{},
      beginXMidYEndZ0{},
      endXMidYEndZ0{},
      midXBeginYBeginZ0{},
      midXEndYBeginZ0{},
      midXBeginYEndZ0{},
      midXEndYEndZ0{},
      beginXBeginYMidZ1{},
      endXBeginYMidZ1{},
      beginXEndYMidZ1{},
      endXEndYMidZ1{},
      beginXMidYBeginZ1{},
      endXMidYBeginZ1{},
      beginXMidYEndZ1{},
      endXMidYEndZ1{},
      midXBeginYBeginZ1{},
      midXEndYBeginZ1{},
      midXBeginYEndZ1{},
      midXEndYEndZ1{},
      beginXBeginYMidZ2{},
      endXBeginYMidZ2{},
      beginXEndYMidZ2{},
      endXEndYMidZ2{},
      beginXMidYBeginZ2{},
      endXMidYBeginZ2{},
      beginXMidYEndZ2{},
      endXMidYEndZ2{},
      midXBeginYBeginZ2{},
      midXEndYBeginZ2{},
      midXBeginYEndZ2{},
      midXEndYEndZ2{},
      beginXMidYMidZ0{},
      midXBeginYMidZ0{},
      midXMidYBeginZ0{},
      endXMidYMidZ0{},
      midXEndYMidZ0{},
      midXMidYEndZ0{},
      beginXMidYMidZ1{},
      midXBeginYMidZ1{},
      midXMidYBeginZ1{},
      endXMidYMidZ1{},
      midXEndYMidZ1{},
      midXMidYEndZ1{},
      beginXMidYMidZ2{},
      midXBeginYMidZ2{},
      midXMidYBeginZ2{},
      endXMidYMidZ2{},
      midXEndYMidZ2{},
      midXMidYEndZ2{},
      midXMidYMidZ0{},
      midXMidYMidZ1{},
      midXMidYMidZ2{},

      bisect3Root{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect3Storage<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect3Storage<Real>::TestEightCornerValues(Real beginX,
                                                              Real beginY,
                                                              Real beginZ,
                                                              Real endX,
                                                              Real endY,
                                                              Real endZ)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (ZeroTest(beginX, beginY, beginZ, Bisect3StorageType::BeginXBeginYBeginZ) ||
        ZeroTest(endX, beginY, beginZ, Bisect3StorageType::EndXBeginYBeginZ) ||
        ZeroTest(beginX, endY, beginZ, Bisect3StorageType::BeginXEndYBeginZ) ||
        ZeroTest(endX, endY, beginZ, Bisect3StorageType::EndXEndYBeginZ) ||
        ZeroTest(beginX, beginY, endZ, Bisect3StorageType::BeginXBeginYEndZ) ||
        ZeroTest(endX, beginY, endZ, Bisect3StorageType::EndXBeginYEndZ) ||
        ZeroTest(beginX, endY, endZ, Bisect3StorageType::BeginXEndYEndZ) ||
        ZeroTest(endX, endY, endZ, Bisect3StorageType::EndXEndYEndZ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
bool Mathematics::Bisect3Storage<Real>::TestEdgeValues()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (ZeroTest(beginPointX, beginPointY, midpointZ, Bisect3StorageType::BeginXBeginYMidZ) ||
        ZeroTest(endPointX, beginPointY, midpointZ, Bisect3StorageType::EndXBeginYMidZ) ||
        ZeroTest(beginPointX, endPointY, midpointZ, Bisect3StorageType::BeginXEndYMidZ) ||
        ZeroTest(endPointX, endPointY, midpointZ, Bisect3StorageType::EndXEndYMidZ) ||
        ZeroTest(beginPointX, midpointY, beginPointZ, Bisect3StorageType::BeginXMidYBeginZ) ||
        ZeroTest(endPointX, midpointY, beginPointZ, Bisect3StorageType::EndXMidYBeginZ) ||
        ZeroTest(beginPointX, midpointY, endPointZ, Bisect3StorageType::BeginXMidYEndZ) ||
        ZeroTest(endPointX, midpointY, endPointZ, Bisect3StorageType::EndXMidYEndZ) ||
        ZeroTest(midpointX, beginPointY, beginPointZ, Bisect3StorageType::MidXBeginYBeginZ) ||
        ZeroTest(midpointX, endPointY, beginPointZ, Bisect3StorageType::MidXEndYBeginZ) ||
        ZeroTest(midpointX, beginPointY, endPointZ, Bisect3StorageType::MidXBeginYEndZ) ||
        ZeroTest(midpointX, endPointY, endPointZ, Bisect3StorageType::MidXEndYEndZ) ||
        ZeroTest(beginPointX, midpointY, midpointZ, Bisect3StorageType::BeginXMidYMidZ) ||
        ZeroTest(midpointX, beginPointY, midpointZ, Bisect3StorageType::MidXBeginYMidZ) ||
        ZeroTest(midpointX, midpointY, beginPointZ, Bisect3StorageType::MidXMidYBeginZ) ||
        ZeroTest(endPointX, midpointY, midpointZ, Bisect3StorageType::EndXMidYMidZ) ||
        ZeroTest(midpointX, endPointY, midpointZ, Bisect3StorageType::MidXEndYMidZ) ||
        ZeroTest(midpointX, midpointY, endPointZ, Bisect3StorageType::MidXMidYEndZ) ||
        ZeroTest(midpointX, midpointY, midpointZ, Bisect3StorageType::MidXMidYMidZ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
typename Mathematics::Bisect3Storage<Real>::Bisect3RootSharedPtr Mathematics::Bisect3Storage<Real>::GetBisect3Root() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bisect3Root;
}

template <typename Real>
bool Mathematics::Bisect3Storage<Real>::ZeroTest(Real x, Real y, Real z, Bisect3StorageType type)
{
    auto value0 = bisect.GetFunction0Value(x, y, z);
    auto value1 = bisect.GetFunction1Value(x, y, z);
    auto value2 = bisect.GetFunction2Value(x, y, z);

    SetStorageValue(value0, value1, value2, type);

    if (MathType::FAbs(value0) <= bisect.GetTolerance() && MathType::FAbs(value1) <= bisect.GetTolerance() && MathType::FAbs(value2) <= bisect.GetTolerance())
    {
        bisect3Root = std::make_shared<Bisect3RootType>(x, y, z, BisectRootType::HaveSolution);

        return true;
    }

    return false;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginPointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginPointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginPointZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginPointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endPointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endPointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndPointZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endPointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidpointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midpointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidpointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midpointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidpointZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midpointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXBeginYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXBeginYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXEndYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXEndYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return beginXMidYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXBeginYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return endXMidYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXEndYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return midXMidYMidZ2;
}

template <typename Real>
void Mathematics::Bisect3Storage<Real>::SetStorageValue(Real value0, Real value1, Real value2, Bisect3StorageType type) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (type)
    {
        case Bisect3StorageType::BeginXBeginYBeginZ:
        {
            beginXBeginYBeginZ0 = value0;
            beginXBeginYBeginZ1 = value1;
            beginXBeginYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXBeginYBeginZ:
        {
            endXBeginYBeginZ0 = value0;
            endXBeginYBeginZ1 = value1;
            endXBeginYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXEndYBeginZ:
        {
            beginXEndYBeginZ0 = value0;
            beginXEndYBeginZ1 = value1;
            beginXEndYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXEndYBeginZ:
        {
            endXEndYBeginZ0 = value0;
            endXEndYBeginZ1 = value1;
            endXEndYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXBeginYEndZ:
        {
            beginXBeginYEndZ0 = value0;
            beginXBeginYEndZ1 = value1;
            beginXBeginYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXBeginYEndZ:
        {
            endXBeginYEndZ0 = value0;
            endXBeginYEndZ1 = value1;
            endXBeginYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXEndYEndZ:
        {
            beginXEndYEndZ0 = value0;
            beginXEndYEndZ1 = value1;
            beginXEndYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXEndYEndZ:
        {
            endXEndYEndZ0 = value0;
            endXEndYEndZ1 = value1;
            endXEndYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXBeginYMidZ:
        {
            beginXBeginYMidZ0 = value0;
            beginXBeginYMidZ1 = value1;
            beginXBeginYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXBeginYMidZ:
        {
            endXBeginYMidZ0 = value0;
            endXBeginYMidZ1 = value1;
            endXBeginYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXEndYMidZ:
        {
            beginXEndYMidZ0 = value0;
            beginXEndYMidZ1 = value1;
            beginXEndYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXEndYMidZ:
        {
            endXEndYMidZ0 = value0;
            endXEndYMidZ1 = value1;
            endXEndYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXMidYBeginZ:
        {
            beginXMidYBeginZ0 = value0;
            beginXMidYBeginZ1 = value1;
            beginXMidYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXMidYBeginZ:
        {
            endXMidYBeginZ0 = value0;
            endXMidYBeginZ1 = value1;
            endXMidYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXMidYEndZ:
        {
            beginXMidYEndZ0 = value0;
            beginXMidYEndZ1 = value1;
            beginXMidYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXMidYEndZ:
        {
            endXMidYEndZ0 = value0;
            endXMidYEndZ1 = value1;
            endXMidYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXBeginYBeginZ:
        {
            midXBeginYBeginZ0 = value0;
            midXBeginYBeginZ1 = value1;
            midXBeginYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXEndYBeginZ:
        {
            midXEndYBeginZ0 = value0;
            midXEndYBeginZ1 = value1;
            midXEndYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXBeginYEndZ:
        {
            midXBeginYEndZ0 = value0;
            midXBeginYEndZ1 = value1;
            midXBeginYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXEndYEndZ:
        {
            midXEndYEndZ0 = value0;
            midXEndYEndZ1 = value1;
            midXEndYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXMidYMidZ:
        {
            beginXMidYMidZ0 = value0;
            beginXMidYMidZ1 = value1;
            beginXMidYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXBeginYMidZ:
        {
            midXBeginYMidZ0 = value0;
            midXBeginYMidZ1 = value1;
            midXBeginYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXMidYBeginZ:
        {
            midXMidYBeginZ0 = value0;
            midXMidYBeginZ1 = value1;
            midXMidYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXMidYMidZ:
        {
            endXMidYMidZ0 = value0;
            endXMidYMidZ1 = value1;
            endXMidYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXEndYMidZ:
        {
            midXEndYMidZ0 = value0;
            midXEndYMidZ1 = value1;
            midXEndYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXMidYEndZ:
        {
            midXMidYEndZ0 = value0;
            midXMidYEndZ1 = value1;
            midXMidYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXMidYMidZ:
        {
            midXMidYMidZ0 = value0;
            midXMidYMidZ1 = value1;
            midXMidYMidZ2 = value2;
            break;
        }

        default:
            break;
    }
}

template <typename Real>
void Mathematics::Bisect3Storage<Real>::SetStorageValue(const Bisect3NodeSharedPtr& node) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (node == nullptr)
    {
        return;
    }

    const auto endNode = node->GetXNext()->GetYNext()->GetZNext();

    if (endNode == nullptr)
    {
        return;
    }

    beginPointX = node->GetX();
    beginPointY = node->GetY();
    beginPointZ = node->GetZ();
    endPointX = endNode->GetX();
    endPointY = endNode->GetY();
    endPointZ = endNode->GetZ();
    midpointX = (MathType::GetRational(1, 2) * (beginPointX + endPointX));
    midpointY = (MathType::GetRational(1, 2) * (beginPointY + endPointY));
    midpointZ = (MathType::GetRational(1, 2) * (beginPointZ + endPointZ));
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H
