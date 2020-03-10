// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:19)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
	// �����ṩ��ӵĻ��ڷ�����ֻд���Է���
	// �����ඨ����һ��set������ ����������һ����̬���������������������������ڵ�ƫ������
	// Ȼ��ʹ���������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������

	template<typename Reference, // ��������
			 typename Container, // �����
			 ptrdiff_t(*FO)(), // ָ�뺯���ṩ������ƫ������  
			 void(Container::*FS)(Reference)> // ָ�뵽һ����Ա��������R
	class MethodPropertySetExternal
	{
	public:
		using ReferenceType = Reference;
		using ContainerType = Container;
		using ClassType = MethodPropertySetExternal<ReferenceType, ContainerType, FO, FS>;

	public:
		CLASS_INVARIANT_DECLARE;

		// �ṩ�Ը����Ե�ֻд����
		ClassType& operator=(ReferenceType value);
	};
}

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H