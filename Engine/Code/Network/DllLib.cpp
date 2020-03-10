// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/09 19:17)

// ����⣨Network����װ��������������á�
// �����λ������ĵ����㣬ֻ������������е�System��CoreTools�⣬��ʹ��boost��stlsoft��ACE���߿⡣

// ������������ģ�飺
// 1.	Helper��������
// 2.	Configuration����������ã�
// 3.	NetworkMessage��������Ϣ��
// 4.	Interface�������ӿڣ�
// 5.	ACEWrappers��ACE��װ����
// 6.	BoostWrappers��boost��װ����
// 7.	NetworkWrappers��Network��װ����
// 8.	SocketWrappers��socket��װ����
// 9.	Openssl��Openssl��

#include "Network/NetworkExport.h"

#include "Network/Network.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_NETWORK_STATIC

	#include "DllLib.h"

#else // BUILDING_NETWORK_STATIC

	namespace Network
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_NETWORK_STATIC