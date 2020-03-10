// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:20)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H

#include "CoreTools/CoreToolsDll.h"

// ʹ�÷�ʽ��
// �������1�ֽڶ���
// #pragma pack(push, 1)
// ��Ҫ����һ����������ľ�̬������
// static ptrdiff_t GetOffset()
// { enum { offset = offsetof(Class, Property) }; return offset; }

namespace CoreTools
{
	template<typename T, typename ConstReference, ConstReference(T::*PF)() const, ptrdiff_t(*FO)()>
	class PropertyGetExternalOffset
	{
	public:
		using ConstReferenceType = ConstReference;
		using ClassType = PropertyGetExternalOffset<T, ConstReferenceType, PF, FO>;

	public:
		CLASS_INVARIANT_DECLARE;

	public:
		operator ConstReferenceType () const;
	};
}

#endif // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_OFFSET_H