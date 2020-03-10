// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H
#define CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Rtti
	{
	public:
		using ClassType = Rtti;

	public:
		// �����Ʊ�����ϵͳ�б����Ƕ��صġ���CoreTools�����ռ䣬��FooӦ��ʹ�á�CoreTools.Foo����
		// ���һ��Ӧ�ó�������һ�������ռ�SomeName��Ȼ�������ӦΪ��SomeName.Foo����
		Rtti(const char* name, const Rtti* baseType);

		CLASS_INVARIANT_DECLARE;

		const char* GetName() const noexcept;
		bool IsExactly(const Rtti& type) const noexcept;
		bool IsDerived(const Rtti& type) const noexcept;

	private:
		const char* m_Name;
		const Rtti* m_BaseType;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_RTTI_H
