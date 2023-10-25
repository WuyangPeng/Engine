///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	°æ±¾£º0.9.1.5 (2023/09/22 11:10)

#ifndef CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
#define CORE_TOOLS_HELPER_EXCEPTION_MACRO_H

#include "System/SystemOutput/MessageBoxSelection.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Exception/LastError.h"
#include "CoreTools/Helper/FunctionDescribedMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <stdexcept>

#define THROW_EXCEPTION(error)                                                  \
    {                                                                           \
        using namespace std::literals;                                          \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), (error)); \
    }

#define THROW_WINDOWS_EXCEPTION                                                          \
    {                                                                                    \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), System::String{}); \
    }

#define THROW_LAST_ERROR_EXCEPTION(lastError, error)                                       \
    {                                                                                      \
        using namespace std::literals;                                                     \
        CoreTools::Error::ThrowError((CORE_TOOLS_FUNCTION_DESCRIBED), lastError, (error)); \
    }

#define EXCEPTION_TRY try

#define EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType)                                                                \
    catch (const CoreTools::Error& error)                                                                           \
    {                                                                                                               \
        LOG_SINGLETON_ENGINE_APPENDER(Error, filterType, error, CoreTools::LogAppenderIOManageSign::TriggerAssert); \
    }

#define EXCEPTION_STD_EXCEPTION_CATCH(filterType)                                                                   \
    catch (const std::exception& error)                                                                             \
    {                                                                                                               \
        LOG_SINGLETON_ENGINE_APPENDER(Error, filterType, error, CoreTools::LogAppenderIOManageSign::TriggerAssert); \
    }

#define EXCEPTION_UNKNOWN_CATCH(filterType)                                                                                             \
    catch (...)                                                                                                                         \
    {                                                                                                                                   \
        LOG_SINGLETON_ENGINE_APPENDER(Fatal, filterType, SYSTEM_TEXT("Î´Öª´íÎó¡£"), CoreTools::LogAppenderIOManageSign::TriggerAssert); \
    }

#define EXCEPTION_ALL_CATCH(filterType)          \
    EXCEPTION_ENGINE_EXCEPTION_CATCH(filterType) \
    EXCEPTION_STD_EXCEPTION_CATCH(filterType)    \
    EXCEPTION_UNKNOWN_CATCH(filterType)

#define EXCEPTION_ENTRY_POINT_CATCH                    \
    catch (const CoreTools::Error& error)              \
    {                                                  \
        CERR << error.GetError() << SYSTEM_TEXT('\n'); \
    }                                                  \
    catch (const std::runtime_error& error)            \
    {                                                  \
        std::cerr << error.what() << '\n';             \
    }                                                  \
    catch (...)                                        \
    {                                                  \
        CERR << SYSTEM_TEXT("Î´Öª´íÎó\n");             \
    }

#define EXCEPTION_WINDOWS_ENTRY_POINT_CATCH                                                                                              \
    catch (const CoreTools::Error& error)                                                                                                \
    {                                                                                                                                    \
        MAYBE_UNUSED const auto dialogBoxCommand = System::MessageBoxSelectionWithTChar(error.GetError().c_str(), SYSTEM_TEXT("´íÎó"));  \
    }                                                                                                                                    \
    catch (const std::runtime_error& error)                                                                                              \
    {                                                                                                                                    \
        MAYBE_UNUSED const auto dialogBoxCommand = System::MessageBoxSelectionWithChar(error.what(), "´íÎó");                            \
    }                                                                                                                                    \
    catch (...)                                                                                                                          \
    {                                                                                                                                    \
        MAYBE_UNUSED const auto dialogBoxCommand = System::MessageBoxSelectionWithTChar(SYSTEM_TEXT("Î´Öª´íÎó£¡"), SYSTEM_TEXT("´íÎó")); \
    }

#endif  // CORE_TOOLS_HELPER_EXCEPTION_MACRO_H
