/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:08)

#ifndef RENDERING_STATE_BLEND_STATE_TARGET_H
#define RENDERING_STATE_BLEND_STATE_TARGET_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE BlendStateTarget
    {
    public:
        using ClassType = BlendStateTarget;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        BlendStateTarget() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsEnable() const noexcept;
        void SetEnable(bool aEnable) noexcept;

        NODISCARD BlendStateMode GetSourceColor() const noexcept;
        void SetSourceColor(BlendStateMode color) noexcept;

        NODISCARD BlendStateMode GetDestinationColor() const noexcept;
        void SetDestinationColor(BlendStateMode color) noexcept;

        NODISCARD BlendStateOperation GetOperationColor() const noexcept;
        void SetOperationColor(BlendStateOperation color) noexcept;

        NODISCARD BlendStateMode GetSourceAlpha() const noexcept;
        void SetSourceAlpha(BlendStateMode alpha) noexcept;

        NODISCARD BlendStateMode GetDestinationAlpha() const noexcept;
        void SetDestinationAlpha(BlendStateMode alpha) noexcept;

        NODISCARD BlendStateOperation GetOperationAlpha() const noexcept;
        void SetOperationAlpha(BlendStateOperation alpha) noexcept;

        NODISCARD BlendStateColorWrite GetMask() const noexcept;
        void SetMask(BlendStateColorWrite aMask) noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        bool enable;
        BlendStateMode sourceColor;
        BlendStateMode destinationColor;
        BlendStateOperation operationColor;
        BlendStateMode sourceAlpha;
        BlendStateMode destinationAlpha;
        BlendStateOperation operationAlpha;
        BlendStateColorWrite mask;
    };

    NODISCARD bool RENDERING_DEFAULT_DECLARE operator==(const BlendStateTarget& lhs, const BlendStateTarget& rhs) noexcept;
}

#endif  // RENDERING_STATE_BLEND_STATE_TARGET_H
