//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 10:19)

#include "CoreTools/CoreToolsExport.h"

#include "TestingInformationHelper.h"
#include "Detail/TestingInformationHelperImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;
using std::string;

CoreTools::TestingInformationHelper::TestingInformationHelper(DisableNotThrow disableNotThrow)
    : impl{  disableNotThrow }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TestingInformationHelper::TestingInformationHelper(TestingInformationHelper&& rhs) noexcept
    : impl{ std::move(rhs.impl) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::TestingInformationHelper& CoreTools::TestingInformationHelper::operator=(TestingInformationHelper&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    impl = std::move(rhs.impl);

    return *this;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, TestingInformationHelper)

int CoreTools::TestingInformationHelper::GetLoopCount(const string& suiteName, const string& testingName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetLoopCount(suiteName, testingName);
}

bool CoreTools::TestingInformationHelper::IsPrintRun() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsPrintRun();
}

int CoreTools::TestingInformationHelper::GetRandomSeed() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetRandomSeed();
}
