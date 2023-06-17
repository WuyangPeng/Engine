///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:29)

#ifndef RENDERING_SHADERS_CULL_STATE_IMPL_H
#define RENDERING_SHADERS_CULL_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CullStateImpl
    {
    public:
        typedef CullStateImpl ClassType;
        typedef CoreTools::BufferSource BufferSource;
        typedef CoreTools::BufferTarget BufferTarget;
        typedef CoreTools::WriteFileManager WriteFileManager;
        typedef CoreTools::ReadFileManager ReadFileManager;

    public:
        CullStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsEnabled() const noexcept;
        void SetEnabled(bool aEnabled) noexcept;
        NODISCARD bool IsCCWOrder() const noexcept;
        void SetCCWOrder(bool aCCWOrder) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        bool enabled;  // 默认: true
        bool ccwOrder;  // 默认: true
    };
}

#endif  // RENDERING_SHADERS_CULL_STATE_IMPL_H
