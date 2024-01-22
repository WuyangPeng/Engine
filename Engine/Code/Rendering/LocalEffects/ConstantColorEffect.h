/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 16:46)

#ifndef RENDERING_LOCAL_EFFECTS_CONSTANT_COLOR_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_CONSTANT_COLOR_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualEffect.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ConstantColorEffect, ConstantColorEffectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ConstantColorEffect : public VisualEffect
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ConstantColorEffect);
        using ParentType = VisualEffect;

        using Colour = Colour<float>;

    public:
        ConstantColorEffect(const std::string& name, ProgramFactory& factory, const BaseRendererSharedPtr& baseRenderer, const Colour& color);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ConstantColorEffect);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        void SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer) override;

        NODISCARD ConstantBufferSharedPtr GetColorConstant() noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetColorConstant() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_CONSTANT_COLOR_EFFECT_H
