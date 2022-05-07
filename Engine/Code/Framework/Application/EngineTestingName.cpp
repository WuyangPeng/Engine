///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 11:29)

#include "Framework/FrameworkExport.h"

#include "EngineTestingName.h"
#include "Detail/EngineTestingNameImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::EngineTestingName::EngineTestingName(const String& endName)
    : impl{ endName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineTestingName)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EngineTestingName, PrintSelect, CoreTools::OStreamShared, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EngineTestingName, IsSelectValid, int, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Framework, EngineTestingName, GetEngineTestingName, int, System::String)
