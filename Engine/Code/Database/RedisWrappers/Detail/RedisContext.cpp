///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:04)

#include "Database/DatabaseExport.h"

#include "RedisContext.h"
#include "RedisDatabaseFlush.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#ifdef DATABASE_USE_REDIS

Database::RedisContext::RedisContext(const ConfigurationStrategy& configurationStrategy)
    : redisContext{ ::redisConnect(configurationStrategy.GetIp().c_str(), configurationStrategy.GetPort()) }
{
    if (redisContext == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("redis connect 失败。"))
    }
    else if (redisContext->err)
    {
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26485)

        THROW_EXCEPTION(SYSTEM_TEXT("redis connect 失败。") + CoreTools::StringConversion::MultiByteConversionStandard(redisContext->errstr))

    #include STSTEM_WARNING_POP
    }

    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::RedisContext::~RedisContext() noexcept
{
    EXCEPTION_TRY
    {
        ::redisFree(redisContext);
    }
    EXCEPTION_ALL_CATCH(Database)

    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, RedisContext)

::redisContext* Database::RedisContext::GetRedisContext() noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    return redisContext;
}

#endif  // DATABASE_USE_REDIS
