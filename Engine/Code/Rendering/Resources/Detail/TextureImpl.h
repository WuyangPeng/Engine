///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 22:52)

#ifndef RENDERING_RESOURCES_TEXTURE_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "TextureBuffer.h"
#include "TextureData.h"
#include "TextureUserField.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureImpl
    {
    public:
        using ClassType = TextureImpl;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;
        using TextureImplSharedPtr = std::shared_ptr<ClassType>;

    public:
        TextureImpl(TextureFormat format, TextureFlags type, BufferUsage usage, int numLevels);
        virtual ~TextureImpl() noexcept = default;
        TextureImpl(const TextureImpl& rhs) = default;
        TextureImpl& operator=(const TextureImpl& rhs) = default;
        TextureImpl(TextureImpl&& rhs) noexcept = default;
        TextureImpl& operator=(TextureImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD TextureFormat GetFormat() const noexcept;
        NODISCARD TextureFlags GetTextureType() const noexcept;
        NODISCARD BufferUsage GetUsage() const noexcept;
        NODISCARD int GetNumLevels() const noexcept;

        NODISCARD virtual int GetNumDimensions() const = 0;
        NODISCARD virtual int GetDimension(int index, int level) const = 0;
        NODISCARD virtual int GetNumLevelBytes(int level) const = 0;
        NODISCARD virtual int GetNumTotalBytes() const = 0;
        NODISCARD virtual int GetLevelOffset(int level) const = 0;

        void GenerateMipmaps();
        NODISCARD bool HasMipmaps() const;

        NODISCARD int GetPixelSize() const;
        NODISCARD static int GetPixelSize(TextureFormat format);
        NODISCARD bool IsCompressed() const noexcept;
        NODISCARD bool IsMipmapable() const;

        // ����ϵͳ�ڴ������һ���������ֽ���ͨ��GetNumTotalBytes()��ѯ��
        // ��ѯϵͳ���ڴ淢����Texture1D��Texture2D��Texture3D��TextureCube��
        // GetReadOnlyData()������Ӧ�÷���ֻ�����ݡ�
        // ��Ҫת������Ϊ��char*��ȥд,��Ⱦ������֪�������ѱ��޸ġ�
        NODISCARD const char* GetReadOnlyData() const;

        // �û��ֶΡ���Щ���������ڴ洢�ض���Ӧ�ó����δ֪�����ࡣ
        void SetUserField(int index, int userField);
        NODISCARD int GetUserField(int index) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        NODISCARD static int CalculateNumDimensions(TextureFlags type);
        NODISCARD static int CalculateItemSize(TextureFormat format);

    protected:
        NODISCARD char* GetWriteData();
        void SetNumLevels(int numLevels) noexcept;
        void ExpandFileBufferSizeOnCube();
        void ResetTextureBufferNum();

        NODISCARD virtual int GetMaxLevels() const = 0;

    private:
        virtual void LoadLevelData(CoreTools::BufferSource& source) = 0;
        virtual void SaveLevelData(CoreTools::BufferTarget& target) const = 0;
        NODISCARD virtual int GetLevelDataStreamingSize() const = 0;

        virtual void SaveLevelDataToFile(WriteFileManager& outFile) const = 0;
        virtual void LoadLevelDataFromFile(ReadFileManager& inFile) = 0;

        void RecomputationLevelBytes();

        virtual void ExpandFileBufferSize();

        virtual void DoGenerateMipmaps() = 0;
        virtual void ComputeNumLevelBytes() = 0;
        virtual void VerifyNumLevels() = 0;

    private:
        // ��Ա��ֵͨ�����캯�����ݡ�
        TextureData textureData;

        // �û��ֶ����洢�ض���Ӧ�ó�������ݡ�
        TextureUserField textureUserField;

        // �����ϵͳ�ڴ渴�ƣ�ʹ���ڼ��غ͸�����Ƶ�ڴ�
        TextureBuffer data;

        static std::array<int, System::EnumCastUnderlying(TextureFlags::Quantity)> numDimensions;
        static std::array<int, System::EnumCastUnderlying(TextureFormat::Quantity)> pixelSize;
        static std::array<bool, System::EnumCastUnderlying(TextureFormat::Quantity)> mipmapable;
        static std::array<int, System::EnumCastUnderlying(TextureFormat::Quantity)> itemSize;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_IMPL_H
