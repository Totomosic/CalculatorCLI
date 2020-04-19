#include "ConstantExpression.h"

namespace clc
{

	ConstantExpression::ConstantExpression(double value)
		: m_Value(value)
	{
	}

	ExpressionPtr ConstantExpression::Evaluate(const ExpressionContext& context) const
	{
		return CreateExpr<ConstantExpression>(GetNumericValue(context));
	}

	std::string ConstantExpression::ToString(const ExpressionContext& context) const
	{
		return std::to_string(GetNumericValue(context));
	}

	bool ConstantExpression::HasNumericValue(const ExpressionContext& context) const
	{
		return true;
	}

	double ConstantExpression::GetNumericValue(const ExpressionContext& context) const
	{
		return m_Value;
	}

}
