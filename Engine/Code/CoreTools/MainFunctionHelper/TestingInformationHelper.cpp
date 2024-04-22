/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:49)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelper.h"
#include "Detail/TestingInformationHelperImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::TestingInformationHelper::TestingInformationHelper(DisableNotThrow disableNotThrow)
    : impl{ disableNotThrow }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformationHelper)

int CoreTools::TestingInformationHelper::GetLoopCount(const std::string& suiteName, const std::string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetLoopCount(suiteName, testingName);
}

bool CoreTools::TestingInformationHelper::IsPrintRun() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsPrintRun();
}

int CoreTools::TestingInformationHelper::GetRandomSeed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRandomSeed();
}

CoreTools::TestingInformationHelper CoreTools::TestingInformationHelper::Create()
{
    return TestingInformationHelper{ DisableNotThrow::Disable };
}
