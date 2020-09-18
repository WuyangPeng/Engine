// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 15:57)

#include "Rendering/RenderingExport.h"

#include "DepthStateImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/EnumCast.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::DepthStateImpl
	::DepthStateImpl() noexcept
	:m_Enabled{ true },m_Writable{ true },m_Compare{ DepthStateFlags::CompareMode::LessEqual }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, DepthStateImpl)

void Rendering::DepthStateImpl
	::Load(BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = source.ReadBool();
	m_Writable = source.ReadBool();
	source.ReadEnum(m_Compare);
}

void Rendering::DepthStateImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target->Write(m_Enabled);
	target->Write(m_Writable);
        target->WriteEnum(m_Compare);
}

int Rendering::DepthStateImpl
	::GetStreamingSize() const
{	
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Enabled);
	size += CORE_TOOLS_STREAM_SIZE(m_Writable);
	size += CORE_TOOLS_STREAM_SIZE(m_Compare);

	return size;
}

bool Rendering::DepthStateImpl
	::IsEnabled() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Enabled;
}

bool Rendering::DepthStateImpl
	::IsWritable() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Writable;
}

Rendering::DepthStateImpl::CompareMode Rendering::DepthStateImpl
	::GetCompare() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Compare;
}

void Rendering::DepthStateImpl
	::SetEnabled(bool enabled)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = enabled;
}

void Rendering::DepthStateImpl
	::SetWritable(bool writable)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Writable = writable;
}

void Rendering::DepthStateImpl
	::SetCompare(CompareMode compare)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Compare = compare;
}

void Rendering::DepthStateImpl
	::SaveState(WriteFileManager& manager) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

const auto enabled = m_Enabled ? 1 : 0;
        const auto writable = m_Writable ? 1 : 0;
        const	auto compare = System::EnumCastUnderlying(m_Compare);

	manager.Write(sizeof(int), &enabled);
	manager.Write(sizeof(int), &writable);
	manager.Write(sizeof(int), &compare);
}

void Rendering::DepthStateImpl
	::LoadState(ReadFileManager& manager)
{
	RENDERING_CLASS_IS_VALID_9;

	int enabled{ 0 };
	int writable{ 0 };
	int compare{ 0 };
	manager.Read(sizeof(int), &enabled);
	manager.Read(sizeof(int), &writable);
	manager.Read(sizeof(int), &compare);

	m_Enabled = (enabled == 1) ? true : false;
	m_Writable = (writable == 1) ? true : false; 
	m_Compare = System::UnderlyingCastEnum<CompareMode>(compare);
}

#include STSTEM_WARNING_POP