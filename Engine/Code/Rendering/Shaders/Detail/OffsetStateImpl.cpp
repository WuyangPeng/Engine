///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 18:09)

#include "Rendering/RenderingExport.h"

#include "OffsetStateImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::OffsetStateImpl::OffsetStateImpl() noexcept
    : fillEnabled{ false }, lineEnabled{ false }, pointEnabled{ false }, scale{ 0.0f }, bias{ 0.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OffsetStateImpl)

void Rendering::OffsetStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    fillEnabled = source.ReadBool();
    lineEnabled = source.ReadBool();
    pointEnabled = source.ReadBool();
    source.Read(scale);
    source.Read(bias);
}

void Rendering::OffsetStateImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(fillEnabled);
    target.Write(lineEnabled);
    target.Write(pointEnabled);
    target.Write(scale);
    target.Write(bias);
}

int Rendering::OffsetStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(fillEnabled);
    size += CORE_TOOLS_STREAM_SIZE(lineEnabled);
    size += CORE_TOOLS_STREAM_SIZE(pointEnabled);
    size += CORE_TOOLS_STREAM_SIZE(scale);
    size += CORE_TOOLS_STREAM_SIZE(bias);

    return size;
}

bool Rendering::OffsetStateImpl::IsFillEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fillEnabled;
}

bool Rendering::OffsetStateImpl::IsLineEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return lineEnabled;
}

bool Rendering::OffsetStateImpl::IsPointEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pointEnabled;
}

float Rendering::OffsetStateImpl::GetScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return scale;
}

float Rendering::OffsetStateImpl::GetBias() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bias;
}

void Rendering::OffsetStateImpl::SetFillEnabled(bool aFillEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    fillEnabled = aFillEnabled;
}

void Rendering::OffsetStateImpl::SetLineEnabled(bool aLineEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    lineEnabled = aLineEnabled;
}

void Rendering::OffsetStateImpl::SetPointEnabled(bool aPointEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    pointEnabled = aPointEnabled;
}

void Rendering::OffsetStateImpl::SetScale(float aScale) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    scale = aScale;
}

void Rendering::OffsetStateImpl::SetBias(float aBias) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bias = aBias;
}

void Rendering::OffsetStateImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto fillEnabledWrite = (fillEnabled ? 1 : 0);
    const auto lineEnabledWrite = (lineEnabled ? 1 : 0);
    const auto pointEnabledWrite = (pointEnabled ? 1 : 0);

    manager.Write(sizeof(int32_t), &fillEnabledWrite);
    manager.Write(sizeof(int32_t), &lineEnabledWrite);
    manager.Write(sizeof(int32_t), &pointEnabledWrite);
    manager.Write(sizeof(float), &scale);
    manager.Write(sizeof(float), &bias);
}

void Rendering::OffsetStateImpl::LoadState(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    int32_t fillEnabledRead{ 0 };
    int32_t lineEnabledRead{ 0 };
    int32_t pointEnabledRead{ 0 };

    manager.Read(sizeof(int32_t), &fillEnabledRead);
    manager.Read(sizeof(int32_t), &lineEnabledRead);
    manager.Read(sizeof(int32_t), &pointEnabledRead);
    manager.Read(sizeof(float), &scale);
    manager.Read(sizeof(float), &bias);

    fillEnabled = (fillEnabledRead == 1 ? true : false);
    lineEnabled = (lineEnabledRead == 1 ? true : false);
    pointEnabled = (pointEnabledRead == 1 ? true : false);
}
