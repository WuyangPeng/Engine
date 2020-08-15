// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:53)

#include "CoreTools/CoreToolsExport.h"

#include "InTopLevel.h"
#include "Detail/InTopLevelImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::InTopLevel
	::InTopLevel()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, InTopLevel)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, InTopLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, InTopLevel, IsTopLevel, uint64_t, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, GetTopLevelSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, InTopLevel, operator[], int, CoreTools::ConstObjectInterfaceSmartPointer)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, InTopLevel, Insert, ObjectInterfaceSmartPointer, void)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, InTopLevel, operator[], int, CoreTools::ObjectInterfaceSmartPointer&)
