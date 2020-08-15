// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:51)

#include "Rendering/RenderingExport.h"

#include "WireStateImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::WireStateImpl
	::WireStateImpl() noexcept
	:m_Enabled{ false }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, WireStateImpl)

void Rendering::WireStateImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = source.ReadBool();
}

void Rendering::WireStateImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteBool(m_Enabled);
}

int Rendering::WireStateImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	const auto size = CORE_TOOLS_STREAM_SIZE(m_Enabled);	

	return size;
}

bool Rendering::WireStateImpl ::IsEnabled() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Enabled;
}

void Rendering::WireStateImpl ::SetEnabled(bool enabled) noexcept
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = enabled;
}

void Rendering::WireStateImpl
	::SaveState( WriteFileManager& manager ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

const	auto enabled = (m_Enabled ? 1 : 0);

	manager.Write(sizeof(int), &enabled);
}

void Rendering::WireStateImpl
	::LoadState(ReadFileManager& manager)
{
	RENDERING_CLASS_IS_VALID_9;

	int enabled{ 0 };
	manager.Read(sizeof(int), &enabled);

	m_Enabled = (enabled == 1) ? true : false;
}
