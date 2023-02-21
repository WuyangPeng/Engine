///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/16 10:19)

#ifndef RENDERING_RESOURCES_TEXTURE_1D_H
#define RENDERING_RESOURCES_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "TextureSingle.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Texture1D, Texture1DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture1D : public TextureSingle
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Texture1D);
        using ParentType = TextureSingle;

    public:
        Texture1D(DataFormatType format, int length, bool hasMipmaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture1D);

        NODISCARD int GetNumItems() const noexcept override;

        NODISCARD int GetDimension(int index) const override;

        NODISCARD DataFormatType GetFormat() const noexcept override;
        NODISCARD int GetNumLevels() const noexcept override;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int index, int level) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetLevelOffset(int item, int level) const override;

        NODISCARD bool HasMipmaps() const noexcept override;

        NODISCARD int GetNumElementsFor(int level) const override;

        void SaveToFile(WriteFileManager& outFile) const override;
        void ReadFromFile(ReadFileManager& inFile) override;

        NODISCARD int GetLength() const;

        void AutogenerateMipmaps() noexcept override;
        NODISCARD bool WantAutogenerateMipmaps() const noexcept override;

        NODISCARD int GetNumSubresources() const noexcept override;
        NODISCARD int GetIndex(int item, int level) const override;

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture1D);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture1D);
}

#endif  // RENDERING_RESOURCES_TEXTURE_1D_H
