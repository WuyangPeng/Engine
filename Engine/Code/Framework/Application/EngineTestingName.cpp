/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:27)

#include "Framework/FrameworkExport.h"

#include "EngineTestingName.h"
#include "Detail/EngineTestingNameImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"

Framework::EngineTestingName::EngineTestingName(const String& endName)
    : impl{ endName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineTestingName)

void Framework::EngineTestingName::PrintSelect(const OStreamShared& stream)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->PrintSelect(stream);
}

bool Framework::EngineTestingName::IsSelectValid(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsSelectValid(select);
}

System::String Framework::EngineTestingName::GetEngineTestingName(int select) const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetEngineTestingName(select);
}
