// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:59)

#include "Rendering/RenderingExport.h"

#include "OffsetStateImpl.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
Rendering::OffsetStateImpl ::OffsetStateImpl() noexcept
    : m_FillEnabled{ false }, m_LineEnabled{ false }, m_PointEnabled{ false }, m_Scale{ 0.0f }, m_Bias{ 0.0f }
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OffsetStateImpl)

void Rendering::OffsetStateImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;	

	m_FillEnabled = source.ReadBool();
	m_LineEnabled = source.ReadBool();
	m_PointEnabled = source.ReadBool();
	source.Read(m_Scale);
	source.Read(m_Bias); 
}

void Rendering::OffsetStateImpl
	::Save(BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.WriteBool(m_FillEnabled);
	target.WriteBool(m_LineEnabled);
	target.WriteBool(m_PointEnabled);
	target.Write(m_Scale);
	target.Write(m_Bias);
}

int Rendering::OffsetStateImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_FillEnabled);
	size += CORE_TOOLS_STREAM_SIZE(m_LineEnabled);
	size += CORE_TOOLS_STREAM_SIZE(m_PointEnabled);
	size += CORE_TOOLS_STREAM_SIZE(m_Scale);
	size += CORE_TOOLS_STREAM_SIZE(m_Bias);

	return size;
}

bool Rendering::OffsetStateImpl
	::IsFillEnabled() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_FillEnabled;
}

bool Rendering::OffsetStateImpl
	::IsLineEnabled() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_LineEnabled;
}

bool Rendering::OffsetStateImpl
	::IsPointEnabled() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_PointEnabled;
}

float Rendering::OffsetStateImpl
	::GetScale() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Scale;
}

float Rendering::OffsetStateImpl
	::GetBias() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Bias;
}

void Rendering::OffsetStateImpl
	::SetFillEnabled(bool fillEnabled)
{
	RENDERING_CLASS_IS_VALID_9;

	m_FillEnabled = fillEnabled;
}

void Rendering::OffsetStateImpl
	::SetLineEnabled(bool lineEnabled)
{
	RENDERING_CLASS_IS_VALID_9;

	m_LineEnabled = lineEnabled;
}

void Rendering::OffsetStateImpl
	::SetPointEnabled(bool pointEnabled)
{
	RENDERING_CLASS_IS_VALID_9;

	m_PointEnabled = pointEnabled;
}

void Rendering::OffsetStateImpl
	::SetScale(float scale)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Scale = scale;
}

void Rendering::OffsetStateImpl
	::SetBias(float bias)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Bias = bias;
}

void Rendering::OffsetStateImpl
	::SaveState(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

const	auto fillEnabled = (m_FillEnabled ? 1 : 0);
        const auto lineEnabled = (m_LineEnabled ? 1 : 0);
const auto pointEnabled = (m_PointEnabled ? 1 : 0);
        const auto scale = m_Scale;
const auto bias = m_Bias;

	manager.Write(sizeof(int), &fillEnabled);
	manager.Write(sizeof(int), &lineEnabled);
	manager.Write(sizeof(int), &pointEnabled);
	manager.Write(sizeof(float), &scale);
	manager.Write(sizeof(float), &bias);
}

void Rendering::OffsetStateImpl
	::LoadState(ReadFileManager& manager)
{
	RENDERING_CLASS_IS_VALID_9;

	int fillEnabled{ 0 };
	int lineEnabled{ 0 };
	int pointEnabled{ 0 };
	float scale{ 0.0f };
	float bias{ 0.0f };
	manager.Read(sizeof(int), &fillEnabled);
	manager.Read(sizeof(int), &lineEnabled);
	manager.Read(sizeof(int), &pointEnabled);
	manager.Read(sizeof(float), &scale);
	manager.Read(sizeof(float), &bias);

	m_FillEnabled = (fillEnabled == 1 ? true : false);
	m_LineEnabled = (lineEnabled == 1 ? true : false);
	m_PointEnabled = (pointEnabled == 1 ? true : false);
	m_Scale = scale;
	m_Bias = bias;
}
#include STSTEM_WARNING_POP