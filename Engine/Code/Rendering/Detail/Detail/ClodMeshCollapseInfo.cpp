// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 10:35)

#include "Rendering/RenderingExport.h"

#include "ClodMeshCollapseInfo.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

Rendering::ClodMeshCollapseInfo
	::ClodMeshCollapseInfo(int vKeep, int vThrow )
	:m_VKeep{ vKeep }, m_VThrow{ vThrow }, m_TThrow0{ -1 }, m_TThrow1{ -1 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshCollapseInfo)

int Rendering::ClodMeshCollapseInfo
	::GetVKeep() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VKeep;
}

void Rendering::ClodMeshCollapseInfo
	::SetVKeep(int vKeep)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VKeep = vKeep;
}

int Rendering::ClodMeshCollapseInfo
	::GetVThrow() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_VThrow;
}

void Rendering::ClodMeshCollapseInfo
	::SetVThrow(int vThrow)
{
	RENDERING_CLASS_IS_VALID_9;

	m_VThrow = vThrow;
}

int Rendering::ClodMeshCollapseInfo
	::GetTThrow0() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_TThrow0;
}

void Rendering::ClodMeshCollapseInfo
	::SetTThrow0(int tThrow0)
{
	RENDERING_CLASS_IS_VALID_9;

	m_TThrow0 = tThrow0;
}

int Rendering::ClodMeshCollapseInfo
	::GetTThrow1() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_TThrow1;
}

void Rendering::ClodMeshCollapseInfo
	::SetTThrow1(int tThrow1)
{
	RENDERING_CLASS_IS_VALID_9;

	m_TThrow1 = tThrow1;
}

