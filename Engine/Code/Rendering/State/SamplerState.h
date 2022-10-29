///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/19 0:55)

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
        using Colour = Colour<float>;

    public:
        explicit SamplerState(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SamplerState);

        NODISCARD SamplerStateFilter GetFilter() const noexcept;
        NODISCARD SamplerStateMode GetMode(int index) const;
        NODISCARD float GetMipLODBias() const noexcept;
        NODISCARD int GetMaxAnisotropy() const noexcept;
        NODISCARD SamplerStateComparison GetComparison() const noexcept;
        NODISCARD Colour GetBorderColor() const noexcept;
        NODISCARD float GetMinLOD() const noexcept;
        NODISCARD float GetMaxLOD() const noexcept;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(SamplerState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(SamplerState);
}

#endif  // RENDERING_STATE_SAMPLER_STATE_H
