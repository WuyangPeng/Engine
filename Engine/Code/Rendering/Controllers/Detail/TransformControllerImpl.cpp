///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 11:24)

#include "Rendering/RenderingExport.h"

#include "TransformControllerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::TransformControllerImpl::TransformControllerImpl(const TransformF& localTransform) noexcept
    : localTransform{ localTransform }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TransformControllerImpl)

void Rendering::TransformControllerImpl::SetTransform(const TransformF& aLocalTransform) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform = aLocalTransform;
}

Rendering::TransformF Rendering::TransformControllerImpl::GetTransform() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return localTransform;
}

int Rendering::TransformControllerImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return RENDERING_STREAM_SIZE(localTransform);
}

void Rendering::TransformControllerImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregate(localTransform);
}

void Rendering::TransformControllerImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadAggregate(localTransform);
}

void Rendering::TransformControllerImpl::SetTranslate(const APoint& translate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetTranslate(translate);
}

void Rendering::TransformControllerImpl::SetRotate(const Matrix& rotate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetRotate(rotate);
}

void Rendering::TransformControllerImpl::SetUniformScale(float scale) noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetUniformScale(scale);
}

void Rendering::TransformControllerImpl::SetScale(const APoint& scale) noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetScale(scale);
}

void Rendering::TransformControllerImpl::SetMatrix(const Matrix& matrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    localTransform.SetMatrix(matrix);
}
