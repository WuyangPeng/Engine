///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 13:20)

#include "ProcessTestingBase.h"
#include "System/Threading/Process.h"
#include "System/Threading/Thread.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::ProcessTestingBase::ProcessTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      processFullPath{ GetEngineeringDirectory() + SYSTEM_TEXT("ProcessTest"s) + GetEngineeringSuffix() + GetEngineeringExeSuffix() }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ProcessTestingBase)

void System::ProcessTestingBase::CloseProcessTest(const ProcessInformation& processInformation)
{
    ASSERT_TRUE(CloseSystemThread(processInformation.hThread));
    ASSERT_TRUE(CloseSystemProcess(processInformation.hProcess));
}

System::String System::ProcessTestingBase::GetProcessFullPath() const
{
    return processFullPath;
}
