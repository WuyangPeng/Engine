///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:29)

#ifndef RENDERING_SHADERS_ALPHA_STATE_IMPL_H
#define RENDERING_SHADERS_ALPHA_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/AlphaStateFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE AlphaStateImpl
    {
    public:
        using ClassType = AlphaStateImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using Colour = Colour<float>;
        using SourceBlendMode = AlphaStateFlags::SourceBlendMode;
        using DestinationBlendMode = AlphaStateFlags::DestinationBlendMode;
        using CompareMode = AlphaStateFlags::CompareMode;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        AlphaStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsBlendEnabled() const noexcept;
        NODISCARD SourceBlendMode GetSourceBlend() const noexcept;
        NODISCARD DestinationBlendMode GetDestinationBlend() const noexcept;
        NODISCARD bool IsCompareEnabled() const noexcept;
        NODISCARD CompareMode GetCompare() const noexcept;
        NODISCARD float GetReference() const noexcept;
        NODISCARD Colour GetConstantColor() const noexcept;

        void SetBlendEnabled(bool aBlendEnabled) noexcept;
        void SetSourceBlend(SourceBlendMode mode) noexcept;
        void SetDestinationBlend(DestinationBlendMode mode) noexcept;
        void SetCompareEnabled(bool aCompareEnabled) noexcept;
        void SetCompare(CompareMode mode) noexcept;
        void SetReference(float aReference) noexcept;
        void SetConstantColor(const Colour& value) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        bool blendEnabled;  // Ĭ��: false
        SourceBlendMode sourceBlend;  // Ĭ��: SourceBlendMode::SourceAlpha
        DestinationBlendMode destinationBlend;  // Ĭ��: DestinationBlendMode::OneMinusSourceAlpha
        bool compareEnabled;  // Ĭ��: false
        CompareMode compare;  // Ĭ��: CompareMode::Always
        float reference;  // Ĭ��: 0, ������[0,1]
        Colour constantColor;  // Ĭ��: (0,0,0,0)
    };
}

#endif  // RENDERING_SHADERS_ALPHA_STATE_IMPL_H
