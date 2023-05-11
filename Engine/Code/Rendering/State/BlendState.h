///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/03 14:51)

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
        using BlendStateSharedPtr = std::shared_ptr<BlendState>;

    private:
        enum class BlendStateCreate
        {
            Init,
        };

    public:
        NODISCARD static BlendStateSharedPtr Create(const std::string& name);
        BlendState(BlendStateCreate blendStateCreate, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BlendState);

        NODISCARD bool IsEnableAlphaToCoverage() const noexcept;
        void SetEnableAlphaToCoverage(bool enableAlphaToCoverage) noexcept;

        NODISCARD bool IsEnableIndependentBlend() const noexcept;
        void SetEnableIndependentBlend(bool enableIndependentBlend) noexcept;

        NODISCARD Colour GetBlendColor() const noexcept;
        void SetBlendColor(Colour blendColor) noexcept;

        NODISCARD uint32_t GetSampleMask() const noexcept;
        void SetSampleMask(uint32_t sampleMask) noexcept;

        NODISCARD BlendStateTarget GetBlendStateTarget(int index) const;
        void SetBlendStateTarget(int index, const BlendStateTarget& blendStateTarget);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        void CheckDrawingState();

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(BlendState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BlendState);
}

#endif  // RENDERING_STATE_BLEND_STATE_H