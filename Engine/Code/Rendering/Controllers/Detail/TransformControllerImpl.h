///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TransformControllerImpl
    {
    public:
        using ClassType = TransformControllerImpl;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;

    public:
        explicit TransformControllerImpl(const TransformF& localTransform) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetTransform(const TransformF& aLocalTransform) noexcept;
        NODISCARD TransformF GetTransform() const noexcept;

        void SetTranslate(const APoint& translate) noexcept;
        void SetRotate(const Matrix& rotate) noexcept;
        void SetUniformScale(float scale) noexcept(gAssert < 2 || gRenderingAssert < 2);
        void SetScale(const APoint& scale) noexcept(gAssert < 2 || gRenderingAssert < 2);
        void SetMatrix(const Matrix& matrix) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

    private:
        TransformF localTransform;
    };
}

#endif  // RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H
