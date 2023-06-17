///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:41)

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
        bool enabledState;  // Ĭ��: false
        CompareMode compareState;  // Ĭ��: CompareMode::Never
        uint32_t referenceState;  // Ĭ��: 0
        uint32_t maskState;  // Ĭ��: UINT_MAX (0xFFFFFFFF)
        uint32_t writeMaskState;  // Ĭ��: UINT_MAX (0xFFFFFFFF)
        OperationType onFailState;  // Ĭ��: OperationType::Keep
        OperationType onZFailState;  // Ĭ��: OperationType::Keep
        OperationType onZPassState;  // Ĭ��: OperationType::Keep
    };
}

#endif  // RENDERING_SHADERS_STENCIL_STATE_IMPL_H
