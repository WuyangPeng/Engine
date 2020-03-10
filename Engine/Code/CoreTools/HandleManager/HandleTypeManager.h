// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 13:01)

#ifndef CORE_TOOLS_HANDLE_MANAGER_HANDLE_TYPE_MANAGER_H
#define CORE_TOOLS_HANDLE_MANAGER_HANDLE_TYPE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include <map>
#include <vector>
#include <string>

namespace CoreTools
{
	template <typename Data, typename ResourceHandle, typename ManagerTag = std::string>
	class HandleTypeManager
	{
	public:
		using ClassType = HandleTypeManager<Data, ResourceHandle, ManagerTag>;
		using DataType = Data;
		using DataTypePtr = std::shared_ptr<DataType>;
		using ResourceHandleType = ResourceHandle;
		using ResourceHandleTagType = typename ResourceHandle::TagType;
		using ManagerTagType = ManagerTag;

	public:
		HandleTypeManager();

		CLASS_INVARIANT_DECLARE;

		void Acquire(const ManagerTagType& handleTag);
		void Release(const ManagerTagType& handleTag);

		DataTypePtr Dereference(const ManagerTagType& handleTag);

		int GetUsedHandleCount() const;
		bool HasUsedHandles() const;

	private:
		using UserCollection = std::vector<DataTypePtr>;
		using MagicCollection = std::vector<uint32_t>;
		using FreeCollection = std::vector<uint32_t>;
		using NameIndex = std::map<ManagerTagType, ResourceHandleType>;

	private:
		void AcquireWithCreation(const ManagerTagType& handleTag);
		void AcquireWithRebuild(const ManagerTagType& handleTag);

	private:
		UserCollection m_UserData;
		MagicCollection m_MagicNumbers;
		FreeCollection m_FreeSlots;
		NameIndex m_NameIndex;
	};
}

#endif // CORE_TOOLS_HANDLE_MANAGER_HANDLE_TYPE_MANAGER_H