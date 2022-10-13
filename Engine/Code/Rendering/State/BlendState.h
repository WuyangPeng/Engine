///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 18:16)

#ifndef RENDERING_STATE_BLEND_STATE_H
#define RENDERING_STATE_BLEND_STATE_H

#include "Rendering/RenderingDll.h"

#include "BlendStateTarget.h"
#include "DrawingState.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(BlendState, BlendStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE BlendState : public DrawingState
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(BlendState);
        using ParentType = DrawingState;
        using Colour = Colour<float>;

    public:
        explicit BlendState(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BlendState);

        NODISCARD bool GetEnableAlphaToCoverage() const noexcept;
        void SetEnableAlphaToCoverage(bool aEnableAlphaToCoverage) noexcept;

        NODISCARD bool GetEnableIndependentBlend() const noexcept;
        void SetEnableIndependentBlend(bool aEnableIndependentBlend) noexcept;

        NODISCARD Colour GetBlendColor() const noexcept;
        void SetBlendColor(Colour aBlendColor) noexcept;

        NODISCARD uint32_t GetSampleMask() const noexcept;
        void SetSampleMask(uint32_t aSampleMask) noexcept;

        NODISCARD BlendStateTarget GetBlendStateTarget(int index) const;
        void SetBlendStateTarget(int index, const BlendStateTarget& blendStateTarget);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(BlendState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BlendState);
}

#endif  // RENDERING_STATE_BLEND_STATE_H
