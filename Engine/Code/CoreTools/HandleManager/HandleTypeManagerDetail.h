// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 12:59)

#ifndef CORE_TOOLS_HANDLE_MANAGER_HANDLE_MANAGER_DETAIL_H
#define CORE_TOOLS_HANDLE_MANAGER_HANDLE_MANAGER_DETAIL_H

#include "HandleTypeManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Data, typename ResourceHandle, typename ManagerTag>
CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::HandleTypeManager()
	:m_UserData{}, m_MagicNumbers{}, m_FreeSlots{}, m_NameIndex{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Data, typename ResourceHandle, typename ManagerTag>
bool  CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::IsValid() const noexcept
{
	if (m_MagicNumbers.size() == m_UserData.size() && m_MagicNumbers.size() - m_FreeSlots.size() == m_NameIndex.size())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Data, typename ResourceHandle, typename ManagerTag>
void CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::Acquire(const ManagerTagType& handleTag)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (m_NameIndex.find(handleTag) != m_NameIndex.cend())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Acquire已存在的资源"));
	}

	if (m_FreeSlots.empty())
	{
		AcquireWithCreation(handleTag);
	}
	else
	{
		AcquireWithRebuild(handleTag);
	}
}

template <typename Data, typename ResourceHandle, typename ManagerTag>
void CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::AcquireWithCreation(const ManagerTagType& handleTag)
{
	ResourceHandleType resourceHandle{ boost::numeric_cast<uint32_t>(m_MagicNumbers.size()) };

	m_UserData.push_back(std::make_shared<Data>(handleTag));
	m_MagicNumbers.push_back(resourceHandle.GetMagic());
	m_NameIndex.insert({ handleTag, resourceHandle });
}

template <typename Data, typename ResourceHandle, typename ManagerTag>
void CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::AcquireWithRebuild(const ManagerTagType& handleTag)
{
	auto index = m_FreeSlots.back();
	ResourceHandleType resourceHandle{ index };
	m_FreeSlots.pop_back();

	m_UserData[index]->Reset(handleTag);
	m_MagicNumbers[index] = resourceHandle.GetMagic();
	m_NameIndex.insert({ handleTag, resourceHandle });
}

template <typename Data, typename ResourceHandle, typename ManagerTag>
void CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::Release(const ManagerTagType& handleTag)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto iter = m_NameIndex.find(handleTag);

	if (iter != m_NameIndex.cend())
	{
		auto index = iter->second.GetIndex();

		CORE_TOOLS_ASSERTION_0(index < m_UserData.size(), "索引数不正确！");
		CORE_TOOLS_ASSERTION_0(m_MagicNumbers[index] == iter->second.GetMagic(), "魔术数不对应！");

		m_MagicNumbers[index] = 0;
		m_FreeSlots.push_back(index);
		m_UserData[index]->Reset();
		m_NameIndex.erase(handleTag);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Release不存在的资源！"));
	}
}

template <typename Data, typename ResourceHandle, typename ManagerTag>
typename CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>::DataTypePtr CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::Dereference(const ManagerTagType& handleTag)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto iter = m_NameIndex.find(handleTag);

	if (iter != m_NameIndex.cend())
	{
		auto index = iter->second.GetIndex();

		CORE_TOOLS_ASSERTION_0(index < m_UserData.size() && m_MagicNumbers[index] == iter->second.GetMagic(), "魔术数不对应！");

		return m_UserData[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("提取不存在的资源！"));
	}
}

template <typename Data, typename ResourceHandle, typename ManagerTag>
int CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::GetUsedHandleCount() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_MagicNumbers.size() - m_FreeSlots.size());
}

template <typename Data, typename ResourceHandle, typename ManagerTag>
bool CoreTools::HandleTypeManager<Data, ResourceHandle, ManagerTag>
	::HasUsedHandles() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return GetUsedHandleCount() != 0;
}

#endif // CORE_TOOLS_HANDLE_MANAGER_HANDLE_MANAGER_DETAIL_H

