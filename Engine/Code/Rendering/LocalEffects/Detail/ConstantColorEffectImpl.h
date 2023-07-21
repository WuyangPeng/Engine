///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/10 14:53)

#ifndef RENDERING_LOCAL_EFFECTS_CONSTANT_COLOR_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_CONSTANT_COLOR_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ConstantColorEffectImpl
    {
    public:
        using ClassType = ConstantColorEffectImpl;

        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;

    public:
        ConstantColorEffectImpl() noexcept;
        explicit ConstantColorEffectImpl(int numColorConstantBytes);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstConstantBufferSharedPtr GetColorConstant() const noexcept;
        NODISCARD ConstantBufferSharedPtr GetColorConstant() noexcept;

    private:
        ConstantBufferSharedPtr colorConstant;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_CONSTANT_COLOR_EFFECT_IMPL_H
