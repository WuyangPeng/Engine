///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 17:00)

#ifndef RENDERING_GLOBAL_EFFECTS_LIGHT_PROJECTOR_IMPL_H
#define RENDERING_GLOBAL_EFFECTS_LIGHT_PROJECTOR_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Vector4.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LightProjectorImpl
    {
    public:
        using ClassType = LightProjectorImpl;

        using Vector4 = Mathematics::Vector4<float>;

    public:
        LightProjectorImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector4 GetPosition() const noexcept;
        void SetPosition(const Vector4& aPosition) noexcept;
        NODISCARD Vector4 GetDirection() const noexcept;
        void SetDirection(const Vector4& aDirection) noexcept;
        NODISCARD bool IsPointLight() const noexcept;
        void SetIsPointLight(const bool aIsPointLight) noexcept;

    private:
        Vector4 position;
        Vector4 direction;

        bool isPointLight;
    };
}

#endif  // RENDERING_GLOBAL_EFFECTS_LIGHT_PROJECTOR_IMPL_H
