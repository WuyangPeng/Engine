// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:55)

#include "CoreTools/CoreToolsExport.h"

#include "OutTopLevel.h"
#include "Detail/OutTopLevelImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::OutTopLevel
	::OutTopLevel()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, OutTopLevel)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, OutTopLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, OutTopLevel, IsTopLevel, uint64_t, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, OutTopLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, OutTopLevel, operator[], int, CoreTools::ConstObjectInterfaceSmartPointer)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, OutTopLevel, Insert, ObjectInterfaceSmartPointer, void)

void CoreTools::OutTopLevel
	::SetUniqueID(int index, uint64_t uniqueID)
{
	IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->SetUniqueID(index, uniqueID);
}
