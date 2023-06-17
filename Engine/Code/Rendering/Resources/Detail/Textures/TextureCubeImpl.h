///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:23)

#ifndef RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/Resources/Flags/CubeFaceType.h"
#include "Rendering/Resources/Textures/TextureLevelData.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureCubeImpl : public TextureImpl
    {
    public:
        using ClassType = TextureCubeImpl;
        using ParentType = TextureImpl;

    public:
        explicit TextureCubeImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        TextureCubeImpl(DataFormatType format, int length, bool hasMipmaps);
        TextureCubeImpl(int numCubes, DataFormatType format, int length, bool hasMipmaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumItems() const noexcept override;

        NODISCARD int GetDimension(int index) const override;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int level, int index) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetLevelOffset(int item, int level) const override;

        NODISCARD bool HasMipmaps() const noexcept override;

        void AutogenerateMipmaps() noexcept override;
        NODISCARD bool WantAutogenerateMipmaps() const noexcept override;

        NODISCARD int GetNumSubresources() const noexcept override;
        NODISCARD int GetIndex(int item, int level) const override;

    private:
        using FloatColour = Colour<float>;
        using TextureLevelData = TextureLevelData<2>;

        static constexpr auto cubeFaceCount = System::EnumCastUnderlying(CubeFaceType::Count);

    private:
        void LoadLevelData(CoreTools::BufferSource& source) override;
        void SaveLevelData(CoreTools::BufferTarget& target) const override;
        NODISCARD int GetLevelDataStreamingSize() const override;

        void SaveLevelDataToFile(WriteFileManager& outFile) const override;
        void LoadLevelDataFromFile(ReadFileManager& inFile) override;

        void SaveBaseToFile(WriteFileManager& outFile) const override;

    private:
        TextureLevelData textureLevelData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H
