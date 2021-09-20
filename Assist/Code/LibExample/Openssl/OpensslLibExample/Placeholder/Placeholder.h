// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.3 (2019/10/01 0:05)

#ifndef OPENSSL_LIB_EXAMPLE_PLACEHOLDER_H
#define OPENSSL_LIB_EXAMPLE_PLACEHOLDER_H

#include "LibExample/Openssl/OpensslLibExample/OpensslLibExampleDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace OpensslLibExample
{
	 class OPENSSL_LIB_EXAMPLE_DEFAULT_DECLARE Placeholder
	 {
	 public:
		 using ClassType = Placeholder;

	 public:
		 CLASS_INVARIANT_DECLARE;

	 public:
		 Placeholder();	 
	 };	
}

#endif // OPENSSL_LIB_EXAMPLE_PLACEHOLDER_H
