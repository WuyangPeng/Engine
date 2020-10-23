// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 10:16)

#ifndef DATABASE_DATABASE_MACRO_USER_MACRO_H
#define DATABASE_DATABASE_MACRO_USER_MACRO_H

#include "System/Helper/ConfigMacro.h"
#include "CoreTools/Helper/UserMacro.h"

#define CLOSE_USE_MYSQL (0x01)
#define CLOSE_USE_MYSQL_C_API (0x01 << 1) 
#define CLOSE_USE_MYSQL_CPP_CONNECTOR (0x01 << 2) 
#define CLOSE_USE_SQL_SERVER (0x01 << 3) 
#define CLOSE_DATABASE_MAX (((CLOSE_USE_MYSQL_CPP_CONNECTOR) << 1) - 1)

// ������ԣ�Ĭ��Ϊ0�����ֵΪ0x03��
#define COMPILE_DATABASE_CLOSE 0x00

static_assert(0 <= COMPILE_DATABASE_CLOSE, "COMPILE_DATABASE_CLOSE Must be greater than or equal 0.");
static_assert(COMPILE_DATABASE_CLOSE <= CLOSE_DATABASE_MAX, "COMPILE_DATABASE_CLOSE Must be less than or equal CLOSE_DATABASE_MAX.");

 // �Ƿ����Ϊ��̬��
#ifdef BUILDING_STATIC
	#define  BUILDING_DATABASE_STATIC
#endif // BUILDING_STATIC

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL) != CLOSE_USE_MYSQL
	#define DATABASE_USE_MYSQL
#endif // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL) != CLOSE_USE_MYSQL  

#ifdef DATABASE_USE_MYSQL

	#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_C_API) != CLOSE_USE_MYSQL_C_API
		#define DATABASE_USE_MYSQL_C_API
	#endif // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_C_API) != CLOSE_USE_MYSQL_C_API  

	#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_CPP_CONNECTOR) != CLOSE_USE_MYSQL_CPP_CONNECTOR
		#define DATABASE_USE_MYSQL_CPP_CONNECTOR
	#endif // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_MYSQL_CPP_CONNECTOR) != CLOSE_USE_MYSQL_CPP_CONNECTOR  
 
#endif // DATABASE_USE_MYSQL

#if !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_SQL_SERVER) != CLOSE_USE_SQL_SERVER
	#define DATABASE_USE_SQL_SERVER
#endif // !defined(COMPILE_DATABASE_CLOSE) || (COMPILE_DATABASE_CLOSE & CLOSE_USE_SQL_SERVER) != CLOSE_USE_SQL_SERVER  
	
#endif // DATABASE_DATABASE_MACRO_USER_MACRO_H