#include "ExpressionContext.h"
#include "Expressions/ConstantExpression.h"
#include "assert.h"

namespace clc
{

	bool clc::ExpressionContext::HasVariable(const std::string& varname) const
	{
		return m_VariableMap.find(varname) != m_VariableMap.end();
	}

	ExpressionPtr clc::ExpressionContext::GetVariable(const std::string& varname) const
	{
		CLC_ASSERT(HasVariable(varname), "Missing varname " + varname);
		return m_VariableMap.at(varname);
	}

	void clc::ExpressionContext::CreateConstantVariable(const std::string& varname, double value)
	{
		m_VariableMap[varname] = CreateExpr<ConstantExpression>(value);
	}

}
