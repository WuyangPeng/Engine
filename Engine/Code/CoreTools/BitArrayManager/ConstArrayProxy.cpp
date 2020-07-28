// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:41)

#include "CoreTools/CoreToolsExport.h"

#include "BitArray2D.h"
#include "ConstBitProxy.h"
#include "ConstArrayProxy.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ConstArrayProxy
	::ConstArrayProxy(const BitArray2D& bitArray2D, int position) noexcept
	:m_Array{ bitArray2D }, m_Position{ position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::ConstArrayProxy
	::ConstArrayProxy(const ConstArrayProxy& rhs) noexcept
	:m_Array{ rhs.m_Array }, m_Position{ rhs.m_Position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ConstArrayProxy
	::IsValid() const noexcept
{
	if (0 <= m_Position)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::ConstBitProxy CoreTools::ConstArrayProxy
	::operator[](int position) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return ConstBitProxy{ m_Array.GetBitArray(), m_Position * m_Array.GetWidth() + position };
}
