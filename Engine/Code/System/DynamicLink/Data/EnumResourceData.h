// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/09 13:32)

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
		// const DynamicLinkCharType*�����ʹ�ú�MAKEINTRESOURCEǿת��ָ�룬���ܽ����úʹ�ӡ��
		constexpr EnumResourceData(const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowWord language) noexcept
			:m_Type{ type }, m_Name{ name }, m_Language{ language }
		{
		}

		constexpr const DynamicLinkCharType* GetType() const noexcept
		{
			return m_Type;
		}

		constexpr const DynamicLinkCharType* GetName() const noexcept
		{
			return m_Name;
		}

		constexpr const LanguageIDData GetLanguage() const noexcept
		{
			return LanguageIDData{ UnderlyingCastEnum<PrimaryLanguage>(GetPrimaryLanguageID(m_Language)), UnderlyingCastEnum<SubLanguage>(GetSubLanguageID(m_Language)) };
		}

	private:
		const DynamicLinkCharType* m_Type;
		const DynamicLinkCharType* m_Name;
		WindowWord m_Language;
	};
}

#endif // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H