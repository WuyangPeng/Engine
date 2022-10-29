///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 17:19)

#include "Rendering/RenderingExport.h"

#include "BlendStateTarget.h"
#include "Flags/BlendStateColorWrite.h"
#include "Flags/BlendStateMode.h"
#include "Flags/BlendStateOperation.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

Rendering::BlendStateTarget::BlendStateTarget() noexcept
    : enable{ false },
      sourceColor{ BlendStateMode::One },
      destinationColor{ BlendStateMode::Zero },
      operationColor{ BlendStateOperation::Add },
      sourceAlpha{ BlendStateMode::One },
      destinationAlpha{ BlendStateMode::Zero },
      operationAlpha{ BlendStateOperation::Add },
      mask{ BlendStateColorWrite::EnableAll }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BlendStateTarget)

bool Rendering::BlendStateTarget::IsEnable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enable;
}

void Rendering::BlendStateTarget::SetEnable(bool aEnable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enable = aEnable;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetSourceColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sourceColor;
}

void Rendering::BlendStateTarget::SetSourceColor(BlendStateMode color) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    sourceColor = color;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetDestinationColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return destinationColor;
}

void Rendering::BlendStateTarget::SetDestinationColor(BlendStateMode color) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    destinationColor = color;
}

Rendering::BlendStateOperation Rendering::BlendStateTarget::GetOperationColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return operationColor;
}

void Rendering::BlendStateTarget::SetOperationColor(BlendStateOperation color) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    operationColor = color;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetSourceAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sourceAlpha;
}

void Rendering::BlendStateTarget::SetSourceAlpha(BlendStateMode alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    sourceAlpha = alpha;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetDestinationAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return destinationAlpha;
}

void Rendering::BlendStateTarget::SetDestinationAlpha(BlendStateMode alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    destinationAlpha = alpha;
}

Rendering::BlendStateOperation Rendering::BlendStateTarget::GetOperationAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return operationAlpha;
}

void Rendering::BlendStateTarget::SetOperationAlpha(BlendStateOperation alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    operationAlpha = alpha;
}

Rendering::BlendStateColorWrite Rendering::BlendStateTarget::GetMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return mask;
}

void Rendering::BlendStateTarget::SetMask(BlendStateColorWrite aMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    mask = aMask;
}

void Rendering::BlendStateTarget::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(enable);
    source.ReadEnum(sourceColor);
    source.ReadEnum(destinationColor);
    source.ReadEnum(operationColor);
    source.ReadEnum(sourceAlpha);
    source.ReadEnum(destinationAlpha);
    source.ReadEnum(operationAlpha);
    source.ReadEnum(mask);
}

void Rendering::BlendStateTarget::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(enable);
    target.WriteEnum(sourceColor);
    target.WriteEnum(destinationColor);
    target.WriteEnum(operationColor);
    target.WriteEnum(sourceAlpha);
    target.WriteEnum(destinationAlpha);
    target.WriteEnum(operationAlpha);
    target.WriteEnum(mask);
}

int Rendering::BlendStateTarget::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(enable);

    size += CORE_TOOLS_STREAM_SIZE(sourceColor);
    size += CORE_TOOLS_STREAM_SIZE(destinationColor);
    size += CORE_TOOLS_STREAM_SIZE(operationColor);
    size += CORE_TOOLS_STREAM_SIZE(sourceAlpha);
    size += CORE_TOOLS_STREAM_SIZE(destinationAlpha);
    size += CORE_TOOLS_STREAM_SIZE(operationAlpha);
    size += CORE_TOOLS_STREAM_SIZE(mask);

    return size;
}

bool Rendering::operator==(const BlendStateTarget& lhs, const BlendStateTarget& rhs) noexcept
{
    return lhs.IsEnable() == rhs.IsEnable() &&
           lhs.GetSourceColor() == rhs.GetSourceColor() &&
           lhs.GetDestinationColor() == rhs.GetDestinationColor() &&
           lhs.GetOperationColor() == rhs.GetOperationColor() &&
           lhs.GetSourceAlpha() == rhs.GetSourceAlpha() &&
           lhs.GetDestinationAlpha() == rhs.GetDestinationAlpha() &&
           lhs.GetOperationAlpha() == rhs.GetOperationAlpha() &&
           lhs.GetMask() == rhs.GetMask();
}
