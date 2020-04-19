#include "DivideExpression.h"
#include "assert.h"
#include "ConstantExpression.h"

namespace clc
{

	DivideExpression::DivideExpression(const ExpressionPtr& left, const ExpressionPtr& right)
	{
		Expression::AddExpression(left);
		Expression::AddExpression(right);
	}

	ExpressionPtr DivideExpression::Evaluate(const ExpressionContext& context) const
	{
		ExpressionPtr left = GetExpression(0)->Evaluate(context);
		ExpressionPtr right = GetExpression(1)->Evaluate(context);
		CLC_ASSERT(left->HasNumericValue(context) && right->HasNumericValue(context), "Invalid divide expression");
		return CreateExpr<ConstantExpression>(left->GetNumericValue(context) / right->GetNumericValue(context));
	}

	std::string DivideExpression::ToString(const ExpressionContext& context) const
	{
		return "(" + GetExpression(0)->ToString(context) + " / " + GetExpression(1)->ToString(context) + ")";
	}

	bool DivideExpression::HasNumericValue(const ExpressionContext& context) const
	{
		return false;
	}

	double DivideExpression::GetNumericValue(const ExpressionContext& context) const
	{
		return 0.0;
	}

}
