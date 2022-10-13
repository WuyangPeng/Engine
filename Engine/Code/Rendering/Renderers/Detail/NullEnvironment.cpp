///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/05 10:59)

#include "Rendering/RenderingExport.h"

#include "NullEnvironment.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::NullEnvironment::NullEnvironment(const RendererParameter& rendererParameter) noexcept
    : ParentType{ rendererParameter }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, NullEnvironment)

Rendering::NullEnvironment::RenderingEnvironmentSharedPtr Rendering::NullEnvironment::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::NullEnvironment::InitEnvironment() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}
