///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/06 23:05)

#include "Rendering/RenderingExport.h"

#include "EnvironmentParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::EnvironmentParameterImpl::EnvironmentParameterImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, EnvironmentParameterImpl)

Rendering::EnvironmentParameterImpl::EnvironmentParameterSharedPtr Rendering::EnvironmentParameterImpl::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

System::WindowsHWnd Rendering::EnvironmentParameterImpl::GetWindowsHWnd() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("�޷���ȡWindows HWnd"s));
}
