///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 20:15)

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

        using ReadFileManager = CoreTools::ReadFileManager;
        using WriteFileManager = CoreTools::WriteFileManager;
        using TextureSharedPtr = std::shared_ptr<ClassType>;
        using ConstTextureSharedPtr = std::shared_ptr<const ClassType>;

    public:
        Texture(int numElements, int elementSize, GraphicsObjectType type);
        Texture(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type);

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

        virtual void SaveToFile(WriteFileManager& outFile) const = 0;
        virtual void ReadFromFile(ReadFileManager& inFile) = 0;

        void virtual AutoGenerateMipMaps() noexcept = 0;
        NODISCARD virtual bool WantAutoGenerateMipMaps() const noexcept = 0;

        NODISCARD virtual int GetNumSubResources() const noexcept = 0;
        NODISCARD virtual int GetIndex(int item, int level) const = 0;

        NODISCARD ConstSpanIterator GetDataFor(int item, int level) const;
        NODISCARD SpanIterator GetDataFor(int item, int level);

        NODISCARD SubResource GetSubResource(int index);

        NODISCARD virtual TextureSharedPtr Clone() const = 0;

    protected:
        void SaveTypeToFile(WriteFileManager& outFile) const;
        void SaveResourceDataToFile(WriteFileManager& outFile) const;
        void SaveStorageDataToFile(WriteFileManager& outFile) const;

        void ReadResourceDataFromFile(ReadFileManager& inFile);
        void ReadStorageDataFromFile(ReadFileManager& inFile);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Texture);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture);
}

#endif  // RENDERING_RESOURCES_TEXTURE_H
