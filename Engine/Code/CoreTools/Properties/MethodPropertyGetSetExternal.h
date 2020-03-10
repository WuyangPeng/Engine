// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 16:18)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp> 

namespace CoreTools
{
	// �����ṩ��ӷ����Ķ�/д���Է���

	// �����ඨ��get��set������ ����������һ����̬���������а������������������ڵ�ƫ������
	// Ȼ��ʹ�������������ͣ���ȡ�������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������

	template<typename GetReference, typename SetReference, typename Container,
			 ptrdiff_t(*FO)(), GetReference(Container::*FG)() const, void (Container::*FS)(SetReference)>
	class MethodPropertyGetSetExternal
	{
	public:
		using GetReferenceType = GetReference;
		using SetReferenceType = SetReference;
		using ContainerType = Container;
		using ClassType = MethodPropertyGetSetExternal<GetReferenceType, SetReferenceType, ContainerType, FO, FG, FS>;

	public:
		CLASS_INVARIANT_DECLARE;

		// �ṩ�Ը����Ե�ֻ������
		operator GetReferenceType () const;

		// �ṩ�Ը����Ե�ֻд����
		ClassType& operator =(SetReferenceType value);
	};
}

#endif // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H