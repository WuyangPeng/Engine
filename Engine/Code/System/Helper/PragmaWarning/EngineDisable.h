// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/02/28 02:08)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_ENGINE_DISABLE_H
#define SYSTEM_HELPER_PRAGMA_WARNING_ENGINE_DISABLE_H 

// ���棺����<func>��ȱ��ע��<annotation>��
#if defined(TCRE_USE_MSVC)
	#pragma warning(disable : 26135) 
#endif // TCRE_USE_MSVC  

// ���棺����ʹ��gsl::at()����δѡ�е��±��������
#if defined(TCRE_USE_MSVC)
	#pragma warning(disable : 26446) 
#endif // TCRE_USE_MSVC  

#endif // SYSTEM_HELPER_PRAGMA_WARNING_ENGINE_DISABLE_H
