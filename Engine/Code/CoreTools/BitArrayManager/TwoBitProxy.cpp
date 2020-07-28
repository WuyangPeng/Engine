// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:42)

#include "CoreTools/CoreToolsExport.h"

#include "TwoBitProxy.h"
#include "TwoBitArray.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::TwoBitProxy
	::TwoBitProxy(TwoBitArray& array, int position) noexcept
	:m_Array{ array }, m_Position{ position }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TwoBitProxy&	CoreTools::TwoBitProxy
	::operator=(const TwoBitProxy& rhs) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Array.Set(m_Position, rhs.m_Array.Get(rhs.m_Position));

	return *this;
}

CoreTools::TwoBitProxy&	CoreTools::TwoBitProxy
	::operator=(uint32_t value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Array.Set(m_Position, value);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::TwoBitProxy
	::IsValid() const noexcept
{
	if (0 <= m_Position)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

CoreTools::TwoBitProxy
	::operator uint32_t() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Array.Get(m_Position);
}
