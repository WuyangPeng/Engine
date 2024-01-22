/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:34)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Framework::WindowInstanceParameterImpl::WindowInstanceParameterImpl(WindowsHInstance instance, String className)
    : hInstance{ instance }, className{ std::move(className) }
{
    if (instance == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ʵ�������ڡ�"s))
    }

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowInstanceParameterImpl::IsValid() const noexcept
{
    if (hInstance != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Framework::WindowInstanceParameterImpl::WindowsHInstance Framework::WindowInstanceParameterImpl::GetHInstance() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return hInstance;
}

System::String Framework::WindowInstanceParameterImpl::GetWindowClassName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return className;
}
