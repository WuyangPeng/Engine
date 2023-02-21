///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 10:57)

#ifndef RENDERING_SHADERS_ALPHA_STATE_H
#define RENDERING_SHADERS_ALPHA_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/AlphaStateFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(AlphaState, AlphaStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE AlphaState : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(AlphaState);
        using ParentType = Object;
        using Colour = Colour<float>;
        using SourceBlendMode = AlphaStateFlags::SourceBlendMode;
        using DestinationBlendMode = AlphaStateFlags::DestinationBlendMode;
        using CompareMode = AlphaStateFlags::CompareMode;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit AlphaState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(AlphaState);

        NODISCARD bool IsBlendEnabled() const noexcept;
        NODISCARD SourceBlendMode GetSourceBlend() const noexcept;
        NODISCARD DestinationBlendMode GetDestinationBlend() const noexcept;
        NODISCARD bool IsCompareEnabled() const noexcept;
        NODISCARD CompareMode GetCompare() const noexcept;
        NODISCARD float GetReference() const noexcept;
        NODISCARD Colour GetConstantColor() const noexcept;

        void SetBlendEnabled(bool blendEnabled) noexcept;
        void SetSourceBlend(SourceBlendMode mode) noexcept;
        void SetDestinationBlend(DestinationBlendMode mode) noexcept;
        void SetCompareEnabled(bool compareEnabled) noexcept;
        void SetCompare(CompareMode mode) noexcept;
        void SetReference(float reference) noexcept;
        void SetConstantColor(const Colour& value) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(AlphaState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(AlphaState);
}

#endif  // RENDERING_SHADERS_ALPHA_STATE_H
