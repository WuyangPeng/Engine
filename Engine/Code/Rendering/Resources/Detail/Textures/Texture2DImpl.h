/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:51)

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
        explicit Texture2DImpl(CoreTools::DisableNotThrow disableNotThrow);
        Texture2DImpl(DataFormatType format, int width, int height, bool hasMipMaps);
        Texture2DImpl(int numItems, DataFormatType format, int width, int height, bool hasMipMaps);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetNumItems() const noexcept override;

        // ��ȡ���㼶��mipmap������ά�ȡ�
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;

        // ������������

        NODISCARD int GetDimension(int index) const override;

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
        using TextureLevelDataType = TextureLevelData<2>;

    private:
        void LoadLevelData(BufferSource& source) override;
        void SaveLevelData(BufferTarget& target) const override;
        NODISCARD int GetLevelDataStreamingSize() const override;

    private:
        TextureLevelDataType textureLevelData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_1D_IMPL_H
