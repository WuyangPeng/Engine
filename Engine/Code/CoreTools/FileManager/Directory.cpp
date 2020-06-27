// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.1.1.0 (2020/05/02 13:43)

#include "CoreTools/CoreToolsExport.h"

#include "Directory.h"
#include "Detail/DirectoryImpl.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

 

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Directory)
 




CoreTools::Directory
	::Directory(const System::String& directoryName)
	:m_Impl{std::make_shared<ImplType>(directoryName)}
{

}
