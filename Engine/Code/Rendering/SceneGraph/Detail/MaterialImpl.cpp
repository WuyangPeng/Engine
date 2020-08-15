// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 16:11)

#include "Rendering/RenderingExport.h"

#include "MaterialImpl.h"
#include "Rendering/DataTypes/ColourDetail.h" 
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26440)
Rendering::MaterialImpl
    ::MaterialImpl()
	:m_Emissive{ 0.0f, 0.0f, 0.0f, 1.0f }, m_Ambient{ 0.0f, 0.0f, 0.0f, 1.0f }, m_Diffuse{ 0.0f, 0.0f, 0.0f, 1.0f }, m_Specular{ 0.0f, 0.0f, 0.0f, 0.0f }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}
Rendering::MaterialImpl
	::MaterialImpl(const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specdiffuseular)
	: m_Emissive{ emissive },m_Ambient{ ambient },m_Diffuse{ diffuse },m_Specular{ specdiffuseular }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MaterialImpl)

void Rendering::MaterialImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	source.ReadAggregate(m_Emissive);
	source.ReadAggregate(m_Ambient);
	source.ReadAggregate(m_Diffuse);
	source.ReadAggregate(m_Specular);
}

void Rendering::MaterialImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteAggregate(m_Emissive);
	target.WriteAggregate(m_Ambient);
	target.WriteAggregate(m_Diffuse);
	target.WriteAggregate(m_Specular);
}

int Rendering::MaterialImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = MATHEMATICS_STREAM_SIZE(m_Emissive);

	size += MATHEMATICS_STREAM_SIZE(m_Ambient);
	size += MATHEMATICS_STREAM_SIZE(m_Diffuse);
	size += MATHEMATICS_STREAM_SIZE(m_Specular);

	return size;
}

const Rendering::MaterialImpl::Colour Rendering::MaterialImpl
	::GetEmissive() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Emissive;
}

const Rendering::MaterialImpl::Colour Rendering::MaterialImpl
	::GetAmbient() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Ambient;
}

const Rendering::MaterialImpl::Colour Rendering::MaterialImpl
	::GetDiffuse() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Diffuse;
}

const Rendering::MaterialImpl::Colour Rendering::MaterialImpl
	::GetSpecular() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Specular;
}

void Rendering::MaterialImpl
	::SetEmissive(const Colour& emissive)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Emissive = emissive;
}

void Rendering::MaterialImpl
	::SetAmbient(const Colour& ambient)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Ambient = ambient;
}

void Rendering::MaterialImpl
	::SetDiffuse(const Colour& diffuse)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Diffuse = diffuse;
}

void Rendering::MaterialImpl
	::SetSpecular(const Colour& specular)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Specular = specular;
}

float Rendering::MaterialImpl
	::GetAlpha() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Diffuse.GetAlpha();
}

float Rendering::MaterialImpl
	::GetSpecularExponent() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Specular.GetAlpha();
}


 #include STSTEM_WARNING_POP