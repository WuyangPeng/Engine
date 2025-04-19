/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 20:36)

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
Rendering::MaterialImpl::MaterialImpl(const ColourType& emissive, const ColourType& ambient, const ColourType& diffuse, const ColourType& specular) noexcept
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

Rendering::MaterialImpl::ColourType Rendering::MaterialImpl::GetEmissive() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return emissive;
}

Rendering::MaterialImpl::ColourType Rendering::MaterialImpl::GetAmbient() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ambient;
}

Rendering::MaterialImpl::ColourType Rendering::MaterialImpl::GetDiffuse() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return diffuse;
}

Rendering::MaterialImpl::ColourType Rendering::MaterialImpl::GetSpecular() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return specular;
}

void Rendering::MaterialImpl::SetEmissive(const ColourType& aEmissive) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    emissive = aEmissive;
}

void Rendering::MaterialImpl::SetAmbient(const ColourType& aAmbient) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    ambient = aAmbient;
}

void Rendering::MaterialImpl::SetDiffuse(const ColourType& aDiffuse) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    diffuse = aDiffuse;
}

void Rendering::MaterialImpl::SetSpecular(const ColourType& aSpecular) noexcept
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
