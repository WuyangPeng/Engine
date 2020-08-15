// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:54)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectName.h"
#include "Detail/ObjectNameImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;
using std::swap;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::ObjectName
	::ObjectName(const string& name)
	:m_Impl{ make_shared<ImplType>(name) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ObjectName)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, ObjectName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectName, GetName, const string&)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, ObjectName, SetName, string, void)

bool CoreTools::ObjectName
	::IsExactly(const ObjectName& name) const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->IsExactly(*name.m_Impl);
}

void CoreTools::ObjectName
	::Swap(ClassType& rhs) noexcept
{
	m_Impl.swap(rhs.m_Impl);
}


