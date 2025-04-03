/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:21)

#ifndef RENDERING_STATE_SAMPLER_STATE_H
#define RENDERING_STATE_SAMPLER_STATE_H

#include "Rendering/RenderingDll.h"

#include "DrawingState.h"
#include "StateFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(SamplerState, SamplerStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SamplerState : public DrawingState
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SamplerState);
        using ParentType = DrawingState;

        using ColourType = Colour<float>;

    public:
        explicit SamplerState(const std::string& name);
        SamplerState(SamplerStateFilter filter,
                     SamplerStateMode mode0,
                     SamplerStateMode mode1);
        SamplerState(SamplerStateFilter filter,
                     SamplerStateMode mode0,
                     SamplerStateMode mode1,
                     SamplerStateMode mode2);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SamplerState);

        NODISCARD SamplerStateFilter GetFilter() const noexcept;
        NODISCARD SamplerStateMode GetMode(int index) const;
        NODISCARD float GetMipLodBias() const noexcept;
        NODISCARD int GetMaxAnisotropy() const noexcept;
        NODISCARD SamplerStateComparison GetComparison() const noexcept;
        NODISCARD ColourType GetBorderColor() const noexcept;
        NODISCARD float GetMinLod() const noexcept;
        NODISCARD float GetMaxLod() const noexcept;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    public:
        NODISCARD static constexpr int GetShaderDataLookup() noexcept
        {
            return 6;
        }

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(SamplerState);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(SamplerState);
}

#endif  // RENDERING_STATE_SAMPLER_STATE_H
