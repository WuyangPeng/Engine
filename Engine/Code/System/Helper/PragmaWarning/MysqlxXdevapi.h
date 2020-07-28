// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/08 19:27)

#ifndef SYSTEM_HELPER_PRAGMA_MYSQLX_XDEVAPI_H
#define SYSTEM_HELPER_PRAGMA_MYSQLX_XDEVAPI_H 

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

	#include "System/Helper/PragmaWarning.h"

	#include STSTEM_WARNING_PUSH

		#include SYSTEM_WARNING_DISABLE(4244) 
		#include SYSTEM_WARNING_DISABLE(4996) 
		#include SYSTEM_WARNING_DISABLE(26416) 
		#include SYSTEM_WARNING_DISABLE(26439) 
		#include SYSTEM_WARNING_DISABLE(26474) 
		#include SYSTEM_WARNING_DISABLE(26495)  

		#include <mysqlx/xdevapi.h>

	#include STSTEM_WARNING_POP

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif // SYSTEM_HELPER_PRAGMA_MYSQLX_XDEVAPI_H
