///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:29)

#ifndef RENDERING_SHADERS_OFFSET_STATE_IMPL_H
#define RENDERING_SHADERS_OFFSET_STATE_IMPL_H

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OffsetStateImpl
    {
    public:
        using ClassType = OffsetStateImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        OffsetStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsFillEnabled() const noexcept;
        NODISCARD bool IsLineEnabled() const noexcept;
        NODISCARD bool IsPointEnabled() const noexcept;
        NODISCARD float GetScale() const noexcept;
        NODISCARD float GetBias() const noexcept;

        void SetFillEnabled(bool aFillEnabled) noexcept;
        void SetLineEnabled(bool aLineEnabled) noexcept;
        void SetPointEnabled(bool pointEnabled) noexcept;
        void SetScale(float aScale) noexcept;
        void SetBias(float bias) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        // 设置是否应该为各种多边形绘图模式（填充，线，点）启用偏移。
        bool fillEnabled;  // 默认: false
        bool lineEnabled;  // 默认: false
        bool pointEnabled;  // 默认: false

        // 偏移量是Scale * dZ + Bias * r，
        // 其中DZ是相对于聚屏幕空间区域深度的变化，
        // r是最小可分辨深度差异。负值表示移动多边形接近眼睛。
        float scale;  // 默认: 0
        float bias;  // 默认: 0
    };
}

#endif  // RENDERING_SHADERS_OFFSET_STATE_IMPL_H
