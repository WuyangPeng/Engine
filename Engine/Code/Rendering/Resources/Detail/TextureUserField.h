///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 20:15)

#ifndef RENDERING_RESOURCES_TEXTURE_USER_FIELD_H
#define RENDERING_RESOURCES_TEXTURE_USER_FIELD_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "Rendering/Resources/Flags/TextureFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureUserField
    {
    public:
        using ClassType = TextureUserField;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        TextureUserField() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 用户字段。这些可能是用于存储特定于应用程序的未知纹理类。
        void SetUserField(int index, int32_t userField);
        NODISCARD int32_t GetUserField(int index) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        // 用户字段用来存储特定于应用程序的数据。
        std::array<int32_t, TextureMaxUserFields> userFields{};
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_USER_FIELD_H
