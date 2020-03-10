// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:01)

#ifndef CORE_TOOLS_HANDLE_MANAGER_RESOURCE_HANDLE_DETAIL_H
#define CORE_TOOLS_HANDLE_MANAGER_RESOURCE_HANDLE_DETAIL_H

#include "ResourceHandle.h"
#include "CoreTools/Base/UniqueIDManagerDetail.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Tag>
CoreTools::ResourceHandle<Tag>
	::ResourceHandle(uint32_t index)
	: m_Index{ index }, m_Magic{ GenerateMagic() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// static
template <typename Tag>
unsigned CoreTools::ResourceHandle<Tag>
	::GenerateMagic()
{
	auto autoMagic = UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::ResourceHandle);

	return autoMagic % sm_MaxMagic;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Tag>
bool CoreTools::ResourceHandle<Tag>
	::IsValid() const noexcept
{
	if (m_Index <= sm_MaxIndex && m_Magic <= sm_MaxMagic)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Tag>
uint32_t CoreTools::ResourceHandle<Tag>
	::GetIndex() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Index;
}

template <typename Tag>
uint32_t CoreTools::ResourceHandle<Tag>
	::GetMagic() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Magic;
}

template <typename Tag>
uint64_t CoreTools::ResourceHandle<Tag>
	::GetHandle() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return (static_cast<uint64_t>(m_Index) << sm_MaxBitsIndex) + static_cast<uint64_t>(m_Magic);
}

template <typename T>
bool CoreTools
	::operator ==(const ResourceHandle<T>& lhs, const ResourceHandle<T>& rhs) noexcept
{
	return lhs.GetHandle() == rhs.GetHandle();
}

template <typename T>
std::ostream& CoreTools
	::operator<<(std::ostream& os, const ResourceHandle<T>& resourceHandle)
{
	os << resourceHandle.GetHandle();

	return os;
}

#endif // CORE_TOOLS_HANDLE_MANAGER_RESOURCE_HANDLE_DETAIL_H

