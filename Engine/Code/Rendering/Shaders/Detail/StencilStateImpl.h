///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:41)

#ifndef RENDERING_SHADERS_STENCIL_STATE_IMPL_H
#define RENDERING_SHADERS_STENCIL_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/Flags/StencilStateFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE StencilStateImpl
    {
    public:
        using ClassType = StencilStateImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using CompareMode = StencilStateFlags::CompareMode;
        using OperationType = StencilStateFlags::OperationType;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        StencilStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsEnabled() const noexcept;
        NODISCARD CompareMode GetCompare() const noexcept;
        NODISCARD uint32_t GetReference() const noexcept;
        NODISCARD uint32_t GetMask() const noexcept;
        NODISCARD uint32_t GetWriteMask() const noexcept;
        NODISCARD OperationType GetOnFail() const noexcept;
        NODISCARD OperationType GetOnZFail() const noexcept;
        NODISCARD OperationType GetOnZPass() const noexcept;

        void SetEnabled(bool enabled) noexcept;
        void SetCompare(CompareMode compare) noexcept;
        void SetReference(uint32_t reference) noexcept;
        void SetMask(uint32_t mask) noexcept;
        void SetWriteMask(uint32_t writeMask) noexcept;
        void SetOnFail(OperationType onFail) noexcept;
        void SetOnZFail(OperationType onZFail) noexcept;
        void SetOnZPass(OperationType onZPass) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        bool enabledState;  // 默认: false
        CompareMode compareState;  // 默认: CompareMode::Never
        uint32_t referenceState;  // 默认: 0
        uint32_t maskState;  // 默认: UINT_MAX (0xFFFFFFFF)
        uint32_t writeMaskState;  // 默认: UINT_MAX (0xFFFFFFFF)
        OperationType onFailState;  // 默认: OperationType::Keep
        OperationType onZFailState;  // 默认: OperationType::Keep
        OperationType onZPassState;  // 默认: OperationType::Keep
    };
}

#endif  // RENDERING_SHADERS_STENCIL_STATE_IMPL_H
