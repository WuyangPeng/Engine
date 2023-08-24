///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/03 19:59)

#include "Framework/FrameworkExport.h"

#include "WindowHBrush.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Framework::WindowHBrush::WindowHBrush(WindowsBrushTypes background) noexcept
    : hBrush{ System::GetSystemStockObject(background) }
{
    CheckUpHBrush();

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

void Framework::WindowHBrush::CheckUpHBrush() noexcept
{
    if (hBrush == nullptr)
    {
        hBrush = System::GetSystemStockObject(WindowsBrushTypes::WhiteBrush);

        LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework, SYSTEM_TEXT("���ر�����ˢʧ�ܣ�"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowHBrush)

System::WindowsHBrush Framework::WindowHBrush::GetHBrush() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return static_cast<HBrush>(hBrush);
}
