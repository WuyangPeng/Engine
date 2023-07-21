///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/18 14:23)

#ifndef RENDERING_GLOBAL_EFFECTS_LIGHT_PROJECTOR_H
#define RENDERING_GLOBAL_EFFECTS_LIGHT_PROJECTOR_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Mathematics/Algebra/Vector4.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(LightProjector, LightProjectorImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightProjector
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(LightProjector);

        using Vector4 = Mathematics::Vector4<float>;

    public:
        explicit LightProjector(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector4 GetPosition() const noexcept;
        void SetPosition(const Vector4& aPosition) noexcept;
        NODISCARD Vector4 GetDirection() const noexcept;
        void SetDirection(const Vector4& aDirection) noexcept;
        NODISCARD bool IsPointLight() const noexcept;
        void SetIsPointLight(const bool aIsPointLight) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_GLOBAL_EFFECTS_LIGHT_PROJECTOR_H
