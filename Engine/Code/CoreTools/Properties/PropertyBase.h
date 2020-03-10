// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:20)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h" 

namespace CoreTools
{
	// ��Ҫͨ����TCRE_DEFINE_PROPERTY����m_Offset
	template<typename ID, typename T>
	class PropertyBase
	{
	public:
		using ClassType = PropertyBase<ID, T>;

	public:
		virtual ~PropertyBase();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

	protected:
		T* Holder();
		const T* Holder() const;

	private:
		static const ptrdiff_t m_Offset;
	};
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_BASE_H