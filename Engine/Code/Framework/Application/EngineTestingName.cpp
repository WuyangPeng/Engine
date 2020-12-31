// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "EngineTestingName.h" 
#include "Detail/EngineTestingNameImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

Framework::EngineTestingName
	::EngineTestingName(const String& endName)
	:m_Impl{ std::make_shared<ImplType>(endName) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
} 

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Framework, EngineTestingName)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EngineTestingName, PrintSelect, CoreTools::OStreamShared,void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EngineTestingName, IsSelectValid, int, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EngineTestingName, GetEngineTestingName, int, const System::String)

