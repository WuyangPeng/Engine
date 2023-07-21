///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 15:34)

#include "Rendering/RenderingExport.h"

#include "MaterialImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/ColourDetail.h"

Rendering::MaterialImpl::MaterialImpl() noexcept
    : emissive{ 0.0f, 0.0f, 0.0f, 1.0f },
      ambient{ 0.0f, 0.0f, 0.0f, 1.0f },
      diffuse{ 0.0f, 0.0f, 0.0f, 1.0f },
      specular{ 0.0f, 0.0f, 0.0f, 1.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}
Rendering::MaterialImpl::MaterialImpl(const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specular) noexcept
    : emissive{ emissive }, ambient{ ambient }, diffuse{ diffuse }, specular{ specular }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MaterialImpl)

void Rendering::MaterialImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadAggregate(emissive);
    source.ReadAggregate(ambient);
    source.ReadAggregate(diffuse);
    source.ReadAggregate(specular);
}

void Rendering::MaterialImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteAggregate(emissive);
    target.WriteAggregate(ambient);
    target.WriteAggregate(diffuse);
    target.WriteAggregate(specular);
}

int Rendering::MaterialImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = Mathematics::GetStreamSize(emissive);

    size += Mathematics::GetStreamSize(ambient);
    size += Mathematics::GetStreamSize(diffuse);
    size += Mathematics::GetStreamSize(specular);

    return size;
}

Rendering::MaterialImpl::Colour Rendering::MaterialImpl::GetEmissive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return emissive;
}

Rendering::MaterialImpl::Colour Rendering::MaterialImpl::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ambient;
}

Rendering::MaterialImpl::Colour Rendering::MaterialImpl::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return diffuse;
}

Rendering::MaterialImpl::Colour Rendering::MaterialImpl::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return specular;
}

void Rendering::MaterialImpl::SetEmissive(const Colour& aEmissive) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    emissive = aEmissive;
}

void Rendering::MaterialImpl::SetAmbient(const Colour& aAmbient) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    ambient = aAmbient;
}

void Rendering::MaterialImpl::SetDiffuse(const Colour& aDiffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    diffuse = aDiffuse;
}

void Rendering::MaterialImpl::SetSpecular(const Colour& aSpecular) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    specular = aSpecular;
}

float Rendering::MaterialImpl::GetAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return diffuse.GetAlpha();
}

float Rendering::MaterialImpl::GetSpecularExponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return specular.GetAlpha();
}
