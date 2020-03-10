// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 16:09)

#include "Rendering/RenderingExport.h"

#include "SurfacePatchImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::SurfacePatchImpl
	::SurfacePatchImpl()
	: m_UMin{ 0.0f }, m_UMax{ 0.0f }, m_VMin{ 0.0f }, m_VMax{ 0.0f }, m_Rectangular{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::SurfacePatchImpl
	::SurfacePatchImpl(float uMin, float uMax, float vMin,float vMax, bool rectangular)
	: m_UMin{ uMin }, m_UMax{ uMax }, m_VMin{ vMin }, m_VMax{ vMax }, m_Rectangular{ rectangular }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::SurfacePatchImpl
	::IsValid() const noexcept
{
	if(m_UMin <= m_UMax && m_VMin <= m_VMin)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::SurfacePatchImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;

	source.Read(m_UMin);
	source.Read(m_UMax);
	source.Read(m_VMin);
	source.Read(m_VMax);
	m_Rectangular = source.ReadBool();
}

void Rendering::SurfacePatchImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target.Write(m_UMin);
	target.Write(m_UMax);
	target.Write(m_VMin);
	target.Write(m_VMax);
	target.WriteBool(m_Rectangular);
}

int Rendering::SurfacePatchImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_UMin);
	size += CORE_TOOLS_STREAM_SIZE(m_UMax);
	size += CORE_TOOLS_STREAM_SIZE(m_VMin);
	size += CORE_TOOLS_STREAM_SIZE(m_VMax);
	size += CORE_TOOLS_STREAM_SIZE(m_Rectangular);

	return size;
}

float Rendering::SurfacePatchImpl
	::GetUMin() const noexcept 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_UMin;
}

float Rendering::SurfacePatchImpl
	::GetUMax() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_UMax;
}

float Rendering::SurfacePatchImpl
	::GetVMin() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_VMin;
}

float Rendering::SurfacePatchImpl
	::GetVMax() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_VMax;
}

bool Rendering::SurfacePatchImpl
	::IsRectangular() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Rectangular;
}
