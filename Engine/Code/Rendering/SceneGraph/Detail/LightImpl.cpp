/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:35)

#include "Rendering/RenderingExport.h"

#include "LightImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::LightImpl::LightImpl() noexcept
    : lighting{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightImpl)

Rendering::LightingSharedPtr Rendering::LightImpl::GetLighting()
{
    RENDERING_CLASS_IS_VALID_9;

    if (lighting.object == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("灯光对象为空。"))
    }

    return lighting.object;
}

void Rendering::LightImpl::SetLighting(const LightingSharedPtr& aLighting) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    lighting.object = aLighting;
}

void Rendering::LightImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(lighting);
}

void Rendering::LightImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(lighting);
}

int Rendering::LightImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetStreamSize(lighting);
}
