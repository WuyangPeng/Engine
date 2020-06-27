// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:37)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H

#include "Bisect2Storage.h"
#include "Bisect2Node.h"
#include "Bisect2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect2Storage<Real>
	::Bisect2Storage(const Bisect2& bisect)
	:m_Bisect{ bisect },
	 m_BeginPointX{}, m_BeginPointY{}, m_EndPointX{}, m_EndPointY{}, m_MidpointX{}, m_MidpointY{},
	 m_FirstBeginXAndBeginY{}, m_FirstEndXAndBeginY{}, m_FirstBeginXAndEndY{}, m_FirstEndXAndEndY{},
	 m_FirstBeginXAndMidY{}, m_FirstEndXAndMidY{}, m_FirstMidXAndBeginY{}, m_FirstMidXAndEndY{}, m_FirstMidXAndMidY{},
	 m_SecondBeginXAndBeginY{}, m_SecondEndXAndBeginY{}, m_SecondBeginXAndEndY{}, m_SecondEndXAndEndY{},
	 m_SecondBeginXAndMidY{}, m_SecondEndXAndMidY{}, m_SecondMidXAndBeginY{}, m_SecondMidXAndEndY{}, m_SecondMidXAndMidY{},
	 m_Bisect2RootPtr{ nullptr }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect2Storage<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect2Storage<Real>
	::TestFourCornerValues(Real beginPointX, Real beginPointY, Real endPointX, Real endPointY)
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
bool Mathematics::Bisect2Storage<Real>
	::ZeroTest(Real x, Real y, Bisect2StorageType type)
{
	auto first = m_Bisect.GetFirstFunctionValue(x, y);
	auto second = m_Bisect.GetSecondFunctionValue(x, y);

	SetStorageValue(first, second, type);

	if (Math<Real>::FAbs(first) <= m_Bisect.GetTolerance() && Math<Real>::FAbs(second) <= m_Bisect.GetTolerance())
	{
		m_Bisect2RootPtr = std::make_shared<Bisect2Root>(x, y, BisectRootType::HaveSolution);

		return true;
	}

	return false;
}

template <typename Real>
typename const Mathematics::Bisect2Storage<Real>::Bisect2RootPtr Mathematics::Bisect2Storage<Real>
	::GetBisect2RootPtr() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Bisect2RootPtr;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginPointX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_BeginPointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginPointY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_BeginPointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndPointX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_EndPointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndPointY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_EndPointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidpointX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MidpointX;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidpointY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MidpointY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginXAndBeginYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXAndBeginY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndXAndBeginYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXAndBeginY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginXAndEndYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXAndEndY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndXAndEndYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXAndEndY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginXAndMidYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXAndMidY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndXAndMidYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXAndMidY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidXAndBeginYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXAndBeginY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidXAndEndYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXAndEndY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidXAndMidYFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXAndMidY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginXAndBeginYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXAndBeginY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndXAndBeginYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXAndBeginY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginXAndEndYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXAndEndY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndXAndEndYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXAndEndY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetBeginXAndMidYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXAndMidY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetEndXAndMidYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXAndMidY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidXAndBeginYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXAndBeginY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidXAndEndYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXAndEndY;
}

template <typename Real>
Real Mathematics::Bisect2Storage<Real>
	::GetMidXAndMidYSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXAndMidY;
} 

template <typename Real>
void Mathematics::Bisect2Storage<Real>
	::SetStorageValue(Real firstValue, Real secondValue, Bisect2StorageType type)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	switch (type)
	{
	case Bisect2StorageType::BeginXAndBeginY:
		m_FirstBeginXAndBeginY = firstValue;
		m_SecondBeginXAndBeginY = secondValue;
		break;

	case Bisect2StorageType::EndXAndBeginY:
		m_FirstEndXAndBeginY = firstValue;
		m_SecondEndXAndBeginY = secondValue;
		break;

	case Bisect2StorageType::BeginXAndEndY:
		m_FirstBeginXAndEndY = firstValue;
		m_SecondBeginXAndEndY = secondValue;
		break;

	case Bisect2StorageType::EndXAndEndY:
		m_FirstEndXAndEndY = firstValue;
		m_SecondEndXAndEndY = secondValue;
		break;

	case Bisect2StorageType::BeginXAndMidY:
		m_FirstBeginXAndMidY = firstValue;
		m_SecondBeginXAndMidY = secondValue;
		break;

	case Bisect2StorageType::EndXAndMidY:
		m_FirstEndXAndMidY = firstValue;
		m_SecondEndXAndMidY = secondValue;
		break;

	case Bisect2StorageType::MidXAndBeginY:
		m_FirstMidXAndBeginY = firstValue;
		m_SecondMidXAndBeginY = secondValue;
		break;

	case Bisect2StorageType::MidXAndEndY:
		m_FirstMidXAndEndY = firstValue;
		m_SecondMidXAndEndY = secondValue;
		break;

	case Bisect2StorageType::MidXAndMidY:
		m_FirstMidXAndMidY = firstValue;
		m_SecondMidXAndMidY = secondValue;
		break;

	default:
		break;
	}
}

template <typename Real>
void Mathematics::Bisect2Storage<Real>
	::SetStorageValue(Bisect2Node* node)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto xNext = node->GetXNext();
	auto yNext = node->GetYNext();

	// 二等分四边形。
	m_EndPointX = xNext->GetX();
	m_BeginPointY = xNext->GetY();
	m_BeginPointX = yNext->GetX();
	m_EndPointY = yNext->GetY();
	m_MidpointX = static_cast<Real>(0.5) * (m_BeginPointX + m_EndPointX);
	m_MidpointY = static_cast<Real>(0.5) * (m_BeginPointY + m_EndPointY);
}

template <typename Real>
bool Mathematics::Bisect2Storage<Real>
	::TestEdgeValues()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (ZeroTest(m_EndPointX, m_MidpointY, Bisect2StorageType::EndXAndMidY) || ZeroTest(m_MidpointX, m_EndPointY, Bisect2StorageType::MidXAndEndY) ||
		ZeroTest(m_MidpointX, m_BeginPointY, Bisect2StorageType::MidXAndBeginY) || ZeroTest(m_BeginPointX, m_MidpointY, Bisect2StorageType::BeginXAndMidY) ||
		ZeroTest(m_MidpointX, m_MidpointY, Bisect2StorageType::MidXAndMidY))
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_STORAGE_DETAIL_H
