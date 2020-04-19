#pragma once
#include "../Expression.h"

namespace clc
{

	class AddExpression : public Expression
	{
	public:
		AddExpression(const ExpressionPtr& left, const ExpressionPtr& right);

		ExpressionPtr Evaluate(const ExpressionContext& context) const override;
		std::string ToString(const ExpressionContext& context) const override;
		bool HasNumericValue(const ExpressionContext& context) const override;
		double GetNumericValue(const ExpressionContext& context) const override;
	};

}