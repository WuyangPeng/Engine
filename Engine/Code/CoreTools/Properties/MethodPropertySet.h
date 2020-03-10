// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:18)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp> 

// ʹ�ú�TCRE_METHOD_PROPERTY_SET��������
namespace CoreTools
{
	// �����ṩ���ڷ�����ֻд���Է��� 

	// contains�ඨ����һ��set������ ����������һ����̬���������������������������ڵ�ƫ������
	// Ȼ��ʹ��ֵ���ͣ��������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������
	template<typename Value, // ʵ������ֵ����
			 typename Reference, // ��������
			 typename Container,  // �����	
			 ptrdiff_t(*FO)(), // ָ�뺯���ṩ������ƫ������ 
			 void (Container::*FS)(Reference)> // ָ�򷵻�R�ĳ�Ա������ָ��  	
	class MethodPropertySet : private boost::noncopyable
	{
	public:
		using ValueType = Value;
		using ReferenceType = Reference;
		using ContainerType = Container;
		using ClassType = MethodPropertySet<ValueType, ReferenceType, ContainerType, FO, FS>;

		CLASS_INVARIANT_DECLARE;

	private:
		MethodPropertySet();
		explicit MethodPropertySet(ReferenceType value);

		TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

	public:
		ClassType& operator =(ReferenceType value);

	private:
		ValueType m_Value;
	};
}

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H