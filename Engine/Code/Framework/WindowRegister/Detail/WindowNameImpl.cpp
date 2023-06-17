///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:02)

#include "Framework/FrameworkExport.h"

#include "WindowNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowNameImpl::WindowNameImpl(const String& className, const String& menuName)
    : className{ className }, menuName{ menuName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowNameImpl::IsValid() const noexcept
{
    if (!className.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::String Framework::WindowNameImpl::GetWindowClassName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return className;
}

System::String Framework::WindowNameImpl::GetWindowMenuName() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return menuName;
}
