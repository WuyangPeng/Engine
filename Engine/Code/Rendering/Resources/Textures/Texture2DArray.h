///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_TEXTURE_2D_ARRAY_H
#define RENDERING_RESOURCES_TEXTURE_2D_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "TextureArray.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Texture2DArray, Texture2DImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture2DArray : public TextureArray
    {
    public:
        using Texture2DArrayImpl = Texture2DImpl;
        COPY_UNSHARED_TYPE_DECLARE(Texture2DArray);
        using ParentType = TextureArray;
        using Texture2DSharedPtr = std::shared_ptr<ClassType>;
        using ConstTexture2DSharedPtr = std::shared_ptr<const ClassType>;

    public:
        Texture2DArray(int numItems, DataFormatType format, int width, int height, bool hasMipmaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2DArray);

        NODISCARD int GetNumItems() const noexcept override;

        NODISCARD int GetDimension(int index) const override;

        NODISCARD DataFormatType GetFormat() const noexcept override;
        NODISCARD int GetNumLevels() const noexcept override;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int index, int level) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetLevelOffset(int item, int level) const override;

        void SaveToFile(WriteFileManager& outFile) const override;
        void ReadFromFile(ReadFileManager& inFile) override;

        NODISCARD bool HasMipmaps() const noexcept override;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        void AutogenerateMipmaps() noexcept override;
        NODISCARD bool WantAutogenerateMipmaps() const noexcept override;

        NODISCARD int GetNumSubresources() const noexcept override;
        NODISCARD int GetIndex(int item, int level) const override;

        NODISCARD int GetNumElementsFor(int level) const override;

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture2DArray);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture2DArray);
}

#endif  // RENDERING_RESOURCES_TEXTURE_2D_ARRAY_H
