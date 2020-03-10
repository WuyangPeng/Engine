// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/19 14:13)

#include "Rendering/RenderingExport.h"

#include "BufferParameter.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

Rendering::BufferParameter
	::BufferParameter()
	:m_Offset{ 0 }, m_ComponentSize{ 0 }, m_NumComponents{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BufferParameter
	::BufferParameter(int offset, int componentSize, int numComponents)
	:m_Offset{ offset }, m_ComponentSize{ componentSize }, m_NumComponents{ numComponents }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BufferParameter)

void Rendering::BufferParameter
	::Set(int offset, int componentSize, int numComponents)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Offset = offset;
	m_ComponentSize = componentSize;
	m_NumComponents = numComponents;
}

int Rendering::BufferParameter
	::GetOffset() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;	

	return m_Offset;
}

int Rendering::BufferParameter
	::GetComponentSize() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_ComponentSize;
}

int Rendering::BufferParameter
	::GetNumComponents() const 
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_NumComponents;
}

