// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 10:16)

#ifndef RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/DataTypes/Transform.h"

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TransformControllerImpl
    {
    public:
        using ClassType = TransformControllerImpl;
        using APoint = Mathematics::FloatAPoint;
        using Matrix = Mathematics::FloatMatrix;

    public:
        explicit TransformControllerImpl(const FloatTransform& localTransform) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetTransform(const FloatTransform& localTransform) noexcept;
        const FloatTransform GetTransform() const noexcept;

        void SetTranslate(const APoint& translate);
        void SetRotate(const Matrix& rotate);
        void SetUniformScale(float scale);
        void SetScale(const APoint& scale);
        void SetMatrix(const Matrix& matrix);

        int GetStreamingSize() const noexcept;
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        void Load(const CoreTools::BufferSourceSharedPtr& source);

    private:
        FloatTransform m_LocalTransform;
    };
}

#endif  // RENDERING_CONTROLLERS_TRANSFORM_CONTROLLER_IMPL_H
