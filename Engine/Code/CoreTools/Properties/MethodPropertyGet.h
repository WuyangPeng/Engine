// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:17)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp> 

// ʹ�ú�TCRE_METHOD_PROPERTY_GET��������
namespace CoreTools
{
	template<typename Value, // ʵ������ֵ����
			 typename ConstReference, // ��������
			 typename Container, // �����	
			 ptrdiff_t(*FO)(), // ָ�뺯���ṩ������ƫ������ 
			 ConstReference(Container::*FG)() const > // ָ�򷵻�R��const��Ա������ָ��  			
	class MethodPropertyGet : private boost::noncopyable
	{
	public:
		using ValueType = Value;
		using ConstReferenceType = ConstReference;
		using ContainerType = Container;
		using ClassType = MethodPropertyGet<ValueType, ConstReferenceType, ContainerType, FO, FG>;

		CLASS_INVARIANT_DECLARE;

	private:
		MethodPropertyGet();
		explicit MethodPropertyGet(ConstReferenceType value);

		TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

	public:
		operator ConstReferenceType() const;

	private:
		ValueType m_Value;
	};
}

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H