// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:42)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H 

#include "IncrementScope.h"
#include "SimpleDecrementerDetail.h"
#include "SimpleIncrementerDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template< typename T, typename Aquire, typename Release >
CoreTools::IncrementScope<T, Aquire, Release>
	::IncrementScope(Reference value)
	: m_Vaule{ value }
{
	AquireType()(m_Vaule);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template< typename T, typename Aquire, typename Release >
CoreTools::IncrementScope<T, Aquire, Release>
	::~IncrementScope()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;

	ReleaseType()(m_Vaule);
}

#ifdef OPEN_CLASS_INVARIANT
template< typename T, typename Aquire, typename Release >
bool CoreTools::IncrementScope<T, Aquire, Release>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_INCREMENT_SCOPE_DETAIL_H

