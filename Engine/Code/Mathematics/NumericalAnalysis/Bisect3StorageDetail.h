// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 13:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H

#include "Bisect3Storage.h"
#include "Bisect3.h"
#include "Bisect3Root.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect3Storage<Real>
	::Bisect3Storage(const Bisect3& bisect)
	: m_Bisect{ bisect },
	  m_BeginPointX{}, m_EndPointX{}, m_MidpointX{}, m_BeginPointY{}, m_EndPointY{},
	  m_MidpointY{}, m_BeginPointZ{}, m_EndPointZ{}, m_MidpointZ{},
	  m_FirstBeginXBeginYBeginZ{}, m_FirstEndXBeginYBeginZ{}, m_FirstBeginXEndYBeginZ{}, m_FirstEndXEndYBeginZ{},
	  m_FirstBeginXBeginYEndZ{}, m_FirstEndXBeginYEndZ{}, m_FirstBeginXEndYEndZ{}, m_FirstEndXEndYEndZ{},
	  m_SecondBeginXBeginYBeginZ{}, m_SecondEndXBeginYBeginZ{}, m_SecondBeginXEndYBeginZ{}, m_SecondEndXEndYBeginZ{},
	  m_SecondBeginXBeginYEndZ{}, m_SecondEndXBeginYEndZ{}, m_SecondBeginXEndYEndZ{}, m_SecondEndXEndYEndZ{},
	  m_ThirdBeginXBeginYBeginZ{}, m_ThirdEndXBeginYBeginZ{}, m_ThirdBeginXEndYBeginZ{}, m_ThirdEndXEndYBeginZ{},
	  m_ThirdBeginXBeginYEndZ{}, m_ThirdEndXBeginYEndZ{}, m_ThirdBeginXEndYEndZ{}, m_ThirdEndXEndYEndZ{},
	  m_FirstBeginXBeginYMidZ{}, m_FirstEndXBeginYMidZ{}, m_FirstBeginXEndYMidZ{}, m_FirstEndXEndYMidZ{},
	  m_FirstBeginXMidYBeginZ{}, m_FirstEndXMidYBeginZ{}, m_FirstBeginXMidYEndZ{}, m_FirstEndXMidYEndZ{},
	  m_FirstMidXBeginYBeginZ{}, m_FirstMidXEndYBeginZ{}, m_FirstMidXBeginYEndZ{}, m_FirstMidXEndYEndZ{},
	  m_SecondBeginXBeginYMidZ{}, m_SecondEndXBeginYMidZ{}, m_SecondBeginXEndYMidZ{}, m_SecondEndXEndYMidZ{},
	  m_SecondBeginXMidYBeginZ{}, m_SecondEndXMidYBeginZ{}, m_SecondBeginXMidYEndZ{}, m_SecondEndXMidYEndZ{},
	  m_SecondMidXBeginYBeginZ{}, m_SecondMidXEndYBeginZ{}, m_SecondMidXBeginYEndZ{}, m_SecondMidXEndYEndZ{},
	  m_ThirdBeginXBeginYMidZ{}, m_ThirdEndXBeginYMidZ{}, m_ThirdBeginXEndYMidZ{}, m_ThirdEndXEndYMidZ{},
	  m_ThirdBeginXMidYBeginZ{}, m_ThirdEndXMidYBeginZ{}, m_ThirdBeginXMidYEndZ{}, m_ThirdEndXMidYEndZ{},
	  m_ThirdMidXBeginYBeginZ{}, m_ThirdMidXEndYBeginZ{}, m_ThirdMidXBeginYEndZ{}, m_ThirdMidXEndYEndZ{},
	  m_FirstBeginXMidYMidZ{}, m_FirstMidXBeginYMidZ{}, m_FirstMidXMidYBeginZ{},
	  m_FirstEndXMidYMidZ{}, m_FirstMidXEndYMidZ{}, m_FirstMidXMidYEndZ{},
	  m_SecondBeginXMidYMidZ{}, m_SecondMidXBeginYMidZ{}, m_SecondMidXMidYBeginZ{},
	  m_SecondEndXMidYMidZ{}, m_SecondMidXEndYMidZ{}, m_SecondMidXMidYEndZ{},
	  m_ThirdBeginXMidYMidZ{}, m_ThirdMidXBeginYMidZ{}, m_ThirdMidXMidYBeginZ{},
	  m_ThirdEndXMidYMidZ{}, m_ThirdMidXEndYMidZ{}, m_ThirdMidXMidYEndZ{},
	  m_FirstMidXMidYMidZ{}, m_SecondMidXMidYMidZ{}, m_ThirdMidXMidYMidZ{},
	  m_Bisect3RootPtr{ nullptr }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3Storage<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect3Storage<Real>
	::TestEightCornerValues(Real beginPointX, Real beginPointY, Real beginPointZ,
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
bool Mathematics::Bisect3Storage<Real>
	::TestEdgeValues()
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
typename const Mathematics::Bisect3Storage<Real>::Bisect3RootPtr Mathematics::Bisect3Storage<Real>
	::GetBisect3RootPtr() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Bisect3RootPtr;
}

