// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:32)

#include "CoreTools/CoreToolsExport.h"

#include "BitArray2D.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BitArray2D
	::BitArray2D(int firstDimensionality, int secondDimensionality)
	: m_BitArray{ firstDimensionality * secondDimensionality }, m_Width{ secondDimensionality }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BitArray2D
	::IsValid() const noexcept
{
	if (0 <= m_Width)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::ArrayProxy CoreTools::BitArray2D
	::operator[](int position) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return ArrayProxy{ *this,position };
}

CoreTools::ConstArrayProxy CoreTools::BitArray2D
	::operator[](int position) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return ConstArrayProxy{ *this,position };
}

bool CoreTools::BitArray2D
	::operator==(const BitArray2D& rhs) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BitArray == rhs.m_BitArray && m_Width == rhs.m_Width;
}

CoreTools::BitArray2D& CoreTools::BitArray2D
	::operator&=(const BitArray2D& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray &= rhs.m_BitArray;

	return *this;
}

CoreTools::BitArray2D& CoreTools::BitArray2D
	::operator|=(const BitArray2D& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray |= rhs.m_BitArray;

	return *this;
}

CoreTools::BitArray2D&	CoreTools::BitArray2D
	::operator^=(const BitArray2D& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray ^= rhs.m_BitArray;

	return *this;
}

const CoreTools::BitArray2D	CoreTools::BitArray2D
	::operator~() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	BitArray2D bitArray2D{ *this };
	bitArray2D.FlipAllBits();

	return bitArray2D;
}

void CoreTools::BitArray2D
	::Clear() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray.Clear();
}

void CoreTools::BitArray2D
	::SetBit(int firstPosition, int secondPosition) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray.SetBit(firstPosition * m_Width + secondPosition);
}

void CoreTools::BitArray2D
	::ClearBit(int firstPosition, int secondPosition) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray.ClearBit(firstPosition * m_Width + secondPosition);
}

void CoreTools::BitArray2D
	::FlipBit(int firstPosition, int secondPosition) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray.FlipBit(firstPosition * m_Width + secondPosition);
}

void CoreTools::BitArray2D
	::Set(int firstPosition, int secondPosition, bool value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	value ? SetBit(firstPosition, secondPosition) : ClearBit(firstPosition, secondPosition);
}

bool CoreTools::BitArray2D
	::IsBitSet(int firstPosition, int secondPosition) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BitArray.IsBitSet(firstPosition * m_Width + secondPosition);
}

bool CoreTools::BitArray2D
	::AllBitsFalse() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BitArray.AllBitsFalse();
}

void CoreTools::BitArray2D
	::FlipAllBits() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_BitArray.FlipAllBits();
}

int CoreTools::BitArray2D
	::GetWidth() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Width;
}

const CoreTools::BitArray& CoreTools::BitArray2D
	::GetBitArray() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_BitArray;
}

CoreTools::BitArray& CoreTools::BitArray2D
	::GetBitArray() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_BitArray;
}





