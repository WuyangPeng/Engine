/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:30)

#include "InitOnceTestingBase.h"
#include "System/Threading/Event.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitOnceTestingBase::InitOnceTestingBase(const OStreamShared& stream)
    : ParentType{ stream }, eventHandle{ nullptr }, enterInitHandleFunctionCount{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, InitOnceTestingBase)

void System::InitOnceTestingBase::CloseEventTest()
{
    ASSERT_TRUE(CloseSystemEvent(eventHandle));
}

void System::InitOnceTestingBase::SetEventHandle(WindowsHandle handle)
{
    if (eventHandle != nullptr)
    {
        ASSERT_EQUAL(handle, eventHandle);
    }
    else
    {
        eventHandle = handle;
    }
}

void System::InitOnceTestingBase::SetEventHandleNull() noexcept
{
    eventHandle = nullptr;
}

int System::InitOnceTestingBase::GetEnterInitHandleFunctionCount() const noexcept
{
    return enterInitHandleFunctionCount;
}

System::WindowsVoidPtr System::InitOnceTestingBase::GetEnterInitHandleFunctionCountPtr() noexcept
{
    return &enterInitHandleFunctionCount;
}

void System::InitOnceTestingBase::SetEnterInitHandleFunctionCount(int aEnterInitHandleFunctionCount) noexcept
{
    enterInitHandleFunctionCount = aEnterInitHandleFunctionCount;
}