template <typename Real>
bool Mathematics::Bisect3Storage<Real>
	::ZeroTest(Real x, Real y, Real z, Bisect3StorageType type)
{
	auto first = m_Bisect.GetFirstFunctionValue(x, y, z);
	auto second = m_Bisect.GetSecondFunctionValue(x, y, z);
	auto third = m_Bisect.GetThirdFunctionValue(x, y, z);

	SetStorageValue(first, second, third, type);

	if (Math<Real>::FAbs(first) <= m_Bisect.GetTolerance() && Math<Real>::FAbs(second) <= m_Bisect.GetTolerance() && Math<Real>::FAbs(third) <= m_Bisect.GetTolerance())
	{
		m_Bisect3RootPtr = std::make_shared<Bisect3Root>(x, y, z, BisectRootType::HaveSolution);

		return true;
	}

	return false;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginPointX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_BeginPointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginPointY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_BeginPointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginPointZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_BeginPointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndPointX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_EndPointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndPointY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_EndPointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndPointZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_EndPointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidpointX() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MidpointX;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidpointY() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MidpointY;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidpointZ() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_MidpointZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXBeginYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXBeginYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXEndYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXEndYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXBeginYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXEndYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXBeginYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXEndYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstBeginXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYBeginZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstEndXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYEndZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondBeginXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYBeginZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondEndXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYEndZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetBeginXMidYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdBeginXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXBeginYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXBeginYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYBeginZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXMidYBeginZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetEndXMidYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdEndXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXEndYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXEndYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYEndZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXMidYEndZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYMidZFirstValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_FirstMidXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYMidZSecondValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_SecondMidXMidYMidZ;
}

template <typename Real>
Real Mathematics::Bisect3Storage<Real>
	::GetMidXMidYMidZThirdValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_ThirdMidXMidYMidZ;
}

