// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:40)

#include "CoreTools/CoreToolsExport.h"

#include "BitProxy.h"
#include "BitArray.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BitProxy
	::BitProxy(BitArray& bitArray, int position) noexcept
	:m_Array{ bitArray }, m_Position{ position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BitProxy
	::BitProxy(const BitProxy& bitProxy) noexcept
	:m_Array{ bitProxy.m_Array }, m_Position{ bitProxy.m_Position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::BitProxy& CoreTools::BitProxy
	::operator=(bool value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Array.Set(m_Position, value);

	return *this;
}

CoreTools::BitProxy& CoreTools::BitProxy
	::operator=(const BitProxy& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Array.Set(m_Position, rhs.m_Array.IsBitSet(rhs.m_Position));

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BitProxy
	::IsValid() const noexcept
{
	if (0 <= m_Position)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::BitProxy
	::operator bool() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Array.IsBitSet(m_Position);
}

void CoreTools::BitProxy
	::Flip() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Array.FlipBit(m_Position);
}

