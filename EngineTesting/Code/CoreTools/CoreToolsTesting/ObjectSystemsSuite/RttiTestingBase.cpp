///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:18)

#include "RttiTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::RttiTestingBase::RttiTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, RttiTestingBase)

void CoreTools::RttiTestingBase::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

CORE_TOOLS_RTTI_BASE_DEFINE(CoreTools, RttiTestingBase)

void CoreTools::RttiTestingBase::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
}

void CoreTools::RttiTestingBase::RttiTest()
{
    ASSERT_EQUAL("CoreTools.RttiTestingBase", GetRttiType().GetName());
    ASSERT_TRUE(GetRttiType().IsExactly(ClassType::GetRttiType()));
    ASSERT_TRUE(GetRttiType().IsDerived(ClassType::GetRttiType()));
}
