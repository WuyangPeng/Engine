///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 15:30)

#include "Rendering/RenderingExport.h"

#include "StencilStateImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::StencilStateImpl::StencilStateImpl() noexcept
    : enabledState{ false },
      compareState{ StencilStateFlags::CompareMode::Never },
      referenceState{ 0 },
      maskState{ 0xFFFFFFFF },
      writeMaskState{ 0xFFFFFFFF },
      onFailState{ StencilStateFlags::OperationType::Keep },
      onZFailState{ StencilStateFlags::OperationType::Keep },
      onZPassState{ StencilStateFlags::OperationType::Keep }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, StencilStateImpl)

void Rendering::StencilStateImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    enabledState = source.ReadBool();
    source.ReadEnum(compareState);
    source.Read(referenceState);
    source.Read(maskState);
    source.Read(writeMaskState);
    source.ReadEnum(onFailState);
    source.ReadEnum(onZFailState);
    source.ReadEnum(onZPassState);
}

void Rendering::StencilStateImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(enabledState);
    target.WriteEnum(compareState);
    target.Write(referenceState);
    target.Write(maskState);
    target.Write(writeMaskState);
    target.WriteEnum(onFailState);
    target.WriteEnum(onZFailState);
    target.WriteEnum(onZPassState);
}

int Rendering::StencilStateImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(enabledState);

    size += CORE_TOOLS_STREAM_SIZE(compareState);
    size += CORE_TOOLS_STREAM_SIZE(referenceState);
    size += CORE_TOOLS_STREAM_SIZE(maskState);
    size += CORE_TOOLS_STREAM_SIZE(writeMaskState);
    size += CORE_TOOLS_STREAM_SIZE(onFailState);
    size += CORE_TOOLS_STREAM_SIZE(onZFailState);
    size += CORE_TOOLS_STREAM_SIZE(onZPassState);

    return size;
}

bool Rendering::StencilStateImpl::IsEnabled() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enabledState;
}

void Rendering::StencilStateImpl::SetEnabled(bool enabled) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enabledState = enabled;
}

Rendering::StencilStateImpl::CompareMode Rendering::StencilStateImpl::GetCompare() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return compareState;
}

void Rendering::StencilStateImpl::SetCompare(CompareMode compare) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    compareState = compare;
}

uint32_t Rendering::StencilStateImpl::GetReference() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referenceState;
}

void Rendering::StencilStateImpl::SetReference(uint32_t reference) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    referenceState = reference;
}

uint32_t Rendering::StencilStateImpl::GetMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return maskState;
}

void Rendering::StencilStateImpl::SetMask(uint32_t mask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    maskState = mask;
}

uint32_t Rendering::StencilStateImpl::GetWriteMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return writeMaskState;
}

void Rendering::StencilStateImpl::SetWriteMask(uint32_t writeMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    writeMaskState = writeMask;
}

Rendering::StencilStateImpl::OperationType Rendering::StencilStateImpl::GetOnFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return onFailState;
}

void Rendering::StencilStateImpl::SetOnFail(OperationType onFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    onFailState = onFail;
}

Rendering::StencilStateImpl::OperationType Rendering::StencilStateImpl::GetOnZFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return onZFailState;
}

void Rendering::StencilStateImpl::SetOnZFail(OperationType onZFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    onZFailState = onZFail;
}

Rendering::StencilStateImpl::OperationType Rendering::StencilStateImpl::GetOnZPass() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return onZPassState;
}

void Rendering::StencilStateImpl::SetOnZPass(OperationType onZPass) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    onZPassState = onZPass;
}

void Rendering::StencilStateImpl::SaveState(WriteFileManager& manager) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto enabled = (enabledState ? 1 : 0);

    manager.Write(sizeof(int32_t), &enabled);
    manager.Write(sizeof(CompareMode), &compareState);
    manager.Write(sizeof(uint32_t), &referenceState);
    manager.Write(sizeof(uint32_t), &maskState);
    manager.Write(sizeof(uint32_t), &writeMaskState);
    manager.Write(sizeof(OperationType), &onFailState);
    manager.Write(sizeof(OperationType), &onZFailState);
    manager.Write(sizeof(OperationType), &onZPassState);
}

void Rendering::StencilStateImpl::LoadState(ReadFileManager& manager)
{
    RENDERING_CLASS_IS_VALID_9;

    int32_t enabled{ 0 };

    manager.Read(sizeof(int32_t), &enabled);
    manager.Read(sizeof(CompareMode), &compareState);
    manager.Read(sizeof(uint32_t), &referenceState);
    manager.Read(sizeof(uint32_t), &maskState);
    manager.Read(sizeof(uint32_t), &writeMaskState);
    manager.Read(sizeof(OperationType), &onFailState);
    manager.Read(sizeof(OperationType), &onZFailState);
    manager.Read(sizeof(OperationType), &onZPassState);

    enabledState = (enabled == 1) ? true : false;
}
