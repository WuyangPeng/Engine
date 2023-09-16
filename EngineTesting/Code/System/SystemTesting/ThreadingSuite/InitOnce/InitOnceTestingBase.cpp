///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 15:06)

#include "InitOnceTestingBase.h"
#include "System/Threading/Event.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::InitOnceTestingBase::InitOnceTestingBase(const OStreamShared& stream)
    : ParentType{ stream }, eventHandle{ nullptr }, enterInitHandleFunctionCount{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
