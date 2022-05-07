///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 17:09)

#ifndef RENDERING_SHADERS_DEPTH_STATE_IMPL_H
#define RENDERING_SHADERS_DEPTH_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/Flags/DepthStateFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE DepthStateImpl
    {
    public:
        using ClassType = DepthStateImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using CompareMode = DepthStateFlags::CompareMode;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        DepthStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsEnabled() const noexcept;
        NODISCARD bool IsWritable() const noexcept;
        NODISCARD CompareMode GetCompare() const noexcept;

        void SetEnabled(bool aEnabled) noexcept;
        void SetWritable(bool aWritable) noexcept;
        void SetCompare(CompareMode aCompare) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        bool enabled;  // 默认: true
        bool writable;  // 默认: true
        CompareMode compare;  // 默认: CompareMode::LessEqual
    };
}

#endif  // RENDERING_SHADERS_DEPTH_STATE_IMPL_H
