///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 16:08)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H

#include "Bisect2Node.h"
#include "Bisect2Storage.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Bisect2.h"

template <typename Real>
Mathematics::Bisect2Storage<Real>::Bisect2Storage(const Bisect2& bisect) noexcept
    : m_Bisect{ bisect },
      m_BeginPointX{},
      m_BeginPointY{},
      m_EndPointX{},
      m_EndPointY{},
      m_MidpointX{},
      m_MidpointY{},
      m_BeginXAndBeginY0{},
      m_EndXAndBeginY0{},
      m_BeginXAndEndY0{},
      m_EndXAndEndY0{},
      m_BeginXAndMidY0{},
      m_EndXAndMidY0{},
      m_MidXAndBeginY0{},
      m_MidXAndEndY0{},
      m_MidXAndMidY0{},
      m_BeginXAndBeginY1{},
      m_EndXAndBeginY1{},
      m_BeginXAndEndY1{},
      m_EndXAndEndY1{},
      m_BeginXAndMidY1{},
      m_EndXAndMidY1{},
      m_MidXAndBeginY1{},
      m_MidXAndEndY1{},
      m_MidXAndMidY1{},
      m_Bisect2Root{}
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
bool Mathematics::Bisect2Storage<Real>::TestFourCornerValues(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (ZeroTest(beginPointX, beginPointY, Bisect2StorageType::BeginXAndBeginY) || ZeroTest(endPointX, beginPointY, Bisect2StorageType::EndXAndBeginY) ||
        ZeroTest(beginPointX, endPointY, Bisect2StorageType::BeginXAndEndY) || ZeroTest(endPointX, endPointY, Bisect2StorageType::EndXAndEndY))
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
    auto value0 = m_Bisect.GetFunction0Value(x, y);
    auto value1 = m_Bisect.GetFunction1Value(x, y);

    SetStorageValue(value0, value1, type);

    if (Math::FAbs(value0) <= m_Bisect.GetTolerance() && Math::FAbs(value1) <= m_Bisect.GetTolerance())
    {
        m_Bisect2Root = std::make_shared<Bisect2Root>(x, y, BisectRootType::HaveSolution);

        return true;
    }

    return false;
}

template <typename Real>
typename const Mathematics::Bisect2Storage<Real>::Bisect2RootSharedPtr Mathematics::Bisect2Storage<Real>::GetBisect2Root() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Bisect2Root;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginPointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginPointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndPointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndPointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndPointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndPointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidpointX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidpointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidpointY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidpointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndBeginYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXAndBeginY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndBeginYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXAndBeginY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndEndYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXAndEndY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndEndYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXAndEndY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndMidYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXAndMidY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndMidYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXAndMidY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndBeginYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXAndBeginY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndEndYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXAndEndY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndMidYValue0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXAndMidY0;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndBeginYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXAndBeginY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndBeginYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXAndBeginY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndEndYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXAndEndY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndEndYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXAndEndY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetBeginXAndMidYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BeginXAndMidY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetEndXAndMidYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_EndXAndMidY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndBeginYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXAndBeginY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndEndYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXAndEndY1;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>::GetMidXAndMidYValue1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MidXAndMidY1;
}

template <typename Real>
void Mathematics::Bisect2Storage<Real>::SetStorageValue(Real value0, Real value1, Bisect2StorageType type) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    switch (type)
    {
        case Bisect2StorageType::BeginXAndBeginY:
            m_BeginXAndBeginY0 = value0;
            m_BeginXAndBeginY1 = value1;
            break;

        case Bisect2StorageType::EndXAndBeginY:
            m_EndXAndBeginY0 = value0;
            m_EndXAndBeginY1 = value1;
            break;

        case Bisect2StorageType::BeginXAndEndY:
            m_BeginXAndEndY0 = value0;
            m_BeginXAndEndY1 = value1;
            break;

        case Bisect2StorageType::EndXAndEndY:
            m_EndXAndEndY0 = value0;
            m_EndXAndEndY1 = value1;
            break;

        case Bisect2StorageType::BeginXAndMidY:
            m_BeginXAndMidY0 = value0;
            m_BeginXAndMidY1 = value1;
            break;

        case Bisect2StorageType::EndXAndMidY:
            m_EndXAndMidY0 = value0;
            m_EndXAndMidY1 = value1;
            break;

        case Bisect2StorageType::MidXAndBeginY:
            m_MidXAndBeginY0 = value0;
            m_MidXAndBeginY1 = value1;
            break;

        case Bisect2StorageType::MidXAndEndY:
            m_MidXAndEndY0 = value0;
            m_MidXAndEndY1 = value1;
            break;

        case Bisect2StorageType::MidXAndMidY:
            m_MidXAndMidY0 = value0;
            m_MidXAndMidY1 = value1;
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
        m_EndPointX = xNext->GetX();
        m_BeginPointX = yNext->GetX();
        m_MidpointX = Math::GetRational(1, 2) * (m_BeginPointX + m_EndPointX);
    }

    if (yNext != nullptr)
    {
        m_BeginPointY = xNext->GetY();
        m_EndPointY = yNext->GetY();
        m_MidpointY = Math::GetRational(1, 2) * (m_BeginPointY + m_EndPointY);
    }
}

template <typename Real>
bool Mathematics::Bisect2Storage<Real>::TestEdgeValues()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (ZeroTest(m_EndPointX, m_MidpointY, Bisect2StorageType::EndXAndMidY) ||
        ZeroTest(m_MidpointX, m_EndPointY, Bisect2StorageType::MidXAndEndY) ||
        ZeroTest(m_MidpointX, m_BeginPointY, Bisect2StorageType::MidXAndBeginY) ||
        ZeroTest(m_BeginPointX, m_MidpointY, Bisect2StorageType::BeginXAndMidY) ||
        ZeroTest(m_MidpointX, m_MidpointY, Bisect2StorageType::MidXAndMidY))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H
