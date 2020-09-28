// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:07)

#include "CoreTools/CoreToolsExport.h"

#include "LoadingLibrary.h"
#include "Detail/LoadingLibraryImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::LoadingLibrary
	::LoadingLibrary(const String& fileName, LoadLibraryType flags)
	:m_Impl{ make_shared<ImplType>(fileName,flags) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, LoadingLibrary)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, LoadingLibrary, GetLoadedModule, CoreTools::LoadingLibrary::DynamicLinkModule)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, LoadingLibrary, GetProcessAddress, string, CoreTools::LoadingLibrary::DynamicLinkProcess)
