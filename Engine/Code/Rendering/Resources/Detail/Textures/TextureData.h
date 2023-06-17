///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:23)

#ifndef RENDERING_RESOURCES_TEXTURE_DATA_H
#define RENDERING_RESOURCES_TEXTURE_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TextureData
    {
    public:
        using ClassType = TextureData;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        TextureData(DataFormatType format, int numLevels) noexcept;
        TextureData() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD DataFormatType GetFormat() const noexcept;
        NODISCARD int GetNumLevels() const noexcept;

        void SetNumLevels(int aNumLevels) noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        void SaveToFile(WriteFileManager& outFile) const;
        void ReadFromFile(ReadFileManager& inFile);

    private:
        DataFormatType format;
        int numLevels;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_DATA_H
