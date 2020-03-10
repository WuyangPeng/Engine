// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:18)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
	// �����ṩ�˻��ڷ�����ֻ�����Է���

	// �����ඨ����һ��get������ ����������һ����̬���������������������������ڵ�ƫ������
	// Ȼ��ʹ���������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������
	template<typename ConstReference, // ��������
			 typename Container, // �����
			 ptrdiff_t(*FO)(), // ָ�뺯���ṩ������ƫ������  
			 ConstReference(Container::*FG)() const> // ָ��ָ��һ��const��Ա��������CR  
	class MethodPropertyGetExternal
	{
	public:
		using ConstReferenceType = ConstReference;
		using ContainerType = Container;
		using ClassType = MethodPropertyGetExternal<ConstReferenceType, ContainerType, FO, FG>;

	public:
		CLASS_INVARIANT_DECLARE;

		// �ṩ�Ը����Ե�ֻ������
		operator ConstReferenceType () const;

		// ���ַ��������صģ��Է�ֹ��Ϥ�������û��ڰ��������ж�����ʵ��ʹ��operator=��
		// ��Ϊʹ��MethodPropertyGetSet<>�ᵼ������ѭ����
		ClassType& operator =(ConstReferenceType value) = delete;
	};
}

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H