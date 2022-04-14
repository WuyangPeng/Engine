///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 20:15)

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

        // �û��ֶΡ���Щ���������ڴ洢�ض���Ӧ�ó����δ֪�����ࡣ
        void SetUserField(int index, int32_t userField);
        NODISCARD int32_t GetUserField(int index) const;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        // �û��ֶ������洢�ض���Ӧ�ó�������ݡ�
        std::array<int32_t, TextureMaxUserFields> userFields{};
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_USER_FIELD_H
