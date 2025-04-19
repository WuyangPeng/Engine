/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:09)

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

        using ColourType = Colour<float>;
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

        NODISCARD ColourType GetBlendColor() const noexcept;
        void SetBlendColor(const ColourType& blendColor) noexcept;

        NODISCARD uint32_t GetSampleMask() const noexcept;
        void SetSampleMask(uint32_t sampleMask) noexcept;

        NODISCARD BlendStateTarget GetBlendStateTarget(int index) const;
        void SetBlendStateTarget(int index, const BlendStateTarget& blendStateTarget);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        void CheckBlendState();

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(BlendState);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(BlendState);
}

#endif  // RENDERING_STATE_BLEND_STATE_H
