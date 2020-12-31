///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/20 16:11)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H

#include "Bisect3Storage.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect3.h"
#include "Mathematics/NumericalAnalysis/Bisect3Root.h"

template <typename Real>
Mathematics::Bisect3Storage<Real>::Bisect3Storage(const Bisect3& bisect) noexcept
    : m_Bisect{ bisect },
      m_BeginPointX{}, m_EndPointX{}, m_MidpointX{},
      m_BeginPointY{}, m_EndPointY{}, m_MidpointY{},
      m_BeginPointZ{}, m_EndPointZ{}, m_MidpointZ{},
      m_BeginXBeginYBeginZ0{}, m_EndXBeginYBeginZ0{}, m_BeginXEndYBeginZ0{}, m_EndXEndYBeginZ0{},
      m_BeginXBeginYEndZ0{}, m_EndXBeginYEndZ0{}, m_BeginXEndYEndZ0{}, m_EndXEndYEndZ0{},
      m_BeginXBeginYBeginZ1{}, m_EndXBeginYBeginZ1{}, m_BeginXEndYBeginZ1{}, m_EndXEndYBeginZ1{},
      m_BeginXBeginYEndZ1{}, m_EndXBeginYEndZ1{}, m_BeginXEndYEndZ1{}, m_EndXEndYEndZ1{},
      m_BeginXBeginYBeginZ2{}, m_EndXBeginYBeginZ2{}, m_BeginXEndYBeginZ2{}, m_EndXEndYBeginZ2{},
      m_BeginXBeginYEndZ2{}, m_EndXBeginYEndZ2{}, m_BeginXEndYEndZ2{}, m_EndXEndYEndZ2{},
      m_BeginXBeginYMidZ0{}, m_EndXBeginYMidZ0{}, m_BeginXEndYMidZ0{}, m_EndXEndYMidZ0{},
      m_BeginXMidYBeginZ0{}, m_EndXMidYBeginZ0{}, m_BeginXMidYEndZ0{}, m_EndXMidYEndZ0{},
      m_MidXBeginYBeginZ0{}, m_MidXEndYBeginZ0{}, m_MidXBeginYEndZ0{}, m_MidXEndYEndZ0{},
      m_BeginXBeginYMidZ1{}, m_EndXBeginYMidZ1{}, m_BeginXEndYMidZ1{}, m_EndXEndYMidZ1{},
      m_BeginXMidYBeginZ1{}, m_EndXMidYBeginZ1{}, m_BeginXMidYEndZ1{}, m_EndXMidYEndZ1{},
      m_MidXBeginYBeginZ1{}, m_MidXEndYBeginZ1{}, m_MidXBeginYEndZ1{}, m_MidXEndYEndZ1{},
      m_BeginXBeginYMidZ2{}, m_EndXBeginYMidZ2{}, m_BeginXEndYMidZ2{}, m_EndXEndYMidZ2{},
      m_BeginXMidYBeginZ2{}, m_EndXMidYBeginZ2{}, m_BeginXMidYEndZ2{}, m_EndXMidYEndZ2{},
      m_MidXBeginYBeginZ2{}, m_MidXEndYBeginZ2{}, m_MidXBeginYEndZ2{}, m_MidXEndYEndZ2{},
      m_BeginXMidYMidZ0{}, m_MidXBeginYMidZ0{}, m_MidXMidYBeginZ0{},
      m_EndXMidYMidZ0{}, m_MidXEndYMidZ0{}, m_MidXMidYEndZ0{},
      m_BeginXMidYMidZ1{}, m_MidXBeginYMidZ1{}, m_MidXMidYBeginZ1{},
      m_EndXMidYMidZ1{}, m_MidXEndYMidZ1{}, m_MidXMidYEndZ1{},
      m_BeginXMidYMidZ2{}, m_MidXBeginYMidZ2{}, m_MidXMidYBeginZ2{},
      m_EndXMidYMidZ2{}, m_MidXEndYMidZ2{}, m_MidXMidYEndZ2{},
      m_MidXMidYMidZ0{}, m_MidXMidYMidZ1{}, m_MidXMidYMidZ2{},
      m_Bisect3Root{}
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
bool Mathematics::Bisect3Storage<Real>::TestEightCornerValues(Real beginPointX, Real beginPointY, Real beginPointZ,
                                                              Real endPointX, Real endPointY, Real endPointZ)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (ZeroTest(beginPointX, beginPointY, beginPointZ, Bisect3StorageType::BeginXBeginYBeginZ) ||
        ZeroTest(endPointX, beginPointY, beginPointZ, Bisect3StorageType::EndXBeginYBeginZ) ||
        ZeroTest(beginPointX, endPointY, beginPointZ, Bisect3StorageType::BeginXEndYBeginZ) ||
        ZeroTest(endPointX, endPointY, beginPointZ, Bisect3StorageType::EndXEndYBeginZ) ||
        ZeroTest(beginPointX, beginPointY, endPointZ, Bisect3StorageType::BeginXBeginYEndZ) ||
        ZeroTest(endPointX, beginPointY, endPointZ, Bisect3StorageType::EndXBeginYEndZ) ||
        ZeroTest(beginPointX, endPointY, endPointZ, Bisect3StorageType::BeginXEndYEndZ) ||
        ZeroTest(endPointX, endPointY, endPointZ, Bisect3StorageType::EndXEndYEndZ))
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

    if (ZeroTest(m_BeginPointX, m_BeginPointY, m_MidpointZ, Bisect3StorageType::BeginXBeginYMidZ) ||
        ZeroTest(m_EndPointX, m_BeginPointY, m_MidpointZ, Bisect3StorageType::EndXBeginYMidZ) ||
        ZeroTest(m_BeginPointX, m_EndPointY, m_MidpointZ, Bisect3StorageType::BeginXEndYMidZ) ||
        ZeroTest(m_EndPointX, m_EndPointY, m_MidpointZ, Bisect3StorageType::EndXEndYMidZ) ||
        ZeroTest(m_BeginPointX, m_MidpointY, m_BeginPointZ, Bisect3StorageType::BeginXMidYBeginZ) ||
        ZeroTest(m_EndPointX, m_MidpointY, m_BeginPointZ, Bisect3StorageType::EndXMidYBeginZ) ||
        ZeroTest(m_BeginPointX, m_MidpointY, m_EndPointZ, Bisect3StorageType::BeginXMidYEndZ) ||
        ZeroTest(m_EndPointX, m_MidpointY, m_EndPointZ, Bisect3StorageType::EndXMidYEndZ) ||
        ZeroTest(m_MidpointX, m_BeginPointY, m_BeginPointZ, Bisect3StorageType::MidXBeginYBeginZ) ||
        ZeroTest(m_MidpointX, m_EndPointY, m_BeginPointZ, Bisect3StorageType::MidXEndYBeginZ) ||
        ZeroTest(m_MidpointX, m_BeginPointY, m_EndPointZ, Bisect3StorageType::MidXBeginYEndZ) ||
        ZeroTest(m_MidpointX, m_EndPointY, m_EndPointZ, Bisect3StorageType::MidXEndYEndZ) ||
        ZeroTest(m_BeginPointX, m_MidpointY, m_MidpointZ, Bisect3StorageType::BeginXMidYMidZ) ||
        ZeroTest(m_MidpointX, m_BeginPointY, m_MidpointZ, Bisect3StorageType::MidXBeginYMidZ) ||
        ZeroTest(m_MidpointX, m_MidpointY, m_BeginPointZ, Bisect3StorageType::MidXMidYBeginZ) ||
        ZeroTest(m_EndPointX, m_MidpointY, m_MidpointZ, Bisect3StorageType::EndXMidYMidZ) ||
        ZeroTest(m_MidpointX, m_EndPointY, m_MidpointZ, Bisect3StorageType::MidXEndYMidZ) ||
        ZeroTest(m_MidpointX, m_MidpointY, m_EndPointZ, Bisect3StorageType::MidXMidYEndZ) ||
        ZeroTest(m_MidpointX, m_MidpointY, m_MidpointZ, Bisect3StorageType::MidXMidYMidZ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename Real>
typename const Mathematics::Bisect3Storage<Real>::Bisect3RootSharedPtr Mathematics::Bisect3Storage<Real>::GetBisect3Root() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Bisect3Root;
}

template <typename Real>
bool Mathematics::Bisect3Storage<Real>::ZeroTest(Real x, Real y, Real z, Bisect3StorageType type)
{
    auto value0 = m_Bisect.GetFunction0Value(x, y, z);
    auto value1 = m_Bisect.GetFunction1Value(x, y, z);
    auto value2 = m_Bisect.GetFunction2Value(x, y, z);

    SetStorageValue(value0, value1, value2, type);

    if (Math::FAbs(value0) <= m_Bisect.GetTolerance() && Math::FAbs(value1) <= m_Bisect.GetTolerance() && Math::FAbs(value2) <= m_Bisect.GetTolerance())
    {
        m_Bisect3Root = std::make_shared<Bisect3Root>(x, y, z, BisectRootType::HaveSolution);

        return true;
    }

    return false;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginPointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginPointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginPointZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginPointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndPointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndPointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndPointZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndPointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidpointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidpointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidpointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidpointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidpointZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidpointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXBeginYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXBeginYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXBeginYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXBeginYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXEndYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXEndYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXEndYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXEndYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYBeginZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYBeginZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYEndZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYEndZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYBeginZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYBeginZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYEndZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYEndZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetBeginXMidYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXMidYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXBeginYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXBeginYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYBeginZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYBeginZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetEndXMidYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXMidYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXEndYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXEndYMidZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYEndZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYEndZ2;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYMidZValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYMidZ0;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYMidZValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYMidZ1;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>::GetMidXMidYMidZValue2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXMidYMidZ2;
}

template <typename Real>
void Mathematics::Bisect3Storage<Real>::SetStorageValue(Real value0, Real value1, Real value2, Bisect3StorageType type) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (type)
    {
        case Bisect3StorageType::BeginXBeginYBeginZ:
        {
            m_BeginXBeginYBeginZ0 = value0;
            m_BeginXBeginYBeginZ1 = value1;
            m_BeginXBeginYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXBeginYBeginZ:
        {
            m_EndXBeginYBeginZ0 = value0;
            m_EndXBeginYBeginZ1 = value1;
            m_EndXBeginYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXEndYBeginZ:
        {
            m_BeginXEndYBeginZ0 = value0;
            m_BeginXEndYBeginZ1 = value1;
            m_BeginXEndYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXEndYBeginZ:
        {
            m_EndXEndYBeginZ0 = value0;
            m_EndXEndYBeginZ1 = value1;
            m_EndXEndYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXBeginYEndZ:
        {
            m_BeginXBeginYEndZ0 = value0;
            m_BeginXBeginYEndZ1 = value1;
            m_BeginXBeginYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXBeginYEndZ:
        {
            m_EndXBeginYEndZ0 = value0;
            m_EndXBeginYEndZ1 = value1;
            m_EndXBeginYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXEndYEndZ:
        {
            m_BeginXEndYEndZ0 = value0;
            m_BeginXEndYEndZ1 = value1;
            m_BeginXEndYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXEndYEndZ:
        {
            m_EndXEndYEndZ0 = value0;
            m_EndXEndYEndZ1 = value1;
            m_EndXEndYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXBeginYMidZ:
        {
            m_BeginXBeginYMidZ0 = value0;
            m_BeginXBeginYMidZ1 = value1;
            m_BeginXBeginYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXBeginYMidZ:
        {
            m_EndXBeginYMidZ0 = value0;
            m_EndXBeginYMidZ1 = value1;
            m_EndXBeginYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXEndYMidZ:
        {
            m_BeginXEndYMidZ0 = value0;
            m_BeginXEndYMidZ1 = value1;
            m_BeginXEndYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXEndYMidZ:
        {
            m_EndXEndYMidZ0 = value0;
            m_EndXEndYMidZ1 = value1;
            m_EndXEndYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXMidYBeginZ:
        {
            m_BeginXMidYBeginZ0 = value0;
            m_BeginXMidYBeginZ1 = value1;
            m_BeginXMidYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXMidYBeginZ:
        {
            m_EndXMidYBeginZ0 = value0;
            m_EndXMidYBeginZ1 = value1;
            m_EndXMidYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXMidYEndZ:
        {
            m_BeginXMidYEndZ0 = value0;
            m_BeginXMidYEndZ1 = value1;
            m_BeginXMidYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXMidYEndZ:
        {
            m_EndXMidYEndZ0 = value0;
            m_EndXMidYEndZ1 = value1;
            m_EndXMidYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXBeginYBeginZ:
        {
            m_MidXBeginYBeginZ0 = value0;
            m_MidXBeginYBeginZ1 = value1;
            m_MidXBeginYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXEndYBeginZ:
        {
            m_MidXEndYBeginZ0 = value0;
            m_MidXEndYBeginZ1 = value1;
            m_MidXEndYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXBeginYEndZ:
        {
            m_MidXBeginYEndZ0 = value0;
            m_MidXBeginYEndZ1 = value1;
            m_MidXBeginYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXEndYEndZ:
        {
            m_MidXEndYEndZ0 = value0;
            m_MidXEndYEndZ1 = value1;
            m_MidXEndYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::BeginXMidYMidZ:
        {
            m_BeginXMidYMidZ0 = value0;
            m_BeginXMidYMidZ1 = value1;
            m_BeginXMidYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXBeginYMidZ:
        {
            m_MidXBeginYMidZ0 = value0;
            m_MidXBeginYMidZ1 = value1;
            m_MidXBeginYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXMidYBeginZ:
        {
            m_MidXMidYBeginZ0 = value0;
            m_MidXMidYBeginZ1 = value1;
            m_MidXMidYBeginZ2 = value2;
            break;
        }
        case Bisect3StorageType::EndXMidYMidZ:
        {
            m_EndXMidYMidZ0 = value0;
            m_EndXMidYMidZ1 = value1;
            m_EndXMidYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXEndYMidZ:
        {
            m_MidXEndYMidZ0 = value0;
            m_MidXEndYMidZ1 = value1;
            m_MidXEndYMidZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXMidYEndZ:
        {
            m_MidXMidYEndZ0 = value0;
            m_MidXMidYEndZ1 = value1;
            m_MidXMidYEndZ2 = value2;
            break;
        }
        case Bisect3StorageType::MidXMidYMidZ:
        {
            m_MidXMidYMidZ0 = value0;
            m_MidXMidYMidZ1 = value1;
            m_MidXMidYMidZ2 = value2;
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

    m_BeginPointX = node->GetX();
    m_BeginPointY = node->GetY();
    m_BeginPointZ = node->GetZ();
    m_EndPointX = endNode->GetX();
    m_EndPointY = endNode->GetY();
    m_EndPointZ = endNode->GetZ();
    m_MidpointX = (Math::GetRational(1, 2) * (m_BeginPointX + m_EndPointX));
    m_MidpointY = (Math::GetRational(1, 2) * (m_BeginPointY + m_EndPointY));
    m_MidpointZ = (Math::GetRational(1, 2) * (m_BeginPointZ + m_EndPointZ));
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H
