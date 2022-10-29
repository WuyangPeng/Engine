///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/16 14:43)

#ifndef RENDERING_RESOURCES_TEXTURE_CUBE_ARRAY_H
#define RENDERING_RESOURCES_TEXTURE_CUBE_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "TextureArray.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/Flags/CubeFaceType.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TextureCubeArray, TextureCubeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureCubeArray : public TextureArray
    {
    public:
        using TextureCubeArrayImpl = TextureCubeImpl;
        COPY_UNSHARED_TYPE_DECLARE(TextureCubeArray);
        using ParentType = TextureArray;

    public:
        TextureCubeArray(int numCubes, DataFormatType format, int length, bool hasMipmaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureCubeArray);

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

        NODISCARD int GetLength() const;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        void AutogenerateMipmaps() noexcept override;
        NODISCARD bool WantAutogenerateMipmaps() const noexcept override;

        NODISCARD int GetNumSubresources() const noexcept override;
        NODISCARD int GetIndex(int item, int level) const override;

        NODISCARD int GetNumElementsFor(int level) const override;

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD int GetNumCubes() const noexcept;

        NODISCARD int GetItemIndexFor(int cube, int face) const noexcept;
        NODISCARD int GetCubeIndexFor(int item) const noexcept;
        NODISCARD int GetFaceIndexFor(int item) const noexcept;
        NODISCARD int GetOffsetForCubeArray(int cube, int face, int level) const;

        NODISCARD ConstSpanIterator GetDataForCubeArray(int cube, int face, int level) const;
        NODISCARD SpanIterator GetDataForCubeArray(int cube, int face, int level);

        NODISCARD int GetIndex(int cube, int face, int level) const noexcept;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        static constexpr auto cubeFaceCount = System::EnumCastUnderlying(CubeFaceType::Count);

    private:
        PackageType impl;
        int numCubes;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TextureCubeArray);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureCubeArray);
}

#endif  // RENDERING_RESOURCES_TEXTURE_CUBE_ARRAY_H
