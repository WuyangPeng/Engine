// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:55)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegister.h"
#include "Detail/ObjectRegisterImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::ObjectRegister
	::ObjectRegister()
	:m_Impl{ make_shared<ImplType>() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ObjectRegister)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, ObjectRegister);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, GetUniqueID, const ConstObjectInterfaceSmartPointer&, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectRegister, GetOrderedSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, operator[], int, const CoreTools::ConstObjectInterfaceSmartPointer&)
IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, RegisterRoot, const ConstObjectInterfaceSmartPointer&, uint64_t)

