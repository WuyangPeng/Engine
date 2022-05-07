///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 17:09)

#include "Rendering/RenderingExport.h"

#include "DepthStateImpl.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::DepthStateImpl::DepthStateImpl() noexcept
    : enabled{ true }, writable{ true }, compare{ DepthStateFlags::CompareMode::LessEqual }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, DepthStateImpl)

void Rendering::DepthStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    enabled = source.ReadBool();
    writable = source.ReadBool();
    source.ReadEnum(compare);
}

void Rendering::DepthStateImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(enabled);
    target.Write(writable);
    target.WriteEnum(compare);
}

int Rendering::DepthStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(enabled);
    size += CORE_TOOLS_STREAM_SIZE(writable);
    size += CORE_TOOLS_STREAM_SIZE(compare);

    return size;
}

bool Rendering::DepthStateImpl::IsEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enabled;
}

bool Rendering::DepthStateImpl::IsWritable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return writable;
}

Rendering::DepthStateImpl::CompareMode Rendering::DepthStateImpl::GetCompare() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return compare;
}

void Rendering::DepthStateImpl::SetEnabled(bool aEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enabled = aEnabled;
}

void Rendering::DepthStateImpl::SetWritable(bool aWritable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    writable = aWritable;
}

void Rendering::DepthStateImpl::SetCompare(CompareMode aCompare) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    compare = aCompare;
}

void Rendering::DepthStateImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto enabledWrite = enabled ? 1 : 0;
    const auto writableWrite = writable ? 1 : 0;

    manager.Write(sizeof(int32_t), &enabledWrite);
    manager.Write(sizeof(int32_t), &writableWrite);
    manager.Write(sizeof(CompareMode), &compare);
}

void Rendering::DepthStateImpl::LoadState(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    int32_t enabledRead{ 0 };
    int32_t writableRead{ 0 };

    manager.Read(sizeof(int32_t), &enabledRead);
    manager.Read(sizeof(int32_t), &writableRead);
    manager.Read(sizeof(CompareMode), &compare);

    enabled = (enabledRead == 1) ? true : false;
    writable = (writableRead == 1) ? true : false;
}
