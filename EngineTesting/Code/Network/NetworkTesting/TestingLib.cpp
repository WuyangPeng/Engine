// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/11 18:55)

// ����ⵥԪ���԰�������ģ�飺
// 1.	Helper��������
// 2.	Interface�������ӿڣ�
// 3.	Configuration����������ã�
// 4.	ACEWrappers��ACE��װ����
// 5.	BoostWrappers��boost��װ����
// 6.	NetworkWrappers��Network��װ����
// 7.	SocketWrappers��socket��װ����
// 8.	NetworkMessage��������Ϣ��
// 9.	Openssl��Openssl��

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"
#include "Network/NetworkLib.h"

  #ifdef NETWORK_USE_ACE
    #ifdef _DEBUG
        #pragma comment(lib, "ACEd.lib")
    #else  // !_DEBUG
        #pragma comment(lib, "ACE.lib")
    #endif  // _DEBUG
#endif  // NETWORK_USE_ACE
