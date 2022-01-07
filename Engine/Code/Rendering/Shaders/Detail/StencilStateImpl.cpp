// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 16:32)

#include "Rendering/RenderingExport.h"

#include "StencilStateImpl.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/EnumCast.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::StencilStateImpl
	::StencilStateImpl()
	:m_Enabled{ false },m_Compare{ StencilStateFlags::CompareMode::Never },m_Reference{ 0 },m_Mask{ 0xFFFFFFFF },
	 m_WriteMask{ 0xFFFFFFFF },m_OnFail{ StencilStateFlags::OperationType::Keep },m_OnZFail{ StencilStateFlags::OperationType::Keep },m_OnZPass{ StencilStateFlags::OperationType::Keep }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, StencilStateImpl)

void Rendering::StencilStateImpl ::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = source.ReadBool();
	source.ReadEnum(m_Compare);
	source.Read(m_Reference);
	source.Read(m_Mask);
	source.Read(m_WriteMask);
	source.ReadEnum(m_OnFail);
	source.ReadEnum(m_OnZFail);
	source.ReadEnum(m_OnZPass);
}

void Rendering::StencilStateImpl
	::Save(CoreTools::BufferTarget& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	target.Write(m_Enabled);
        target.WriteEnum(m_Compare);
	target.Write(m_Reference);
	target.Write(m_Mask);
	target.Write(m_WriteMask);
        target.WriteEnum(m_OnFail);
        target.WriteEnum(m_OnZFail);
        target.WriteEnum(m_OnZPass);
}

int Rendering::StencilStateImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Enabled);
 
	size += CORE_TOOLS_STREAM_SIZE(m_Compare);
	size += CORE_TOOLS_STREAM_SIZE(m_Reference);
	size += CORE_TOOLS_STREAM_SIZE(m_Mask);
	size += CORE_TOOLS_STREAM_SIZE(m_WriteMask);
	size += CORE_TOOLS_STREAM_SIZE(m_OnFail);
	size += CORE_TOOLS_STREAM_SIZE(m_OnZFail);
	size += CORE_TOOLS_STREAM_SIZE(m_OnZPass);

	return size;
}

bool Rendering::StencilStateImpl
	::IsEnabled() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Enabled;
}

void Rendering::StencilStateImpl
	::SetEnabled(bool enabled)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Enabled = enabled;
}

Rendering::StencilStateImpl::CompareMode Rendering::StencilStateImpl
	::GetCompare() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Compare;
}

void Rendering::StencilStateImpl
	::SetCompare(CompareMode compare)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Compare = compare;
}

unsigned int Rendering::StencilStateImpl
	::GetReference() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Reference;
}

void Rendering::StencilStateImpl
	::SetReference(unsigned int reference)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Reference = reference;
}

unsigned int Rendering::StencilStateImpl
	::GetMask() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_Mask;
}

void Rendering::StencilStateImpl
	::SetMask(unsigned int mask)
{
	RENDERING_CLASS_IS_VALID_9;

	m_Mask = mask;
}

unsigned int Rendering::StencilStateImpl
	::GetWriteMask() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_WriteMask;
}

void Rendering::StencilStateImpl
	::SetWriteMask(unsigned int writeMask)
{
	RENDERING_CLASS_IS_VALID_9;

	m_WriteMask = writeMask;
}

Rendering::StencilStateImpl::OperationType Rendering::StencilStateImpl
	::GetOnFail() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_OnFail;
}

void Rendering::StencilStateImpl
	::SetOnFail(OperationType onFail)
{
	RENDERING_CLASS_IS_VALID_9;

	m_OnFail = onFail;
}

Rendering::StencilStateImpl::OperationType Rendering::StencilStateImpl
	::GetOnZFail() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_OnZFail;
}

void Rendering::StencilStateImpl
	::SetOnZFail(OperationType onZFail)
{
	RENDERING_CLASS_IS_VALID_9;

	m_OnZFail = onZFail;
}

Rendering::StencilStateImpl::OperationType Rendering::StencilStateImpl
	::GetOnZPass() const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	return m_OnZPass;
}

void Rendering::StencilStateImpl
	::SetOnZPass(OperationType onZPass)
{
	RENDERING_CLASS_IS_VALID_9;

	m_OnZPass = onZPass;
}

void Rendering::StencilStateImpl
	::SaveState( WriteFileManager& manager ) const
{
	RENDERING_CLASS_IS_VALID_CONST_9;

	auto enabled = (m_Enabled ? 1 : 0);
	auto compare = System::EnumCastUnderlying(m_Compare);
	auto reference = m_Reference;
	auto mask = m_Mask;
	auto writeMask = m_WriteMask;
	auto onFail = System::EnumCastUnderlying(m_OnFail);
	auto onZFail = System::EnumCastUnderlying(m_OnZFail);
	auto onZPass = System::EnumCastUnderlying(m_OnZPass);

	manager.Write(sizeof(int), &enabled);
	manager.Write(sizeof(int), &compare);
	manager.Write(sizeof(unsigned int), &reference);
	manager.Write(sizeof(unsigned int), &mask);
	manager.Write(sizeof(unsigned int), &writeMask);
	manager.Write(sizeof(int), &onFail);
	manager.Write(sizeof(int), &onZFail);
	manager.Write(sizeof(int), &onZPass);
}

void Rendering::StencilStateImpl
	::LoadState(ReadFileManager& manager)
{
	RENDERING_CLASS_IS_VALID_9;
	
	int enabled{ 0 };
	int compare{ 0 };
	int onFail{ 0 };
	int onZFail{ 0 };
	int onZPass{ 0 };
	uint32_t reference{ 0 };
	uint32_t mask{ 0 };
	uint32_t writeMask{ 0 };
	manager.Read(sizeof(int), &enabled);
	manager.Read(sizeof(int), &compare);
	manager.Read(sizeof(uint32_t), &reference);
	manager.Read(sizeof(uint32_t), &mask);
	manager.Read(sizeof(uint32_t), &writeMask);
	manager.Read(sizeof(int), &onFail);
	manager.Read(sizeof(int), &onZFail);
	manager.Read(sizeof(int), &onZPass);

	m_Enabled = (enabled == 1) ? true : false;
	m_Compare = CompareMode(compare);
	m_Reference = reference;
	m_Mask = mask;
	m_WriteMask = writeMask;
	m_OnFail = OperationType(onFail);
	m_OnZFail = OperationType(onZFail);
	m_OnZPass = OperationType(onZPass);
}
#include STSTEM_WARNING_POP