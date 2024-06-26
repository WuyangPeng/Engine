/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:52)

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

    private:
        DataFormatType format;
        int numLevels;
    };
}

#endif  // RENDERING_RESOURCES_TEXTURE_DATA_H
