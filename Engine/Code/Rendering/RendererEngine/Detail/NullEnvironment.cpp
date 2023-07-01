///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 14:43)

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
