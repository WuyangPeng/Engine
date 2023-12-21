/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:44)

#include "Rendering/RenderingExport.h"

#include "NullRendererObject.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::NullRendererObject::NullRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name)
    : ParentType{ graphicsObject, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, NullRendererObject)

void Rendering::NullRendererObject::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

bool Rendering::NullRendererObject::Update() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return false;
}

bool Rendering::NullRendererObject::Update(int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(level);

    return false;
}

bool Rendering::NullRendererObject::Update(int item, int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(item, level);

    return false;
}

bool Rendering::NullRendererObject::CopyGpuToCpu() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return false;
}

bool Rendering::NullRendererObject::CopyGpuToCpu(int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(level);

    return false;
}

bool Rendering::NullRendererObject::CopyGpuToCpu(int item, int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(item, level);

    return false;
}

bool Rendering::NullRendererObject::CopyCpuToGpu() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return false;
}

bool Rendering::NullRendererObject::CopyCpuToGpu(int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(level);

    return false;
}

bool Rendering::NullRendererObject::CopyCpuToGpu(int item, int level) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(item, level);

    return false;
}

bool Rendering::NullRendererObject::GetNumActiveElements() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return false;
}
