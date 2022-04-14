///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 11:14)

#ifndef RENDERING_RESOURCES_TEXTURE_2D_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_2D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/Resources/TextureLevelData.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Texture2DImpl : public TextureImpl
    {
    public:
        using ClassType = Texture2DImpl;
        using ParentType = TextureImpl;

    public:
        explicit Texture2DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        Texture2DImpl(TextureFormat format, int dimension0, int dimension1, int numLevels, BufferUsage usage = BufferUsage::Texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 获取第零级别mipmap产生的维度。
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        // 访问纹理数据
        NODISCARD char* GetTextureData(int level);
        NODISCARD const char* GetTextureData(int level) const;

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
        void ResetDimension(int dimension0, int dimension1);
        void DoGenerateMipmaps() override;
        void ComputeNumLevelBytes() override;
        void VerifyNumLevels() override;
        void GenerateNextMipmap(int width, int height, const char* texels, int widthNext, int heightNext, char* texelsNext);
        NODISCARD int CalculateNumLevelBytes(int dimension0, int dimension1);

        void LoadLevelData(CoreTools::BufferSource& source) override;
        void SaveLevelData(CoreTools::BufferTarget& target) const override;
        NODISCARD int GetLevelDataStreamingSize() const noexcept override;

        void SaveLevelDataToFile(WriteFileManager& outFile) const override;
        void LoadLevelDataFromFile(ReadFileManager& inFile) override;

    private:
        TextureLevelData textureLevelData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_1D_IMPL_H
