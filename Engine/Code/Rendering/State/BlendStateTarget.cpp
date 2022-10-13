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
      srcColor{ BlendStateMode::One },
      dstColor{ BlendStateMode::Zero },
      opColor{ BlendStateOperation::Add },
      srcAlpha{ BlendStateMode::One },
      dstAlpha{ BlendStateMode::Zero },
      opAlpha{ BlendStateOperation::Add },
      mask{ BlendStateColorWrite::EnableAll }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BlendStateTarget)

bool Rendering::BlendStateTarget::GetEnable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enable;
}

void Rendering::BlendStateTarget::SetEnable(bool aEnable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enable = aEnable;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetSrcColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return srcColor;
}

void Rendering::BlendStateTarget::SetSrcColor(BlendStateMode aSrcColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    srcColor = aSrcColor;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetDstColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dstColor;
}

void Rendering::BlendStateTarget::SetDstColor(BlendStateMode aDstColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    dstColor = aDstColor;
}

Rendering::BlendStateOperation Rendering::BlendStateTarget::GetOpColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return opColor;
}

void Rendering::BlendStateTarget::SetOpColor(BlendStateOperation aOpColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    opColor = aOpColor;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetSrcAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return srcAlpha;
}

void Rendering::BlendStateTarget::SetSrcAlpha(BlendStateMode aSrcAlpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    srcAlpha = aSrcAlpha;
}

Rendering::BlendStateMode Rendering::BlendStateTarget::GetDstAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dstAlpha;
}

void Rendering::BlendStateTarget::SetDstAlpha(BlendStateMode aDstAlpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    dstAlpha = aDstAlpha;
}

Rendering::BlendStateOperation Rendering::BlendStateTarget::GetOpAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return opAlpha;
}

void Rendering::BlendStateTarget::SetOpAlpha(BlendStateOperation aOpAlpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    opAlpha = aOpAlpha;
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

void Rendering::BlendStateTarget::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    enable = source.ReadBool();
    source.ReadEnum(srcColor);
    source.ReadEnum(dstColor);
    source.ReadEnum(opColor);
    source.ReadEnum(srcAlpha);
    source.ReadEnum(dstAlpha);
    source.ReadEnum(opAlpha);
    source.ReadEnum(mask);
}

void Rendering::BlendStateTarget::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(enable);
    target.WriteEnum(srcColor);
    target.WriteEnum(dstColor);
    target.WriteEnum(opColor);
    target.WriteEnum(srcAlpha);
    target.WriteEnum(dstAlpha);
    target.WriteEnum(opAlpha);
    target.WriteEnum(mask);
}

int Rendering::BlendStateTarget::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(enable);

    size += CORE_TOOLS_STREAM_SIZE(srcColor);
    size += CORE_TOOLS_STREAM_SIZE(dstColor);
    size += CORE_TOOLS_STREAM_SIZE(opColor);
    size += CORE_TOOLS_STREAM_SIZE(srcAlpha);
    size += CORE_TOOLS_STREAM_SIZE(dstAlpha);
    size += CORE_TOOLS_STREAM_SIZE(opAlpha);
    size += CORE_TOOLS_STREAM_SIZE(mask);

    return size;
}