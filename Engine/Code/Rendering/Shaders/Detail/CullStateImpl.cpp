// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:57)

#include "Rendering/RenderingExport.h"

#include "CullStateImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::CullStateImpl
	::CullStateImpl() noexcept
	:m_Enabled{ true }, m_CCWOrder{ true }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,CullStateImpl)

bool Rendering::CullStateImpl ::IsEnabled() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Enabled;
}

void Rendering::CullStateImpl ::SetEnabled(bool enabled) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = enabled;
}

bool Rendering::CullStateImpl ::IsCCWOrder() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_CCWOrder;
}

void Rendering::CullStateImpl ::SetCCWOrder(bool cCWOrder) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_CCWOrder = cCWOrder;
}

void Rendering::CullStateImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = source.ReadBool();
	m_CCWOrder = source.ReadBool();
}

void Rendering::CullStateImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteBool(m_Enabled);
	target.WriteBool(m_CCWOrder);
}

int Rendering::CullStateImpl
	::GetStreamingSize() const
{	
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Enabled);
	size += CORE_TOOLS_STREAM_SIZE(m_CCWOrder);

	return size;
}

void Rendering::CullStateImpl
	::SaveState(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

const auto enabled = m_Enabled ? 1 : 0;
        const auto ccwOrder = m_CCWOrder ? 1 : 0;

	manager.Write(sizeof(int), &enabled);
	manager.Write(sizeof(int), &ccwOrder);
}

void Rendering::CullStateImpl
	::LoadState(ReadFileManager& manager)
{
	RENDERING_CLASS_IS_VALID_9;
	
	int enabled{ 0 };
	int ccwOrder{ 0 };
	manager.Read(sizeof(int), &enabled);
	manager.Read(sizeof(int), &ccwOrder);

	m_Enabled = (enabled == 1) ? true : false;
	m_CCWOrder = (ccwOrder == 1) ? true : false; 
}

