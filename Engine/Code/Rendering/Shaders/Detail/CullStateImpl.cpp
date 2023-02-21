///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 17:04)

#include "Rendering/RenderingExport.h"

#include "CullStateImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::CullStateImpl::CullStateImpl() noexcept
    : enabled{ true }, ccwOrder{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CullStateImpl)

bool Rendering::CullStateImpl::IsEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enabled;
}

void Rendering::CullStateImpl::SetEnabled(bool aEnabled) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enabled = aEnabled;
}

bool Rendering::CullStateImpl::IsCCWOrder() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ccwOrder;
}

void Rendering::CullStateImpl::SetCCWOrder(bool aCCWOrder) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    ccwOrder = aCCWOrder;
}

void Rendering::CullStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    enabled = source.ReadBool();
    ccwOrder = source.ReadBool();
}

void Rendering::CullStateImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(enabled);
    target.Write(ccwOrder);
}

int Rendering::CullStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(enabled);
    size += CoreTools::GetStreamSize(ccwOrder);

    return size;
}

void Rendering::CullStateImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto enabledWrite = enabled ? 1 : 0;
    const auto ccwOrderWrite = ccwOrder ? 1 : 0;

    manager.Write(sizeof(int32_t), &enabledWrite);
    manager.Write(sizeof(int32_t), &ccwOrderWrite);
}

void Rendering::CullStateImpl::LoadState(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    int enabledRead{ 0 };
    int ccwOrderRead{ 0 };
    manager.Read(sizeof(int32_t), &enabledRead);
    manager.Read(sizeof(int32_t), &ccwOrderRead);

    enabled = (enabledRead == 1) ? true : false;
    ccwOrder = (ccwOrderRead == 1) ? true : false;
}
