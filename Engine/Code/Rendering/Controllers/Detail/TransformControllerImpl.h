///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 11:24)

#ifndef RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/Transform.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TransformControllerImpl
    {
    public:
        using ClassType = TransformControllerImpl;

        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

    public:
        explicit TransformControllerImpl(const Mathematics::TransformF& localTransform) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetTransform(const Mathematics::TransformF& aLocalTransform) noexcept;
        NODISCARD Mathematics::TransformF GetTransform() const noexcept;

        void SetTranslate(const APoint& translate) noexcept;
        void SetRotate(const Matrix& rotate) noexcept;
        void SetUniformScale(float scale);
        void SetScale(const APoint& scale);
        void SetMatrix(const Matrix& matrix) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

    private:
        Mathematics::TransformF localTransform;
    };
}

#endif  // RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H
