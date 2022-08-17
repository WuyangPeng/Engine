///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/14 22:40)

#ifndef RENDERING_RESOURCES_TEXTURE_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Detail/Textures/TextureData.h"
#include "Rendering/Resources/ResourcesFwd.h"

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
        TextureImpl(DataFormatType format, int numLevels) noexcept;
        virtual ~TextureImpl() noexcept = default;
        TextureImpl(const TextureImpl& rhs) = default;
        TextureImpl& operator=(const TextureImpl& rhs) = default;
        TextureImpl(TextureImpl&& rhs) noexcept = default;
        TextureImpl& operator=(TextureImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetNumItems() const noexcept = 0;

        NODISCARD DataFormatType GetFormat() const noexcept;
        NODISCARD int GetNumLevels() const noexcept;

        NODISCARD virtual int GetNumDimensions() const = 0;
        NODISCARD virtual int GetDimension(int index) const = 0;
        NODISCARD virtual int GetDimension(int index, int level) const = 0;
        NODISCARD virtual int GetNumLevelBytes(int level) const = 0;
        NODISCARD virtual int GetLevelOffset(int item, int level) const = 0;

        NODISCARD virtual bool HasMipmaps() const noexcept = 0;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

        void virtual AutogenerateMipmaps() noexcept = 0;
        NODISCARD virtual bool WantAutogenerateMipmaps() const noexcept = 0;

        NODISCARD virtual int GetNumSubresources() const noexcept = 0;
        NODISCARD virtual int GetIndex(int item, int level) const = 0;

        NODISCARD static int GetTotalElements(int numItems, int dim0, int dim1, int dim2, bool hasMipmaps);

    protected:
        NODISCARD static int GetNumLevels(int dim0, int dim1, int dim2, bool hasMipmaps);

    private:
        virtual void LoadLevelData(CoreTools::BufferSource& source) = 0;
        virtual void SaveLevelData(CoreTools::BufferTarget& target) const = 0;
        NODISCARD virtual int GetLevelDataStreamingSize() const = 0;

        virtual void SaveLevelDataToFile(WriteFileManager& outFile) const = 0;
        virtual void LoadLevelDataFromFile(ReadFileManager& inFile) = 0;

        virtual void SaveBaseToFile(WriteFileManager& outFile) const = 0;

    private:
        // 成员的值通过构造函数传递。
        TextureData textureData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_IMPL_H
