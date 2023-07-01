///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 20:13)

#ifndef RENDERING_RESOURCES_TEXTURE_3D_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_3D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/Resources/Textures/TextureLevelData.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Texture3DImpl : public TextureImpl
    {
    public:
        using ClassType = Texture3DImpl;
        using ParentType = TextureImpl;

    public:
        explicit Texture3DImpl(CoreTools::DisableNotThrow disableNotThrow);
        Texture3DImpl(DataFormatType format, int width, int height, int thickness, bool hasMipMaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumItems() const noexcept override;

        NODISCARD int GetDimension(int index) const override;

        // 获取第零级别mipmap产生的维度。
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD int GetThickness() const;

        NODISCARD int GetNumDimensions() const noexcept override;
        NODISCARD int GetDimension(int level, int index) const override;
        NODISCARD int GetNumLevelBytes(int level) const override;
        NODISCARD int GetLevelOffset(int item, int level) const override;

        NODISCARD bool HasMipMaps() const noexcept override;

        void AutoGenerateMipMaps() noexcept override;
        NODISCARD bool WantAutoGenerateMipMaps() const noexcept override;

        NODISCARD int GetNumSubResources() const noexcept override;
        NODISCARD int GetIndex(int item, int level) const override;

    private:
        using FloatColour = Colour<float>;
        using TextureLevelData = TextureLevelData<3>;

    private:
        void LoadLevelData(BufferSource& source) override;
        void SaveLevelData(BufferTarget& target) const override;
        NODISCARD int GetLevelDataStreamingSize() const override;

        void SaveLevelDataToFile(WriteFileManager& outFile) const override;
        void LoadLevelDataFromFile(ReadFileManager& inFile) override;

        void SaveBaseToFile(WriteFileManager& outFile) const override;

    private:
        TextureLevelData textureLevelData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_3D_IMPL_H
