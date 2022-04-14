///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 18:02)

#ifndef RENDERING_RESOURCES_TEXTURE_H
#define RENDERING_RESOURCES_TEXTURE_H

#include "Rendering/RenderingDll.h"

#include "Flags/BufferFlags.h"
#include "Flags/TextureFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Texture : public CoreTools::Object
    {
    public:
        using ClassType = Texture;
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;
        using FileBuffer = CoreTools::FileBuffer;
        using FileBufferSharedPtr = std::shared_ptr<FileBuffer>;
        using TextureSharedPtr = std::shared_ptr<ClassType>;
        using ConstTextureSharedPtr = std::shared_ptr<const ClassType>;

    public:
        explicit Texture(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(Texture);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD virtual TextureFormat GetFormat() const = 0;
        NODISCARD virtual TextureFlags GetTextureType() const = 0;
        NODISCARD virtual BufferUsage GetUsage() const = 0;
        NODISCARD virtual int GetNumLevels() const = 0;

        NODISCARD virtual int GetNumDimensions() const = 0;
        NODISCARD virtual int GetDimension(int i, int level) const = 0;
        NODISCARD virtual int GetNumLevelBytes(int level) const = 0;
        NODISCARD virtual int GetNumTotalBytes() const = 0;
        NODISCARD virtual int GetLevelOffset(int level) const = 0;

        NODISCARD virtual int GetPixelSize() const = 0;
        NODISCARD static int GetPixelSize(TextureFormat format);
        NODISCARD virtual bool IsCompressed() const = 0;
        NODISCARD virtual bool IsMipmapable() const = 0;

        // 用户字段。这些可能是用于存储特定于应用程序的未知纹理类。
        virtual void SetUserField(int i, int userField) = 0;
        NODISCARD virtual int GetUserField(int i) const = 0;

        // 支持mipmap产生。
        virtual void GenerateMipmaps() = 0;
        NODISCARD virtual bool HasMipmaps() const = 0;

        virtual void SaveToFile(WriteFileManager& outFile) const = 0;
        virtual void ReadFromFile(ReadFileManager& inFile) = 0;

        NODISCARD virtual TextureSharedPtr Clone() const = 0;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Texture);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Texture);
}

#endif  // RENDERING_RESOURCES_TEXTURE_H
