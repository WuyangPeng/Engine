// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 14:59)

#ifndef CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_EXCEPTION_MACRO_H

#include "CoreTools/Exception/Error.h"
#include "CoreTools/Exception/LastError.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/FunctionDescribedMacro.h"

#define THROW_EXCEPTION(error) \
		CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED),(error))

#define THROW_WINDOWS_EXCEPTION \
		CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED),System::String{}) 

#define THROW_LAST_ERROR_EXCEPTION(lastError,error) \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED),lastError,(error))

#define EXCEPTION_TRY try

#define EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType) \
		catch (CoreTools::Error& error) { LOG_SINGLETON_ENGINE_APPENDER(Error, filterType) \
        << error << LOG_SINGLETON_TRIGGER_ASSERT; } 

#define EXCEPTION_STD_EXCEPTION_CATCH(filterType) \
		catch (std::exception& error) {	LOG_SINGLETON_ENGINE_APPENDER(Error, filterType) \
        << error.what() << LOG_SINGLETON_TRIGGER_ASSERT; }

#define EXCEPTION_EXCEPTION_CATCH(filterType) \
		catch (...) { LOG_SINGLETON_ENGINE_APPENDER(Fatal, filterType) << SYSTEM_TEXT("Œ¥÷™¥ÌŒÛ°£") \
		<< LOG_SINGLETON_TRIGGER_ASSERT; }

#define EXCEPTION_ALL_CATCH(filterType) \
		EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType) \
        EXCEPTION_STD_EXCEPTION_CATCH(filterType) \
        EXCEPTION_EXCEPTION_CATCH(filterType)

#endif // CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
