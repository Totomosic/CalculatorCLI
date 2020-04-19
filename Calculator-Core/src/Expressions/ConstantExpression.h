#pragma once
#include "../Expression.h"

namespace clc
{

	class ConstantExpression : public Expression
	{
	private:
		double m_Value;

	public:
		ConstantExpression(double value);

		ExpressionPtr Evaluate(const ExpressionContext& context) const override;
		std::string ToString(const ExpressionContext& context) const override;
		bool HasNumericValue(const ExpressionContext& context) const override;
		double GetNumericValue(const ExpressionContext& context) const override;
	};

}