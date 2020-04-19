#include "VariableExpression.h"
#include "../ExpressionContext.h"

namespace clc
{

	VariableExpression::VariableExpression(const std::string& varname)
		: m_Varname(varname)
	{
	}

	ExpressionPtr VariableExpression::Evaluate(const ExpressionContext& context) const
	{
		if (!context.HasVariable(m_Varname))
		{
			return CreateExpr<VariableExpression>(m_Varname);
		}
		return context.GetVariable(m_Varname)->Evaluate(context);
	}

	std::string VariableExpression::ToString(const ExpressionContext& context) const
	{
		if (!context.HasVariable(m_Varname))
		{
			return m_Varname;
		}
		return Evaluate(context)->ToString(context);
	}

	bool VariableExpression::HasNumericValue(const ExpressionContext& context) const
	{
		return false;
	}

	double VariableExpression::GetNumericValue(const ExpressionContext& context) const
	{
		return 0.0;
	}

}
