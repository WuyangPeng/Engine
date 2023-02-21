///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 18:43)

#include "Rendering/RenderingExport.h"

#include "WireStateImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::WireStateImpl::WireStateImpl() noexcept
    : enabled{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, WireStateImpl)

void Rendering::WireStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    enabled = source.ReadBool();
}

void Rendering::WireStateImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(enabled);
}

int Rendering::WireStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto size = CoreTools::GetStreamSize(enabled);

    return size;
}

bool Rendering::WireStateImpl::IsEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enabled;
}

void Rendering::WireStateImpl::SetEnabled(bool aEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enabled = aEnabled;
}

void Rendering::WireStateImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto result = (enabled ? 1 : 0);

    manager.Write(sizeof(int32_t), &result);
}

void Rendering::WireStateImpl::LoadState(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    int32_t result{ 0 };
    manager.Read(sizeof(int32_t), &result);

    enabled = (result == 1) ? true : false;
}
