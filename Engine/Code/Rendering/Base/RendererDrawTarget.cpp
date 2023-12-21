/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/08 17:44)

#include "Rendering/RenderingExport.h"

#include "RendererDrawTarget.h"
#include "Detail/RendererDrawTargetImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RendererDrawTarget)

Rendering::RendererDrawTarget::RendererDrawTarget(const ConstDrawTargetSharedPtr& drawTarget)
    : impl{ drawTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererDrawTarget)

Rendering::RendererDrawTarget::ConstDrawTargetSharedPtr Rendering::RendererDrawTarget::GetDrawTarget() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDrawTarget();
}
