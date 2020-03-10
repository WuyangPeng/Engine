// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 15:52)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

#include "Log2OfPowerOfTwo.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

// 1111 1111 1111 1111 0000 0000 0000 0000
// 1111 1111 0000 0000 1111 1111 0000 0000 
// 1111 0000 1111 0000 1111 0000 1111 0000
// 1100 1100 1100 1100 1100 1100 1100 1100 
// 1010 1010 1010 1010 1010 1010 1010 1010
template <typename T>
const unsigned Mathematics::Log2OfPowerOfTwo<T>
	::sm_Mask[sm_MaskSize] { 0xFFFF0000,0xFF00FF00,0xF0F0F0F0,0xCCCCCCCC,0xAAAAAAAA};

template <typename T>
Mathematics::Log2OfPowerOfTwo<T>
	::Log2OfPowerOfTwo( T powerOfTwo )
	:m_PowerOfTwo{ powerOfTwo },m_PowerOfTwoCopy{ powerOfTwo },m_Log2{ 0 }
{
	Convert();

	SELF_CLASS_IS_VALID_5;
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>
	::Convert()
{
	for(auto maskIndex = 0;maskIndex < sm_MaskSize;++maskIndex)
	{
		DetermineWhetherBitExist(maskIndex);
	}
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>
	::DetermineWhetherBitExist( int maskIndex )
{
	if ((m_PowerOfTwoCopy & sm_Mask[maskIndex]) != 0)
	{
		PowerOfTwoWithMask(maskIndex);
	}		
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>
	::PowerOfTwoWithMask(int maskIndex)
{
	m_Log2 |= (1 << (sm_MaskSize - maskIndex - 1));
	m_PowerOfTwoCopy &= sm_Mask[maskIndex];
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsValid() const noexcept
{
	if(IsPowerOfTwoValid() && IsLog2Valid() && IsConvertValid())
	    return true;
	else
		return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsPowerOfTwoValid() const noexcept
{
	if(0 <= m_PowerOfTwo)
		return true;
	else
		return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsLog2Valid() const noexcept
{
	if(0 <= static_cast<T>(m_Log2))
		return true;
	else
		return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsConvertValid() const noexcept
{
	T low = static_cast<T>(GetPowerOfTwoLow());
	T high = low * 2;
	T original = m_PowerOfTwo;

	if(low <= original && (original < high || high < low))	
		return true;	
	else
		return false;
}

template <typename T>
uint32_t Mathematics::Log2OfPowerOfTwo<T>
	::GetPowerOfTwoLow() const noexcept
{
	uint32_t powerOfTwo = 1;
	for(auto i = 0u;i < m_Log2;++i)
	{
		powerOfTwo *= 2;
	}

	return powerOfTwo;
}

#endif // OPEN_CLASS_INVARIANT

template <typename T>
T Mathematics::Log2OfPowerOfTwo<T>
	::GetLog2() const
{
	CLASS_IS_VALID_5;

	return boost::numeric_cast<T>(m_Log2);
}

#endif // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H
