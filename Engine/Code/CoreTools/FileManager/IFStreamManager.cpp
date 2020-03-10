// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 17:15)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamManager.h"
#include "Detail/IFStreamManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::IFStreamManager
	::IFStreamManager(const String& fileName)
	:m_Impl{ make_shared<ImplType>(fileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, IFStreamManager)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, GetFileContent, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, BackupFile, System::String)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, IFStreamManager, SetSimplifiedChinese, void)






