// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 14:42)

#include "Rendering/RenderingExport.h"

#include "ControllerKeyInfo.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
 
Rendering::ControllerKeyInfo
	::ControllerKeyInfo(float normTime, int firstIndex, int secondIndex) noexcept
	:m_NormTime{ normTime }, m_FirstIndex{ firstIndex }, m_SecondIndex{ secondIndex }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ControllerKeyInfo::ControllerKeyInfo() noexcept
    : m_NormTime{ 0.0f }, m_FirstIndex{ 0 }, m_SecondIndex{ 0 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,ControllerKeyInfo)

float Rendering::ControllerKeyInfo::GetNormTime() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_NormTime;
}

int Rendering::ControllerKeyInfo::GetFirstIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_FirstIndex;
}

int Rendering::ControllerKeyInfo::GetSecondIndex() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_SecondIndex;
}