/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:54)

#ifndef RENDERING_RESOURCES_TEXTURE_H
#define RENDERING_RESOURCES_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "SubResource.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Resource.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture : public Resource
    {
    public:
        using ClassType = Texture;
        using ParentType = Resource;

        using TextureSharedPtr = std::shared_ptr<ClassType>;
        using ConstTextureSharedPtr = std::shared_ptr<const ClassType>;

    public:
        Texture(const std::string& name, int numElements, int elementSize, GraphicsObjectType type, bool createStorage = true);
        Texture(const std::string& name, int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(Texture);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD virtual int GetNumItems() const noexcept = 0;

        NODISCARD virtual DataFormatType GetFormat() const = 0;
        NODISCARD virtual int GetNumLevels() const = 0;

        NODISCARD virtual int GetNumElementsFor(int level) const = 0;

        NODISCARD virtual int GetDimension(int index) const = 0;
        NODISCARD virtual int GetNumDimensions() const = 0;
        NODISCARD virtual int GetDimension(int level, int index) const = 0;
        NODISCARD virtual int GetNumLevelBytes(int level) const = 0;
        NODISCARD virtual int GetLevelOffset(int item, int level) const = 0;

        NODISCARD virtual bool HasMipMaps() const = 0;

        void virtual AutoGenerateMipMaps() noexcept = 0;
        NODISCARD virtual bool WantAutoGenerateMipMaps() const noexcept = 0;

        NODISCARD virtual int GetNumSubResources() const noexcept = 0;
        NODISCARD virtual int GetIndex(int item, int level) const = 0;

        NODISCARD ConstSpanIterator GetDataFor(int item, int level) const;
        NODISCARD SpanIterator GetDataFor(int item, int level);

        NODISCARD SubResource GetSubResource(int index);

        NODISCARD virtual TextureSharedPtr Clone() const = 0;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture);
}

#endif  // RENDERING_RESOURCES_TEXTURE_H
