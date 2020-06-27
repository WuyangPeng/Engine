// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:26)

#ifndef DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H
#define DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"

#include <iosfwd>

namespace Database
{
	class DATABASE_HIDDEN_DECLARE ResultRowImpl
	{
	public:
		using ClassType = ResultRowImpl;
		using ImplTypePtr = std::shared_ptr<ClassType>;

	public:
		explicit ResultRowImpl(const ConfigurationStrategy& configurationStrategy);
		virtual ~ResultRowImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void Print(std::ostream& os) const;

		virtual int GetIntValue(int pos) const;
		virtual uint32_t GetUIntValue(int pos) const;
		virtual int64_t GetInt64Value(int pos) const;
		virtual uint64_t GetUInt64Value(int pos) const;
		virtual float GetFloatValue(int pos) const;
		virtual double GetDoubleValue(int pos) const;
		virtual bool GetBoolValue(int pos) const;
		virtual std::string GetStringValue(int pos) const;
		virtual std::wstring GetWStringValue(int pos) const;
		virtual int GetColCount() const;

	public:
		ConfigurationStrategy m_ConfigurationStrategy;
	};
}

#endif // DATABASE_SQL_INTERFACE_RESULT_DOC_ROW_IMPL_H
