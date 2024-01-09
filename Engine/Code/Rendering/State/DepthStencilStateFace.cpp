/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:12)

#include "Rendering/RenderingExport.h"

#include "DepthStencilStateFace.h"
#include "Flags/DepthStencilStateComparison.h"
#include "Flags/DepthStencilStateOperation.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

Rendering::DepthStencilStateFace::DepthStencilStateFace() noexcept
    : fail{ DepthStencilStateOperation::Keep },
      depthFail{ DepthStencilStateOperation::Keep },
      pass{ DepthStencilStateOperation::Keep },
      comparison{ DepthStencilStateComparison::Always }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, DepthStencilStateFace)

Rendering::DepthStencilStateOperation Rendering::DepthStencilStateFace::GetFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fail;
}

void Rendering::DepthStencilStateFace::SetFail(Rendering::DepthStencilStateOperation aFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    fail = aFail;
}

Rendering::DepthStencilStateOperation Rendering::DepthStencilStateFace::GetDepthFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthFail;
}

void Rendering::DepthStencilStateFace::SetDepthFail(Rendering::DepthStencilStateOperation aDepthFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    depthFail = aDepthFail;
}

Rendering::DepthStencilStateOperation Rendering::DepthStencilStateFace::GetPass() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pass;
}

void Rendering::DepthStencilStateFace::SetPass(Rendering::DepthStencilStateOperation aPass) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    pass = aPass;
}

Rendering::DepthStencilStateComparison Rendering::DepthStencilStateFace::GetComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return comparison;
}

void Rendering::DepthStencilStateFace::SetComparison(Rendering::DepthStencilStateComparison aComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    comparison = aComparison;
}

void Rendering::DepthStencilStateFace::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadEnum(fail);
    source.ReadEnum(depthFail);
    source.ReadEnum(pass);
    source.ReadEnum(comparison);
};

void Rendering::DepthStencilStateFace::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteEnum(fail);
    target.WriteEnum(depthFail);
    target.WriteEnum(pass);
    target.WriteEnum(comparison);
}

int Rendering::DepthStencilStateFace::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(fail);

    size += CoreTools::GetStreamSize(depthFail);
    size += CoreTools::GetStreamSize(pass);
    size += CoreTools::GetStreamSize(comparison);

    return size;
}

bool Rendering::operator==(const DepthStencilStateFace& lhs, const DepthStencilStateFace& rhs) noexcept
{
    return lhs.GetFail() == rhs.GetFail() &&
           lhs.GetDepthFail() == rhs.GetDepthFail() &&
           lhs.GetPass() == rhs.GetPass() &&
           lhs.GetComparison() == rhs.GetComparison();
}
