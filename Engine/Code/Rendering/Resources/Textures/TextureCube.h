///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/16 14:11)

#ifndef RENDERING_RESOURCES_TEXTURE_CUBE_H
#define RENDERING_RESOURCES_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "TextureArray.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TextureCube, TextureCubeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureCube : public TextureArray
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(TextureCube);
        using ParentType = TextureArray;

    public:
        TextureCube(DataFormatType format, int length, bool hasMipmaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureCube);

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

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(TextureCube);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureCube);
}

#endif  // RENDERING_RESOURCES_TEXTURE_CUBE_H
