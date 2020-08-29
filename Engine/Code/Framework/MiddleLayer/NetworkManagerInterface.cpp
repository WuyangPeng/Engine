// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 14:55)

#include "Framework/FrameworkExport.h"

#include "NetworkManagerInterface.h"
#include "Detail/NetworkManagerImpl.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "Flags/NetworkMiddleLayerFlags.h"
#include "Flags/MiddleLayerPlatformFlags.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/ClassInvariant/NoexceptDetail.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "Framework/MainFunctionHelper/Flags/Directory.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"
 
using std::move;
using std::make_shared;
using namespace std::literals;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Framework::NetworkManagerInterface
	::NetworkManagerInterface(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }, m_Impl{ make_shared<ImplType>(System::EnumCastUnderlying(NetworkMiddleLayer::Count)) }, 
	 m_NetworkManager{ make_shared<NetworkManagerImpl>() }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::NetworkManagerInterface
	::NetworkManagerInterface(NetworkManagerInterface&& rhs) noexcept
	:ParentType{ move(rhs) }, m_Impl{ move(rhs.m_Impl) }, m_NetworkManager{ move(rhs.m_NetworkManager) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}
 
Framework::NetworkManagerInterface& Framework::NetworkManagerInterface
	::operator=(NetworkManagerInterface&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(move(rhs));

	m_Impl = move(rhs.m_Impl);

	m_NetworkManager = move(rhs.m_NetworkManager);

	return *this;
} 

#ifdef OPEN_CLASS_INVARIANT
bool Framework::NetworkManagerInterface
	::IsValid() const noexcept
{	
	if (ParentType::IsValid() && m_Impl != nullptr && m_NetworkManager != nullptr)
		return true; 
	else 
		return false;
}
#endif // OPEN_CLASS_INVARIANT

bool Framework::NetworkManagerInterface
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate(environmentDirectory))
	{
		// 连接服务器和监听客户端。

		auto networkFileName = environmentDirectory.GetDirectory(UpperDirectory::Configuration) + SYSTEM_TEXT("Network.json");

		m_NetworkManager->ResetSendSocketManager(CoreTools::StringConversion::StandardConversionMultiByte(networkFileName));

		return true;
	}		
	else
	{
		return false;
	}		
}

bool Framework::NetworkManagerInterface
	::Initialize() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	if (ParentType::Initialize())
	{
		// 子类在这里注册消息。
		RegisteredMessages();

		return true;
	}		
	else
	{
		return false;
	}		
}

// private
void Framework::NetworkManagerInterface
	::RegisteredMessages()
{
	CoreTools::DoNothing();
}

bool Framework::NetworkManagerInterface
	::Destroy() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy())
	{		
		m_NetworkManager->Destroy();		

		return true;
	}		
	else
	{
		return false;
	}		
}

bool Framework::NetworkManagerInterface
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	if (ParentType::Idle(timeDelta))
	{
		// 发送和接收消息		
		m_NetworkManager->HandlingMessages();		

		return true;
	}		
	else
	{
		return false;
	}	
}

void Framework::NetworkManagerInterface
	::Send(SocketType socketType, int serverID, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_NetworkManager->Send(socketType,serverID,socketID,message);
}

void Framework::NetworkManagerInterface
	::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	
	m_NetworkManager->Insert(socketType, serverID, messageID, messageEvent);	
}

void Framework::NetworkManagerInterface
	::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_NetworkManager->Insert(socketType, serverID, messageID, messageEvent, priority);	
}

void Framework::NetworkManagerInterface
	::Remove(SocketType socketType, int serverID, int64_t messageID)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_NetworkManager->Remove(socketType, serverID, messageID);	
}

void Framework::NetworkManagerInterface
	::Remove(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	m_NetworkManager->Remove(socketType, serverID, messageID, messageEvent);
}

// protected
Framework::NetworkManagerInterface::SendSocketManagerSharedPtr Framework::NetworkManagerInterface
	::GetSendSocketManager() 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto sendSocketManager = m_NetworkManager->GetSendSocketManager();

	if (sendSocketManager != nullptr)
	{
		return sendSocketManager;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("网络管理器不存在！"s));
	}
}

// protected
Network::ConstSendSocketManagerSharedPtr Framework::NetworkManagerInterface
	::GetSendSocketManager() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	auto sendSocketManager = m_NetworkManager->GetSendSocketManager();

	if (sendSocketManager != nullptr)
	{
		return sendSocketManager;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("网络管理器不存在！"s));
	}
}

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, Input)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Network, ObjectLogic) 

bool Framework::NetworkManagerInterface
	::Paint()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Paint();
}

bool Framework::NetworkManagerInterface
	::Move(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Move(point);
}

bool Framework::NetworkManagerInterface
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Resize(windowDisplay,size);
}

bool Framework::NetworkManagerInterface
	::KeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyUp(key, point);
}

bool Framework::NetworkManagerInterface
	::KeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::KeyDown(key, point);
}

bool Framework::NetworkManagerInterface
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyUp(key, point);
}

bool Framework::NetworkManagerInterface
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::SpecialKeyDown(key, point);
}

bool Framework::NetworkManagerInterface
	::PassiveMotion(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::PassiveMotion(point);
}

bool Framework::NetworkManagerInterface
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::Motion(point, virtualKeys);
}

bool Framework::NetworkManagerInterface
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::NetworkManagerInterface
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return ParentType::MouseClick(button, state, point, virtualKeys);
}

#include STSTEM_WARNING_POP