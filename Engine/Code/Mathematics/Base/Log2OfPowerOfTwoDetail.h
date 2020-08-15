// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/18 19:16)

#ifndef MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H
#define MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H

#include "Log2OfPowerOfTwo.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h" 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
template <typename T>
Mathematics::Log2OfPowerOfTwo<T>
	::Log2OfPowerOfTwo(T powerOfTwo) noexcept
	:m_PowerOfTwo{ powerOfTwo }, m_PowerOfTwoCopy{ powerOfTwo }, m_Log2{ 0 }
{
	Convert();

	SELF_CLASS_IS_VALID_5;
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>
	::Convert() noexcept
{
	for (auto maskIndex = 0; maskIndex < sm_MaskSize; ++maskIndex)
	{
		DetermineWhetherBitExist(maskIndex);
	}
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>
	::DetermineWhetherBitExist(int maskIndex) noexcept
{
	if ((m_PowerOfTwoCopy & sm_Mask[maskIndex]) != 0)
	{
		PowerOfTwoWithMask(maskIndex);
	}
}

// private
template <typename T>
void Mathematics::Log2OfPowerOfTwo<T>
	::PowerOfTwoWithMask(int maskIndex) noexcept
{
	m_Log2 |= (1 << (sm_MaskSize - maskIndex - 1));
	m_PowerOfTwoCopy &= sm_Mask[maskIndex];
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsValid() const noexcept
{
	if (IsPowerOfTwoValid() && IsLog2Valid() && IsConvertValid())
		return true;
	else
		return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsPowerOfTwoValid() const noexcept
{
	if (0 <= m_PowerOfTwo)
		return true;
	else
		return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsLog2Valid() const noexcept
{
	if (0 <= static_cast<T>(m_Log2))
		return true;
	else
		return false;
}

template <typename T>
bool Mathematics::Log2OfPowerOfTwo<T>
	::IsConvertValid() const noexcept
{
	auto low = static_cast<T>(GetPowerOfTwoLow());
	auto high = low * 2;
	auto original = m_PowerOfTwo;

	if (low <= original && (original < high || high < low))
		return true;
	else
		return false;
}

template <typename T>
uint32_t Mathematics::Log2OfPowerOfTwo<T>
	::GetPowerOfTwoLow() const noexcept
{
	auto powerOfTwo = 1u;
	for (auto i = 0u; i < m_Log2; ++i)
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
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_BASE_LOG2_OF_POWER_OF_TWO_DETAIL_H
