///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 17:19)

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

    public:
        BlendStateTarget() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool GetEnable() const noexcept;
        void SetEnable(bool aEnable) noexcept;

        NODISCARD BlendStateMode GetSrcColor() const noexcept;
        void SetSrcColor(BlendStateMode aSrcColor) noexcept;

        NODISCARD BlendStateMode GetDstColor() const noexcept;
        void SetDstColor(BlendStateMode aDstColor) noexcept;

        NODISCARD BlendStateOperation GetOpColor() const noexcept;
        void SetOpColor(BlendStateOperation aOpColor) noexcept;

        NODISCARD BlendStateMode GetSrcAlpha() const noexcept;
        void SetSrcAlpha(BlendStateMode aSrcAlpha) noexcept;

        NODISCARD BlendStateMode GetDstAlpha() const noexcept;
        void SetDstAlpha(BlendStateMode aDstAlpha) noexcept;

        NODISCARD BlendStateOperation GetOpAlpha() const noexcept;
        void SetOpAlpha(BlendStateOperation aOpAlpha) noexcept;

        NODISCARD BlendStateColorWrite GetMask() const noexcept;
        void SetMask(BlendStateColorWrite aMask) noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        bool enable;
        BlendStateMode srcColor;
        BlendStateMode dstColor;
        BlendStateOperation opColor;
        BlendStateMode srcAlpha;
        BlendStateMode dstAlpha;
        BlendStateOperation opAlpha;
        BlendStateColorWrite mask;
    };
}

#endif  // RENDERING_STATE_BLEND_STATE_TARGET_H
