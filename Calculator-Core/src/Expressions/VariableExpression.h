#pragma once
#include "../Expression.h"

namespace clc
{

	class VariableExpression : public Expression
	{
	private:
		std::string m_Varname;

	public:
		VariableExpression(const std::string& varname);

		ExpressionPtr Evaluate(const ExpressionContext& context) const override;
		std::string ToString(const ExpressionContext& context) const override;
		bool HasNumericValue(const ExpressionContext& context) const override;
		double GetNumericValue(const ExpressionContext& context) const override;
	};

}