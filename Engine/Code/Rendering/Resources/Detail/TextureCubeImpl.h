///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 14:08)

#ifndef RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/Resources/TextureLevelData.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureCubeImpl : public TextureImpl
    {
    public:
        using ClassType = TextureCubeImpl;
        using ParentType = TextureImpl;

    public:
        explicit TextureCubeImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        TextureCubeImpl(TextureFormat format, int dimension, int numLevels, BufferUsage usage = BufferUsage::Texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        NODISCARD char* GetTextureData(int face, int level);
        NODISCARD const char* GetTextureData(int face, int level) const;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int index, int level) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetNumTotalBytes() const noexcept override;
        NODISCARD int GetLevelOffset(int level) const override;

    protected:
        NODISCARD int GetMaxLevels() const override;

    private:
        using FloatColour = Colour<float>;
        using TextureLevelData = TextureLevelData<2>;

    private:
        void ResetDimension(int dimension);
        void DoGenerateMipmaps() override;
        void ComputeNumLevelBytes() override;
        void VerifyNumLevels() override;
        void GenerateNextMipmap(int dimension, const char* texels, int dimensionNext, char* texelsNext);
        NODISCARD int CalculateNumLevelBytes(int dimension);

        void LoadLevelData(CoreTools::BufferSource& source) override;
        void SaveLevelData(CoreTools::BufferTarget& target) const override;
        NODISCARD int GetLevelDataStreamingSize() const noexcept override;

        void SaveLevelDataToFile(WriteFileManager& outFile) const override;
        void LoadLevelDataFromFile(ReadFileManager& inFile) override;

        void ExpandFileBufferSize() override;

    private:
        TextureLevelData textureLevelData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_CUBE_IMPL_H