template <typename Real>
void Mathematics::Bisect3Storage<Real>
	::SetStorageValue(Real firstValue, Real secondValue, Real thirdValue, Bisect3StorageType type)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	switch (type)
	{
	case Bisect3StorageType::BeginXBeginYBeginZ:
	{
		m_FirstBeginXBeginYBeginZ = firstValue;
		m_SecondBeginXBeginYBeginZ = secondValue;
		m_ThirdBeginXBeginYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXBeginYBeginZ:
	{
		m_FirstEndXBeginYBeginZ = firstValue;
		m_SecondEndXBeginYBeginZ = secondValue;
		m_ThirdEndXBeginYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXEndYBeginZ:
	{
		m_FirstBeginXEndYBeginZ = firstValue;
		m_SecondBeginXEndYBeginZ = secondValue;
		m_ThirdBeginXEndYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXEndYBeginZ:
	{
		m_FirstEndXEndYBeginZ = firstValue;
		m_SecondEndXEndYBeginZ = secondValue;
		m_ThirdEndXEndYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXBeginYEndZ:
	{
		m_FirstBeginXBeginYEndZ = firstValue;
		m_SecondBeginXBeginYEndZ = secondValue;
		m_ThirdBeginXBeginYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXBeginYEndZ:
	{
		m_FirstEndXBeginYEndZ = firstValue;
		m_SecondEndXBeginYEndZ = secondValue;
		m_ThirdEndXBeginYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXEndYEndZ:
	{
		m_FirstBeginXEndYEndZ = firstValue;
		m_SecondBeginXEndYEndZ = secondValue;
		m_ThirdBeginXEndYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXEndYEndZ:
	{
		m_FirstEndXEndYEndZ = firstValue;
		m_SecondEndXEndYEndZ = secondValue;
		m_ThirdEndXEndYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXBeginYMidZ:
	{
		m_FirstBeginXBeginYMidZ = firstValue;
		m_SecondBeginXBeginYMidZ = secondValue;
		m_ThirdBeginXBeginYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXBeginYMidZ:
	{
		m_FirstEndXBeginYMidZ = firstValue;
		m_SecondEndXBeginYMidZ = secondValue;
		m_ThirdEndXBeginYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXEndYMidZ:
	{
		m_FirstBeginXEndYMidZ = firstValue;
		m_SecondBeginXEndYMidZ = secondValue;
		m_ThirdBeginXEndYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXEndYMidZ:
	{
		m_FirstEndXEndYMidZ = firstValue;
		m_SecondEndXEndYMidZ = secondValue;
		m_ThirdEndXEndYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXMidYBeginZ:
	{
		m_FirstBeginXMidYBeginZ = firstValue;
		m_SecondBeginXMidYBeginZ = secondValue;
		m_ThirdBeginXMidYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXMidYBeginZ:
	{
		m_FirstEndXMidYBeginZ = firstValue;
		m_SecondEndXMidYBeginZ = secondValue;
		m_ThirdEndXMidYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXMidYEndZ:
	{
		m_FirstBeginXMidYEndZ = firstValue;
		m_SecondBeginXMidYEndZ = secondValue;
		m_ThirdBeginXMidYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXMidYEndZ:
	{
		m_FirstEndXMidYEndZ = firstValue;
		m_SecondEndXMidYEndZ = secondValue;
		m_ThirdEndXMidYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXBeginYBeginZ:
	{
		m_FirstMidXBeginYBeginZ = firstValue;
		m_SecondMidXBeginYBeginZ = secondValue;
		m_ThirdMidXBeginYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXEndYBeginZ:
	{
		m_FirstMidXEndYBeginZ = firstValue;
		m_SecondMidXEndYBeginZ = secondValue;
		m_ThirdMidXEndYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXBeginYEndZ:
	{
		m_FirstMidXBeginYEndZ = firstValue;
		m_SecondMidXBeginYEndZ = secondValue;
		m_ThirdMidXBeginYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXEndYEndZ:
	{
		m_FirstMidXEndYEndZ = firstValue;
		m_SecondMidXEndYEndZ = secondValue;
		m_ThirdMidXEndYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::BeginXMidYMidZ:
	{
		m_FirstBeginXMidYMidZ = firstValue;
		m_SecondBeginXMidYMidZ = secondValue;
		m_ThirdBeginXMidYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXBeginYMidZ:
	{
		m_FirstMidXBeginYMidZ = firstValue;
		m_SecondMidXBeginYMidZ = secondValue;
		m_ThirdMidXBeginYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXMidYBeginZ:
	{
		m_FirstMidXMidYBeginZ = firstValue;
		m_SecondMidXMidYBeginZ = secondValue;
		m_ThirdMidXMidYBeginZ = thirdValue;
		break;
	}
	case Bisect3StorageType::EndXMidYMidZ:
	{
		m_FirstEndXMidYMidZ = firstValue;
		m_SecondEndXMidYMidZ = secondValue;
		m_ThirdEndXMidYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXEndYMidZ:
	{
		m_FirstMidXEndYMidZ = firstValue;
		m_SecondMidXEndYMidZ = secondValue;
		m_ThirdMidXEndYMidZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXMidYEndZ:
	{
		m_FirstMidXMidYEndZ = firstValue;
		m_SecondMidXMidYEndZ = secondValue;
		m_ThirdMidXMidYEndZ = thirdValue;
		break;
	}
	case Bisect3StorageType::MidXMidYMidZ:
	{
		m_FirstMidXMidYMidZ = firstValue;
		m_SecondMidXMidYMidZ = secondValue;
		m_ThirdMidXMidYMidZ = thirdValue;
		break;
	}

	default:
		break;
	}
}

template <typename Real>
void Mathematics::Bisect3Storage<Real>
	::SetStorageValue(Bisect3Node* node)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto endNode = node->GetXNext()->GetYNext()->GetZNext();

	m_BeginPointX = node->GetX();
	m_BeginPointY = node->GetY();
	m_BeginPointZ = node->GetZ();
	m_EndPointX = endNode->GetX();
	m_EndPointY = endNode->GetY();
	m_EndPointZ = endNode->GetZ();
	m_MidpointX = ( Math::GetRational(1,2) * (m_BeginPointX + m_EndPointX));
	m_MidpointY = ( Math::GetRational(1,2) * (m_BeginPointY + m_EndPointY));
	m_MidpointZ = ( Math::GetRational(1,2) * (m_BeginPointZ + m_EndPointZ));
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_STORAGE_DETAIL_H
