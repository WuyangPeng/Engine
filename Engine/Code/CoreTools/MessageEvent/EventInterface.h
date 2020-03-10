// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 17:02)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_INTERFACE_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_INTERFACE_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"

#include <memory> 

template class CORE_TOOLS_DEFAULT_DECLARE std::weak_ptr<CoreTools::EventInterface>;
template class CORE_TOOLS_DEFAULT_DECLARE std::enable_shared_from_this<CoreTools::EventInterface>;

namespace CoreTools
{
	// ���ֻ��Ҫһ���ص�����������̳�EventFunction��
	// �����Ҫ����ص������������ض���using CallbackMemberFunction = bool (ClassType::*)(const CallbackParameters& callbackParameters);
	// �ٶ���������EventFunction�ĺ�����
	class CORE_TOOLS_DEFAULT_DECLARE EventInterface : public std::enable_shared_from_this<EventInterface>
	{
	public:
		using ClassType = EventInterface;
		using CallbackMemberFunction = bool (ClassType::*)(const CallbackParameters& callbackParameters);

	public:
		EventInterface();
		virtual ~EventInterface();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool EventFunction(const CallbackParameters& callbackParameters) = 0;
	};

	using EventInterfaceSharedPtr = std::shared_ptr<EventInterface>;
	using ConsEventInterfaceSharedPtr = std::shared_ptr<const EventInterface>;
}

#endif // CORE_TOOLS_MESSAGE_EVENT_EVENT_INTERFACE_H
