// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 14:43)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H 

#include "System/SystemDll.h"

#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/DynamicLink/Using/EnumResourceToolsUsing.h"

namespace System
{
	class SYSTEM_DEFAULT_DECLARE EnumResourceData
	{
	public:
		using ClassType = EnumResourceData;

	public:
		// const DynamicLinkCharType*存的是使用宏MAKEINTRESOURCE强转的指针，不能解引用和打印。
		EnumResourceData(const DynamicLinkCharType* type,const DynamicLinkCharType* name,WindowWord language) noexcept;

		const DynamicLinkCharType* GetType() const noexcept;
		const DynamicLinkCharType* GetName() const noexcept;
		const LanguageIDData GetLanguage() const noexcept;
		
	private:		
		const DynamicLinkCharType* m_Type;
		const DynamicLinkCharType* m_Name;
		WindowWord m_Language;
	};
}

#endif // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H