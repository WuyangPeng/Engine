// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 17:15)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamManager.h"
#include "Detail/OFStreamManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::OFStreamManager
	::OFStreamManager(const String& fileName, bool addition)
	:m_Impl{ make_shared<ImplType>(fileName,addition) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, OFStreamManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, OFStreamManager, GetOFStreamSize, CoreTools::OFStreamManager::PosType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, OFStreamManager, SetSimplifiedChinese, void)

CoreTools::OFStreamManager& CoreTools::OFStreamManager
	::operator<<(const String& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	*m_Impl << message;

	return *this;
}



