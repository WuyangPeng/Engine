/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:46)

#include "Rendering/RenderingExport.h"

#include "RendererDrawTargetImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::RendererDrawTargetImpl::RendererDrawTargetImpl(const ConstDrawTargetSharedPtr& drawTarget) noexcept
    : drawTarget{ drawTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RendererDrawTargetImpl::IsValid() const noexcept
{
    if (drawTarget.lock())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::RendererDrawTargetImpl::ConstDrawTargetSharedPtr Rendering::RendererDrawTargetImpl::GetDrawTarget() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto result = drawTarget.lock();

    if (!result)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("drawTarget对象已被销毁。"))
    }

    return result;
}
