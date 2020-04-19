#include "MultiplyExpression.h"
#include "assert.h"
#include "ConstantExpression.h"

namespace clc
{

	MultiplyExpression::MultiplyExpression(const ExpressionPtr& left, const ExpressionPtr& right)
	{
		Expression::AddExpression(left);
		Expression::AddExpression(right);
	}

	ExpressionPtr MultiplyExpression::Evaluate(const ExpressionContext& context) const
	{
		ExpressionPtr left = GetExpression(0)->Evaluate(context);
		ExpressionPtr right = GetExpression(1)->Evaluate(context);
		CLC_ASSERT(left->HasNumericValue(context) && right->HasNumericValue(context), "Invalid multiply expression");
		return CreateExpr<ConstantExpression>(left->GetNumericValue(context) * right->GetNumericValue(context));
	}

	std::string MultiplyExpression::ToString(const ExpressionContext& context) const
	{
		return "(" + GetExpression(0)->ToString(context) + " * " + GetExpression(1)->ToString(context) + ")";
	}

	bool MultiplyExpression::HasNumericValue(const ExpressionContext& context) const
	{
		return false;
	}

	double MultiplyExpression::GetNumericValue(const ExpressionContext& context) const
	{
		return 0.0;
	}

}
