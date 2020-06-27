// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.2 (2020/01/22 13:41)

#include "CoreTools/CoreToolsExport.h"

#include "TwoBitarray.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

CoreTools::TwoBitArray
	::TwoBitArray(int size)
	: m_Array{ sm_TwoSize * size }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TwoBitArray)

CoreTools::TwoBitProxy CoreTools::TwoBitArray
	::operator[](int position)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return TwoBitProxy{ *this, position };
}

CoreTools::ConstTwoBitProxy	CoreTools::TwoBitArray
	::operator[](int pos) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return ConstTwoBitProxy{ *this, pos };
}

bool CoreTools::TwoBitArray
	::operator==(const TwoBitArray& rhs) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Array == rhs.m_Array;
}

CoreTools::TwoBitArray&	CoreTools::TwoBitArray
	::operator&=(const TwoBitArray& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Array &= rhs.m_Array;

	return *this;
}

CoreTools::TwoBitArray&	CoreTools::TwoBitArray
	::operator|=(const TwoBitArray& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Array |= rhs.m_Array;

	return *this;
}

CoreTools::TwoBitArray&	CoreTools::TwoBitArray
	::operator^=(const TwoBitArray& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Array ^= rhs.m_Array;

	return *this;
}

const CoreTools::TwoBitArray CoreTools::TwoBitArray
	::operator~() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	TwoBitArray twoBitArray{ *this };
	twoBitArray.FlipAllBits();

	return twoBitArray;
}

void CoreTools::TwoBitArray
	::Clear() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Array.Clear();
}

void CoreTools::TwoBitArray
	::FlipBits(int position) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	Set(position, 3 ^ Get(position));
}

void CoreTools::TwoBitArray
	::Set(int position, uint32_t value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Array.Set(2 * position, value & 1);
	m_Array.Set(2 * position + 1, (value >> 1) & 1);
}

uint32_t CoreTools::TwoBitArray
	::Get(int position) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	auto lhs = m_Array.IsBitSet(2 * position);
	auto rhs = m_Array.IsBitSet(2 * position + 1);

	return (lhs != 0 ? 1 : 0) | ((rhs != 0 ? 1 : 0) << 1);
}

bool CoreTools::TwoBitArray
	::AllZero() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Array.AllBitsFalse();
}

void CoreTools::TwoBitArray
	::FlipAllBits() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Array.FlipAllBits();
}


