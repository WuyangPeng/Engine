/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:13)

#include "Framework/FrameworkExport.h"

#include "WindowRegisterParameter.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

Framework::WindowRegisterParameter::WindowRegisterParameter(HInstance instance, WindowClassStyle styles, int windowClassExtra, int windowExtra)
    : instance{ instance }, style{ styles }, windowClassExtra{ windowClassExtra }, windowExtra{ windowExtra }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ʵ�������ڡ�"s))
    }

    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

bool Framework::WindowRegisterParameter::IsValid() const noexcept
{
    if (instance != nullptr)
        return true;
    else
        return false;
}

System::WindowsHInstance Framework::WindowRegisterParameter::GetHInstance() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return instance;
}

System::WindowsClassStyle Framework::WindowRegisterParameter::GetStyle() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return style;
}

int Framework::WindowRegisterParameter::GetWindowClassExtra() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowClassExtra;
}

int Framework::WindowRegisterParameter::GetWindowExtra() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowExtra;
}
