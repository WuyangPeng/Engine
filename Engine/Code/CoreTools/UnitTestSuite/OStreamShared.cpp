// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.0.0 (2020/04/08 14:33)

#include "CoreTools/CoreToolsExport.h"

#include "OStreamShared.h"  
#include "Detail/OStreamImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::ostream;
using std::make_shared;

CoreTools::OStreamShared
	::OStreamShared(bool isCout)
	:m_Impl{ make_shared<ImplType>(isCout) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::OStreamShared
	::OStreamShared(const string& fileName)
	:m_Impl{ make_shared<ImplType>(fileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, OStreamShared)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, OStreamShared, GetStream, ostream&) 
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCout, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsCerr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, OStreamShared, IsFile, bool)
