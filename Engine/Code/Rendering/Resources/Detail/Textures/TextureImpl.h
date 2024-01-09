/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:52)

#ifndef RENDERING_RESOURCES_TEXTURE_IMPL_H
#define RENDERING_RESOURCES_TEXTURE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "Rendering/Resources/Detail/Textures/TextureData.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureImpl
    {
    public:
        using ClassType = TextureImpl;

        using TextureImplSharedPtr = std::shared_ptr<ClassType>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

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
        NODISCARD virtual int GetDimension(int level, int index) const = 0;
        NODISCARD virtual int GetNumLevelBytes(int level) const = 0;
        NODISCARD virtual int GetLevelOffset(int item, int level) const = 0;

        NODISCARD virtual bool HasMipMaps() const noexcept = 0;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        void virtual AutoGenerateMipMaps() noexcept = 0;
        NODISCARD virtual bool WantAutoGenerateMipMaps() const noexcept = 0;

        NODISCARD virtual int GetNumSubResources() const noexcept = 0;
        NODISCARD virtual int GetIndex(int item, int level) const = 0;

        NODISCARD static int GetTotalElements(int numItems, int dim0, int dim1, int dim2, bool hasMipMaps);

    protected:
        NODISCARD static int GetNumLevels(int dim0, int dim1, int dim2, bool hasMipMaps);

    private:
        virtual void LoadLevelData(BufferSource& source) = 0;
        virtual void SaveLevelData(BufferTarget& target) const = 0;
        NODISCARD virtual int GetLevelDataStreamingSize() const = 0;

    private:
        // 成员的值通过构造函数传递。
        TextureData textureData;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_IMPL_H
