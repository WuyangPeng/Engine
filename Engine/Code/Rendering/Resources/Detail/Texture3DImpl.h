///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/31 11:44)

#ifndef RENDERING_RESOURCES_TEXTURE_3D_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_3D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureImpl.h"
#include "Rendering/DataTypes/DataTypesFwd.h"
#include "Rendering/Resources/TextureLevelData.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Texture3DImpl : public TextureImpl
    {
    public:
        using ClassType = Texture3DImpl;
        using ParentType = TextureImpl;

    public:
        explicit Texture3DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);
        Texture3DImpl(TextureFormat format, int dimension0, int dimension1, int dimension2, int numLevels, BufferUsage usage = BufferUsage::Texture);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��ȡ���㼶��mipmap������ά�ȡ�
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD int GetThickness() const;

        // ������������
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
        using TextureLevelData = TextureLevelData<3>;

    private:
        void ResetDimension(int dimension0, int dimension1, int dimension2);
        void DoGenerateMipmaps() override;
        void ComputeNumLevelBytes() override;
        void VerifyNumLevels() override;
        void GenerateNextMipmap(int width, int height, int thickness, const char* texels, int widthNext, int heightNext, int thicknessNext, char* texelsNext);
        NODISCARD int CalculateNumLevelBytes(int dimension0, int dimension1, int dimension2);

        void LoadLevelData(CoreTools::BufferSource& source) override;
        void SaveLevelData(CoreTools::BufferTarget& target) const override;
        NODISCARD int GetLevelDataStreamingSize() const noexcept override;

        void SaveLevelDataToFile(WriteFileManager& outFile) const override;
        void LoadLevelDataFromFile(ReadFileManager& inFile) override;

    private:
        TextureLevelData textureLevelData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_3D_IMPL_H
