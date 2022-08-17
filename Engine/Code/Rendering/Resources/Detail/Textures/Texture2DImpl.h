///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/15 14:51)

#ifndef RENDERING_RESOURCES_TEXTURE_2D_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_2D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/Resources/Textures/TextureLevelData.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Texture2DImpl : public TextureImpl
    {
    public:
        using ClassType = Texture2DImpl;
        using ParentType = TextureImpl;

    public:
        explicit Texture2DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        Texture2DImpl(DataFormatType format, int width, int height, bool hasMipmaps);
        Texture2DImpl(int numItems, DataFormatType format, int width, int height, bool hasMipmaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumItems() const noexcept override;

        // 获取第零级别mipmap产生的维度。
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        // 访问纹理数据

        NODISCARD int GetDimension(int index) const override;

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

#endif  // RENDERING_RESOURCES_TEXTURE_1D_IMPL_H
