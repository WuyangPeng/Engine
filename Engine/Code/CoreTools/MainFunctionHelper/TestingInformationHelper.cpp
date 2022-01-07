///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/29 22:31)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelper.h"
#include "Detail/TestingInformationHelperImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::TestingInformationHelper::TestingInformationHelper(DisableNotThrow disableNotThrow)
    : impl{ disableNotThrow }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformationHelper)

int CoreTools::TestingInformationHelper::GetLoopCount(const string& suiteName, const string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetLoopCount(suiteName, testingName);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, TestingInformationHelper, IsPrintRun, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, TestingInformationHelper, GetRandomSeed, int)

CoreTools::TestingInformationHelper CoreTools::TestingInformationHelper::Create()
{
    return TestingInformationHelper{ DisableNotThrow::Disable };
}
