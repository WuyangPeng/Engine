// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:14)

#ifndef RENDERING_SHADERS_ALPHA_STATE_H
#define RENDERING_SHADERS_ALPHA_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/AlphaStateFlags.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_EXPORT_SHARED_PTR(AlphaStateImpl);

namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE AlphaState : public CoreTools::Object
    {
    public:
        OLD_COPY_UNSHARE_CLASSES_TYPE_DECLARE(AlphaState);
        using ParentType = Object;
        using Colour = Colour<float>;
        using SourceBlendMode = AlphaStateFlags::SourceBlendMode;
        using DestinationBlendMode = AlphaStateFlags::DestinationBlendMode;
        using CompareMode = AlphaStateFlags::CompareMode;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        AlphaState();
        ~AlphaState();

        #include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
        AlphaState(AlphaState&&) noexcept = default;
        AlphaState& operator=(AlphaState&&) noexcept = default;
          #include STSTEM_WARNING_POP

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(AlphaState);

        bool IsBlendEnabled() const;
        SourceBlendMode GetSourceBlend() const;
        DestinationBlendMode GetDestinationBlend() const;
        bool IsCompareEnabled() const;
        CompareMode GetCompare() const;
        float GetReference() const;
        const Colour GetConstantColor() const;

        void SetBlendEnabled(bool blendEnabled);
        void SetSourceBlend(SourceBlendMode mode);
        void SetDestinationBlend(DestinationBlendMode mode);
        void SetCompareEnabled(bool compareEnabled);
        void SetCompare(CompareMode mode);
        void SetReference(float reference);
        void SetConstantColor(const Colour& value);

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
          ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        IMPL_TYPE_DECLARE(AlphaState);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(AlphaState);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, AlphaState);
}

#endif  // RENDERING_SHADERS_ALPHA_STATE_H
