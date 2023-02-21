///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 18:13)

#include "Rendering/RenderingExport.h"

#include "ProjectorMatrixConstantImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;
using std::vector;

Rendering::ProjectorMatrixConstantImpl::ProjectorMatrixConstantImpl(const ProjectorSharedPtr& projector, bool biased, int biasScaleMatrixIndex) noexcept
    : ParentType{ projector }, biased{ biased }, biasScaleMatrixIndex{ biasScaleMatrixIndex }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProjectorMatrixConstantImpl::ProjectorMatrixConstantImpl() noexcept
    : ParentType{}, biased{ false }, biasScaleMatrixIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ProjectorMatrixConstantImpl::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= biasScaleMatrixIndex && biasScaleMatrixIndex <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::ProjectorMatrixConstantImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Load(source);
    biased = source.ReadBool();
    source.Read(biasScaleMatrixIndex);
}

void Rendering::ProjectorMatrixConstantImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    ParentType::Save(target);
    target.Write(biased);
    target.Write(biasScaleMatrixIndex);
}

int Rendering::ProjectorMatrixConstantImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();
    size += CoreTools::GetStreamSize(biased);
    size += CoreTools::GetStreamSize(biasScaleMatrixIndex);

    return size;
}

Rendering::ProjectorMatrixConstantImpl::Matrix Rendering::ProjectorMatrixConstantImpl::GetProjectionViewWorldMatrix(const Matrix& projectionViewWorldMatrix) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (biased)
    {
        return Projector::GetBiasScaleMatrix(biasScaleMatrixIndex) * projectionViewWorldMatrix;
    }

    return projectionViewWorldMatrix;
}
